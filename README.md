# STUDENT-STUDY-GUIDE

# Integrated C++ Study & Productivity Suite

A lightweight, terminal-based academic management application written in C++11. Designed specifically for full compatibility with **Dev-C++**, MinGW, GCC, and MSVC.

## Features
- **Short Notes Generator:** Capture bullet points and export structured summary notes to persistent plain text files.
- **Exam Quiz Generator:** Build multiple-choice practice tests, take the test interactively, and view instant score percentages.
- **Daily Checklist Maker:** Interactive task list manager with boolean state toggling (`[ ]` / `[X]`).

## Quick Start (Dev-C++)
1. Clone or download this repository.
2. Open `src/main.cpp` in Dev-C++.
3. Ensure C++11 is enabled under `Tools > Compiler Options > Settings > Code Generation > Language Standard (-std)`.
4. Press `F11` to compile and run.

## Build via Command Line
```bash
g++ -std=c++11 src/main.cpp -o study_suite
./study_suite
