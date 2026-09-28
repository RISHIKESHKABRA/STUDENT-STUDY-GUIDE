# System Verification & Performance Results

All modules were compiled and tested under MinGW GCC 4.9.2 (Dev-C++ default) and GCC 11.2.

| Test ID | Module | Input Vector / Event | Expected Behavior | Result |
| :--- | :--- | :--- | :--- | :--- |
| **TC01** | Navigation | Enter `1` at main menu | Route to Notes Generator | **PASS** |
| **TC02** | Notes Export | Title: `CS101`, Bullet: `Pointers` | Write `CS101_notes.txt` | **PASS** |
| **TC03** | Quiz Scoring | 2/2 answers correct | Compute & display `100%` | **PASS** |
| **TC04** | Checklist | Toggle task index `1` | State flips `[ ]` $\rightarrow$ `[X]` | **PASS** |
| **TC05** | Input Safety | Enter letters in choice menu | Clear error state, restart loop | **PASS** |
