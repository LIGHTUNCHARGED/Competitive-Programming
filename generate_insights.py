#!/usr/bin/env python3
"""
generate_insights.py
Generates AI Code Insights for Competitive Programming problems using Gemini API (gemini-3.5-flash-lite).
Saves structured outputs as insights.json in each problem's directory and updates database.json.
"""

import os
import sys
import json
import argparse
import time
from pathlib import Path
from google import genai
from google.genai import types

# Default model tag as requested by user
PRIMARY_MODEL = os.getenv("GEMINI_MODEL", "gemini-3.5-flash-lite")
FALLBACK_MODELS = ["gemini-2.5-flash", "gemini-1.5-flash", "gemini-2.0-flash"]

SYSTEM_PROMPT = """
You are a World-Class Competitive Programmer, Grandmaster, and Senior AI Systems Architect.
Your task is to provide an expert-level, highly rigorous code review and algorithmic insight breakdown for a competitive programming problem solution.

Given:
1. Problem Description (README.md)
2. Solution Source Code (solution.cpp / solution.py / solution.c)

Analyze the algorithm and output a JSON object adhering strictly to the provided response_schema.

Guidelines:
- Approach explanation must be clear, concise, and highlight core patterns (e.g. Dynamic Programming, Two Pointers, Greedy, Math, Bit Manipulation).
- Code breakdown must sequentially explain key steps and logic intuition.
- Complexity analysis must use standard LaTeX asymptotic notation (e.g., $O(N)$, $O(1)$, $O(N \\log N)$) with clear proofs based on problem constraints.
- Code quality review gives a clean code score (0-100), rates readability, edge-case safety, and lists actionable C++/Python best practices.
- Optimization section suggests concrete alternative algorithms, faster data structures, or lower memory overhead options.
"""

INSIGHTS_RESPONSE_SCHEMA = {
    "type": "OBJECT",
    "properties": {
        "title": {
            "type": "STRING",
            "description": "Algorithmic summary/title of the solution approach"
        },
        "algorithm_tags": {
            "type": "ARRAY",
            "items": {"type": "STRING"},
            "description": "Primary algorithms and techniques used (e.g. Prefix Sums, Greedy)"
        },
        "approach_explanation": {
            "type": "STRING",
            "description": "High-level conceptual explanation of why and how the approach works."
        },
        "code_breakdown": {
            "type": "ARRAY",
            "items": {
                "type": "OBJECT",
                "properties": {
                    "step": {"type": "INTEGER"},
                    "section_title": {"type": "STRING"},
                    "explanation": {"type": "STRING"}
                },
                "required": ["step", "section_title", "explanation"]
            },
            "description": "Sequential breakdown of code logic steps."
        },
        "complexity_analysis": {
            "type": "OBJECT",
            "properties": {
                "time_complexity": {"type": "STRING", "description": "LaTeX time complexity, e.g. $O(N)$"},
                "time_justification": {"type": "STRING", "description": "Mathematical proof based on loops and constraints."},
                "space_complexity": {"type": "STRING", "description": "LaTeX space complexity, e.g. $O(1)$"},
                "space_justification": {"type": "STRING", "description": "Justification based on memory allocation."}
            },
            "required": ["time_complexity", "time_justification", "space_complexity", "space_justification"]
        },
        "code_quality": {
            "type": "OBJECT",
            "properties": {
                "score": {"type": "INTEGER", "description": "Score from 0 to 100"},
                "rating_label": {"type": "STRING", "description": "Needs Improvement, Good, Great, or Optimal"},
                "strengths": {
                    "type": "ARRAY",
                    "items": {"type": "STRING"}
                },
                "edge_cases_handled": {
                    "type": "ARRAY",
                    "items": {"type": "STRING"}
                },
                "best_practices_feedback": {
                    "type": "ARRAY",
                    "items": {"type": "STRING"}
                }
            },
            "required": ["score", "rating_label", "strengths", "edge_cases_handled", "best_practices_feedback"]
        },
        "optimization_and_alternatives": {
            "type": "ARRAY",
            "items": {
                "type": "OBJECT",
                "properties": {
                    "approach_name": {"type": "STRING"},
                    "time_complexity": {"type": "STRING"},
                    "space_complexity": {"type": "STRING"},
                    "tradeoffs": {"type": "STRING"}
                },
                "required": ["approach_name", "time_complexity", "space_complexity", "tradeoffs"]
            },
            "description": "Alternative algorithmic strategies or optimizations."
        }
    },
    "required": [
        "title",
        "algorithm_tags",
        "approach_explanation",
        "code_breakdown",
        "complexity_analysis",
        "code_quality",
        "optimization_and_alternatives"
    ]
}

def get_gemini_client():
    api_key = os.getenv("GEMINI_API_KEY")
    if not api_key:
        print("ERROR: GEMINI_API_KEY environment variable is not set.", file=sys.stderr)
        sys.exit(1)
    return genai.Client(api_key=api_key)

def load_problem_files(problem_dir: Path):
    readme_path = problem_dir / "README.md"
    readme_content = readme_path.read_text(encoding="utf-8") if readme_path.exists() else "No problem description available."
    
    code_content = ""
    code_file = None
    for ext in ["solution.cpp", "solution.py", "solution.c"]:
        candidate = problem_dir / ext
        if candidate.exists():
            code_content = candidate.read_text(encoding="utf-8")
            code_file = ext
            break
            
    if not code_file:
        raise FileNotFoundError(f"No solution file found in {problem_dir}")
        
    return readme_content, code_content, code_file

def generate_insights_for_problem(client, problem_dir: Path, force: bool = False) -> bool:
    insights_path = problem_dir / "insights.json"
    if insights_path.exists() and not force:
        print(f"⏩ Skipping {problem_dir.name} (insights.json already exists).")
        return False

    print(f"🤖 Generating AI Insights for '{problem_dir.name}'...")
    try:
        readme_content, code_content, code_file = load_problem_files(problem_dir)
    except Exception as e:
        print(f"⚠️ Error reading files in {problem_dir}: {e}")
        return False
    
    prompt = f"""
    ### PROBLEM STATEMENT (README.md)
    {readme_content}

    ### SOLUTION CODE ({code_file})
    ```{code_file.split('.')[-1]}
    {code_content}
    ```
    """

    config = types.GenerateContentConfig(
        system_instruction=SYSTEM_PROMPT,
        temperature=0.2,
        response_mime_type="application/json",
        response_schema=INSIGHTS_RESPONSE_SCHEMA
    )

    models_to_try = [PRIMARY_MODEL] + [m for m in FALLBACK_MODELS if m != PRIMARY_MODEL]
    
    response = None
    used_model = None
    last_err = None

    for model in models_to_try:
        try:
            print(f"  Attempting request with model: {model}...")
            response = client.models.generate_content(
                model=model,
                contents=prompt,
                config=config
            )
            used_model = model
            break
        except Exception as e:
            print(f"  Warning: Model {model} failed: {e}")
            last_err = e

    if not response or not response.text:
        print(f"❌ Failed to generate insights for {problem_dir.name}. Error: {last_err}")
        return False

    try:
        insights_data = json.loads(response.text)
        insights_data["generated_at"] = int(time.time())
        insights_data["model"] = used_model

        with open(insights_path, "w", encoding="utf-8") as f:
            json.dump(insights_data, f, indent=2)
            
        print(f"✅ Saved insights to {insights_path}")
        return True

    except Exception as e:
        print(f"❌ Error parsing JSON response for {problem_dir.name}: {e}")
        return False

def update_database_json():
    db_path = Path("database.json")
    if not db_path.exists():
        return
        
    with open(db_path, "r", encoding="utf-8") as f:
        db = json.load(f)
        
    updated = 0
    for p in db.get("problems", []):
        p_path = Path(p["path"])
        has_insights = (p_path / "insights.json").exists()
        p["has_insights"] = has_insights
        if has_insights:
            updated += 1
            
    with open(db_path, "w", encoding="utf-8") as f:
        json.dump(db, f, indent=4)
    print(f"📊 Updated database.json ({updated}/{len(db.get('problems', []))} problems have insights).")

def main_batch(client, force=False):
    archive_dir = Path("Sorted_Problems")
    print(f"Starting batch AI Insights generation across {archive_dir}...")
    count = 0
    for rating_dir in archive_dir.glob("*"):
        if rating_dir.is_dir():
            for prob_dir in rating_dir.glob("*"):
                if prob_dir.is_dir():
                    if generate_insights_for_problem(client, prob_dir, force=force):
                        count += 1
    print(f"Batch generation completed. Total generated/updated: {count}")
    update_database_json()

def main():
    parser = argparse.ArgumentParser(description="Generate AI Code Insights for Competitive Programming archive.")
    parser.add_argument("--path", help="Specific problem folder path (e.g. Sorted_Problems/800/1788_A - One and Two)")
    parser.add_argument("--all", action="store_true", help="Process all problems in Sorted_Problems")
    parser.add_argument("--force", action="store_true", help="Overwrite existing insights.json files")
    args = parser.parse_args()

    client = get_gemini_client()
    archive_dir = Path("Sorted_Problems")

    if args.path:
        target_dir = Path(args.path)
        if not target_dir.exists():
            print(f"Error: Path '{args.path}' does not exist.", file=sys.stderr)
            sys.exit(1)
        generate_insights_for_problem(client, target_dir, force=args.force)
        update_database_json()
    elif args.all:
        main_batch(client, force=args.force)
    else:
        print("Usage: python generate_insights.py --path <folder_path> OR --all [--force]")
        sys.exit(1)

if __name__ == "__main__":
    main()
