<h2 align="center">📚 Codeforces Solutions Organizer</h2>
</p>

An automated, serverless pipeline that tracks my progression in competitive programming. This repository serves as a personal library of highly optimized C++ algorithms, categorized by problem complexity and mathematical concepts.
## 🎯 Engineering Purpose
While the primary goal is to push toward the Expert tier on Codeforces, this repository also demonstrates applied system design. Instead of manual uploads, I engineered a zero-cost, event-driven pipeline to handle data ingestion, categorization, and frontend deployment automatically. 

It is designed to be a frictionless environment where I can focus entirely on **quantitative problem-solving** and **time/space complexity optimization**.

## 🏗️ System Architecture
The repository operates on a hands-off, three-stage pipeline:

1. **Ingestion (Client-Side):** A browser extension (CFPusher) acts as the trigger, bypassing enterprise web-scraping protections to capture my source code immediately upon an `Accepted` verdict.
2. **Processing (CI/CD):** A custom Python Janitor bot runs via **GitHub Actions**. It queries the Codeforces REST API, fetches problem metadata, reorganizes the file tree by difficulty rating, and regenerates a static `database.json` index.
3. **Presentation (Static Frontend):** **GitHub Pages** detects the state change and instantly deploys an updated vanilla JavaScript dashboard, dynamically rendering problem descriptions and syntax-highlighted code blocks.
