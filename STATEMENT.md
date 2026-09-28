```markdown
# Problem Statement & Software Requirements

## Objective
Students frequently switch between disjointed tools for summarizing study materials, creating practice revision tests, and managing daily study schedules. The objective of this project is to build a zero-dependency, unified C++ console tool accessible across lightweight IDE environments like Dev-C++.

## Technical Requirements
1. **Compatibility:** C++11 compliant, runnable without external GUI or external third-party dependencies.
2. **Buffer Safety:** Clean menu loops using state resets (`cin.clear()` and `cin.ignore()`) to handle malformed input.
3. **Data Structures:** Custom structs (`Question`) and STL sequence containers (`std::vector<T>`).
4. **File Output:** Standard output file stream persistent storage (`std::ofstream`).
