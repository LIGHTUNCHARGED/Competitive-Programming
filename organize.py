import os
import shutil
import requests


def main():
    print("Fetching problem ratings from Codeforces API...")
    try:
        response = requests.get("https://codeforces.com/api/problemset.problems", timeout=10).json()
        if response['status'] != 'OK':
            print("Failed to fetch Codeforces API.")
            return
    except Exception as e:
        print(f"API Request failed: {e}")
        return

    # Map problem IDs (e.g., "1876A") to their ratings
    ratings = {}
    for p in response['result']['problems']:
        key = f"{p['contestId']}{p['index']}"
        ratings[key] = p.get('rating', 'Unrated')

    # Look for folders that are just numbers (Contest IDs like '1876', '1900')
    for item in os.listdir('.'):
        if os.path.isdir(item) and item.isdigit():
            contest_id = item

            for problem_folder in os.listdir(contest_id):
                old_path = os.path.join(contest_id, problem_folder)

                if os.path.isdir(old_path):
                    # Extract the index (e.g., "A" from "A - Helmets in Night Light")
                    index = problem_folder.split("-")[0].strip()
                    problem_key = f"{contest_id}{index}"

                    # Get the rating, default to Unrated if not found
                    rating = ratings.get(problem_key, 'Unrated')
                    rating_dir = str(rating)

                    # Create the new rating folder (e.g., "1400")
                    os.makedirs(rating_dir, exist_ok=True)

                    # Create the new path (e.g., "1400/1876_A - Helmets in Night Light")
                    new_folder_name = f"{contest_id}_{problem_folder}"
                    new_path = os.path.join(rating_dir, new_folder_name)

                    shutil.move(old_path, new_path)
                    print(f"Moved: {old_path} -> {new_path}")

            # Clean up the empty contest folder
            if not os.listdir(contest_id):
                os.rmdir(contest_id)

    print("Reorganization complete!")


if __name__ == "__main__":
    main()