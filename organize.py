import os
import shutil
import requests
import json


def fetch_ratings():
    print("Fetching problem ratings from Codeforces API...")
    try:
        response = requests.get("https://codeforces.com/api/problemset.problems", timeout=10).json()
        if response['status'] != 'OK':
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


def organize_files(ratings, archive_dir):
    print("Organizing new submissions...")
    for item in os.listdir('.'):
        # Only process digit folders (Contest IDs) in the root directory.
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


def generate_database(archive_dir):
    print("Generating database.json...")
    database = {
        "stats": {
            "total": 0,
            "by_rating": {}
        },
        "problems": []
    }

    if not os.path.exists(archive_dir):
        print("Archive directory not found. Skipping database generation.")
        return

    # Walk through the Sorted_Problems directory
    for rating_str in os.listdir(archive_dir):
        rating_path = os.path.join(archive_dir, rating_str)
        if not os.path.isdir(rating_path):
            continue

        database["stats"]["by_rating"][rating_str] = 0

        for problem_folder in os.listdir(rating_path):
            problem_path = os.path.join(rating_path, problem_folder)
            if not os.path.isdir(problem_path):
                continue

            # Extract details from folder name (e.g., "1876_A - Helmets in Night Light")
            parts = problem_folder.split("_", 1)
            contest_id = parts[0]
            rest = parts[1] if len(parts) > 1 else problem_folder

            name_parts = rest.split("-", 1)
            index = name_parts[0].strip()
            name = name_parts[1].strip() if len(name_parts) > 1 else rest

            # Update stats
            database["stats"]["total"] += 1
            database["stats"]["by_rating"][rating_str] += 1

            # Add to problem list
            database["problems"].append({
                "contestId": contest_id,
                "index": index,
                "name": name,
                "rating": rating_str,
                "path": f"{archive_dir}/{rating_str}/{problem_folder}"
            })

    # Sort problems by contest ID (newest first)
    database["problems"].sort(key=lambda x: int(x["contestId"]) if x["contestId"].isdigit() else 0, reverse=True)

    # Save the JSON file
    with open("database.json", "w", encoding="utf-8") as f:
        json.dump(database, f, indent=4)

    print(f"Database generated successfully! ({database['stats']['total']} total problems)")


def main():
    archive_dir = "Sorted_Problems"
    os.makedirs(archive_dir, exist_ok=True)

    ratings = fetch_ratings()
    if ratings:
        organize_files(ratings, archive_dir)

    # Always generate the database, even if no new files were moved
    generate_database(archive_dir)


if __name__ == "__main__":
    main()