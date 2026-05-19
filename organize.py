import os
import shutil
import requests

def main():
    print("Fetching problem ratings from Codeforces API...")
    # API request to get JSON containing all Codeforces problems.
    try:
        response = requests.get("https://codeforces.com/api/problemset.problems", timeout=10).json()
        if response['status'] != 'OK':
            print("Failed to fetch Codeforces API.")
            return
    except Exception as e:
        print(f"API Request failed: {e}")
        return

    ratings = {}
    for p in response['result']['problems']:
        key = f"{p['contestId']}{p['index']}"
        ratings[key] = p.get('rating', 'Unrated')

    # Create a dedicated archive folder so the script doesn't eat its own output
    archive_dir = "Sorted_Problems"
    os.makedirs(archive_dir, exist_ok=True)

    for item in os.listdir('.'):

        if os.path.isdir(item) and item.isdigit():
            contest_id = item
            
            for problem_folder in os.listdir(contest_id):
                old_path = os.path.join(contest_id, problem_folder)
                
                if os.path.isdir(old_path):
                    index = problem_folder.split("-")[0].strip()
                    problem_key = f"{contest_id}{index}"
                    
                    rating = ratings.get(problem_key, 'Unrated')
                    
                    # Place the rating folders safely INSIDE the archive folder
                    rating_dir = os.path.join(archive_dir, str(rating))
                    os.makedirs(rating_dir, exist_ok=True)
                    
                    new_folder_name = f"{contest_id}_{problem_folder}"
                    new_path = os.path.join(rating_dir, new_folder_name)
                    
                    shutil.move(old_path, new_path)
                    print(f"Moved: {old_path} -> {new_path}")
            
            if not os.listdir(contest_id):
                os.rmdir(contest_id)

    print("Reorganization complete!")

if __name__ == "__main__":
    main()
