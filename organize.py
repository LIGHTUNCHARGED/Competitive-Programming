import os
import shutil
import requests
import json


HANDLE = "LIGHTUNCHARGED"

def fetch_ratings():
    print("Fetching problem ratings from Codeforces API...")
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"
    }
    try:
        res = requests.get("https://codeforces.com/api/problemset.problems", headers=headers, timeout=10)
        if res.status_code != 200:
            print(f"Failed to fetch ratings. HTTP Status: {res.status_code}")
            return {}
        response = res.json()
        if response.get('status') != 'OK':
            print("Failed to fetch Codeforces API.")
            return {}
        
        ratings = {}
        for p in response['result']['problems']:
            key = f"{p['contestId']}{p['index']}"
            ratings[key] = p.get('rating', 'Unrated')
        return ratings
    except Exception as e:
        print(f"API Request failed: {e}")
        return {}

def fetch_solve_dates():
    print(f"Fetching solve dates for {HANDLE}...")
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"
    }
    try:
        res = requests.get(f"https://codeforces.com/api/user.status?handle={HANDLE}", headers=headers, timeout=10)
        if res.status_code != 200:
            print(f"Failed to fetch solve dates. HTTP Status: {res.status_code}. Response: {res.text[:200]}")
            return {}
        response = res.json()
        if response.get('status') != 'OK':
            print(f"Failed to fetch solve dates: API status {response.get('status')}")
            return {}
        
        dates = {}
        for sub in response['result']:
            # Only care about Accepted verdicts
            if sub.get('verdict') == 'OK' and 'contestId' in sub['problem']:
                key = f"{sub['problem']['contestId']}{sub['problem']['index']}"
                # Save the timestamp of the earliest accepted submission
                if key not in dates:
                    dates[key] = sub['creationTimeSeconds']
                else:
                    dates[key] = min(dates[key], sub['creationTimeSeconds'])
        return dates
    except Exception as e:
        print(f"API Request failed for dates: {e}")
        return {}

def organize_files(ratings, archive_dir):
    print("Organizing new submissions...")
    for item in os.listdir('.'):
        if os.path.isdir(item) and item.isdigit():
            contest_id = item
            for problem_folder in os.listdir(contest_id):
                old_path = os.path.join(contest_id, problem_folder)
                if os.path.isdir(old_path):
                    index = problem_folder.split("-")[0].strip()
                    problem_key = f"{contest_id}{index}"
                    
                    rating = ratings.get(problem_key, 'Unrated')
                    rating_dir = os.path.join(archive_dir, str(rating))
                    os.makedirs(rating_dir, exist_ok=True)
                    
                    new_folder_name = f"{contest_id}_{problem_folder}"
                    new_path = os.path.join(rating_dir, new_folder_name)
                    
                    shutil.move(old_path, new_path)
                    print(f"Moved: {old_path} -> {new_path}")
            
            if not os.listdir(contest_id):
                os.rmdir(contest_id)

def generate_database(archive_dir, solve_dates):
    print("Generating database.json...")
    database = {
        "stats": {
            "total": 0,
            "by_rating": {}
        },
        "problems": []
    }
    
    if not os.path.exists(archive_dir):
        return

    for rating_str in os.listdir(archive_dir):
        rating_path = os.path.join(archive_dir, rating_str)
        if not os.path.isdir(rating_path):
            continue
            
        database["stats"]["by_rating"][rating_str] = 0
        
        for problem_folder in os.listdir(rating_path):
            problem_path = os.path.join(rating_path, problem_folder)
            if not os.path.isdir(problem_path):
                continue
                
            parts = problem_folder.split("_", 1)
            contest_id = parts[0]
            rest = parts[1] if len(parts) > 1 else problem_folder
            
            name_parts = rest.split("-", 1)
            index = name_parts[0].strip()
            name = name_parts[1].strip() if len(name_parts) > 1 else rest
            
            # Match folder to Codeforces timestamp
            problem_key = f"{contest_id}{index}"
            timestamp = solve_dates.get(problem_key, 0)
            
            database["stats"]["total"] += 1
            database["stats"]["by_rating"][rating_str] += 1
            
            database["problems"].append({
                "contestId": contest_id,
                "index": index,
                "name": name,
                "rating": rating_str,
                "timestamp": timestamp, # <-- The new date data
                "path": f"{archive_dir}/{rating_str}/{problem_folder}"
            })
            
    # Default sorting: Newest problems first
    database["problems"].sort(key=lambda x: x["timestamp"], reverse=True)
    
    with open("database.json", "w", encoding="utf-8") as f:
        json.dump(database, f, indent=4)
        
    print("Database generated successfully!")

def load_existing_timestamps():
    print("Loading existing timestamps from database.json...")
    if not os.path.exists("database.json"):
        return {}
    try:
        with open("database.json", "r", encoding="utf-8") as f:
            data = json.load(f)
            timestamps = {}
            for p in data.get("problems", []):
                key = f"{p.get('contestId')}{p.get('index')}"
                if p.get("timestamp"):
                    timestamps[key] = p["timestamp"]
            return timestamps
    except Exception as e:
        print(f"Failed to load existing database: {e}")
        return {}

def main():
    archive_dir = "Sorted_Problems"
    os.makedirs(archive_dir, exist_ok=True)
    
    existing_timestamps = load_existing_timestamps()
    
    ratings = fetch_ratings()
    solve_dates = fetch_solve_dates()
    
    # Merge fetched solve dates with existing timestamps as fallback
    merged_dates = {**existing_timestamps, **solve_dates}
    
    if ratings:
        organize_files(ratings, archive_dir)
        
    generate_database(archive_dir, merged_dates)

if __name__ == "__main__":
    main()
