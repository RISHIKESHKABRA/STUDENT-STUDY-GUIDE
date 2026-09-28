#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

// Structure for Quiz Questions
struct Question {
    string questionText;
    string options[4];
    int correctOption; // 1 to 4
};

// Function declarations
void showMenu();
void shortNotesGenerator();
void examQuizGenerator();
void dailyChecklistMaker();

int main() {
    int choice;
    do {
        showMenu();
        cout << "Enter your choice (1-4): ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        
        cin.ignore(); // Clear newline character from buffer
        cout << "\n----------------------------------------\n";
        
        switch (choice) {
            case 1:
                shortNotesGenerator();
                break;
            case 2:
                examQuizGenerator();
                break;
            case 3:
                dailyChecklistMaker();
                break;
            case 4:
                cout << "Exiting application. Best of luck with your studies!\n";
                break;
            default:
                cout << "Invalid selection! Please try again.\n";
        }
        cout << "----------------------------------------\n\n";
    } while (choice != 4);

    return 0;
}

void showMenu() {
    cout << "========================================\n";
    cout << "      STUDY & PRODUCTIVITY SUITE        \n";
    cout << "========================================\n";
    cout << "1. Short Notes Generator\n";
    cout << "2. Exam Quiz Generator & Practice\n";
    cout << "3. Daily Checklist Maker\n";
    cout << "4. Exit\n";
    cout << "========================================\n";
}

void shortNotesGenerator() {
    cout << "=== SHORT NOTES GENERATOR ===\n";
    string topic, bullet;
    vector<string> points;
    
    cout << "Enter Topic Title: ";
    getline(cin, topic);
    
    cout << "Enter key bullet points (type 'DONE' on a new line when finished):\n";
    while (true) {
        cout << "- ";
        getline(cin, bullet);
        if (bullet == "DONE" || bullet == "done") break;
        if (!bullet.empty()) {
            points.push_back(bullet);
        }
    }
    
    if (points.empty()) {
        cout << "No notes entered. Returning to menu.\n";
        return;
    }
    
    cout << "\n========================================\n";
    cout << "         SUMMARY NOTES: " << topic << "\n";
    cout << "========================================\n";
    for (size_t i = 0; i < points.size(); ++i) {
        cout << " [•] " << points[i] << "\n";
    }
    cout << "========================================\n";
    
    char saveChoice;
    cout << "Do you want to save these notes to a file? (y/n): ";
    cin >> saveChoice;
    if (saveChoice == 'y' || saveChoice == 'Y') {
        string filename = topic + "_notes.txt";
        ofstream outFile(filename.c_str());
        if (outFile.is_open()) {
            outFile << "SUMMARY NOTES: " << topic << "\n";
            outFile << "----------------------------------------\n";
            for (size_t i = 0; i < points.size(); ++i) {
                outFile << " [•] " << points[i] << "\n";
            }
            outFile.close();
            cout << "Notes successfully saved to '" << filename << "'!\n";
        } else {
            cout << "Error creating file.\n";
        }
    }
}

void examQuizGenerator() {
    cout << "=== EXAM QUIZ GENERATOR ===\n";
    int numQuestions;
    cout << "How many questions would you like to create for this quiz? ";
    cin >> numQuestions;
    cin.ignore();
    
    if (numQuestions <= 0) {
        cout << "Invalid number of questions.\n";
        return;
    }
    
    vector<Question> quiz(numQuestions);
    
    for (int i = 0; i < numQuestions; ++i) {
        cout << "\n--- Question " << (i + 1) << " ---\n";
        cout << "Enter the question text: ";
        getline(cin, quiz[i].questionText);
        
        for (int j = 0; j < 4; ++j) {
            cout << "  Option " << (j + 1) << ": ";
            getline(cin, quiz[i].options[j]);
        }
        
        cout << "Enter correct option number (1-4): ";
        cin >> quiz[i].correctOption;
        cin.ignore();
    }
    
    cout << "\n========================================\n";
    cout << "        STARTING YOUR PRACTICE QUIZ     \n";
    cout << "========================================\n";
    
    int score = 0;
    for (int i = 0; i < numQuestions; ++i) {
        cout << "\nQ" << (i + 1) << ": " << quiz[i].questionText << "\n";
        for (int j = 0; j < 4; ++j) {
            cout << "  " << (j + 1) << ". " << quiz[i].options[j] << "\n";
        }
        
        int userAns;
        cout << "Your Answer (1-4): ";
        cin >> userAns;
        
        if (userAns == quiz[i].correctOption) {
            cout << ">> Correct!\n";
            score++;
        } else {
            cout << ">> Incorrect! Correct answer was Option " << quiz[i].correctOption << ".\n";
        }
    }
    
    cout << "\n========================================\n";
    cout << "QUIZ COMPLETED!\n";
    cout << "Your Score: " << score << " / " << numQuestions;
    cout << " (" << (score * 100 / numQuestions) << "%)\n";
    cout << "========================================\n";
}

void dailyChecklistMaker() {
    cout << "=== DAILY CHECKLIST MAKER ===\n";
    vector<string> tasks;
    vector<bool> status;
    string task;
    
    cout << "Enter daily tasks (type 'DONE' when finished adding):\n";
    while (true) {
        cout << "Task " << (tasks.size() + 1) << ": ";
        getline(cin, task);
        if (task == "DONE" || task == "done") break;
        if (!task.empty()) {
            tasks.push_back(task);
            status.push_back(false);
        }
    }
    
    if (tasks.empty()) {
        cout << "No tasks added.\n";
        return;
    }
    
    int choice;
    do {
        cout << "\n========================================\n";
        cout << "             DAILY CHECKLIST            \n";
        cout << "========================================\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << " [" << (status[i] ? "X" : " ") << "] " << (i + 1) << ". " << tasks[i] << "\n";
        }
        cout << "----------------------------------------\n";
        cout << "1. Mark task as completed/pending\n";
        cout << "2. Exit Checklist\n";
        cout << "Choice: ";
        cin >> choice;
        
        if (choice == 1) {
            int taskNum;
            cout << "Enter task number to toggle status: ";
            cin >> taskNum;
            if (taskNum >= 1 && taskNum <= (int)tasks.size()) {
                status[taskNum - 1] = !status[taskNum - 1];
            } else {
                cout << "Invalid task number!\n";
            }
        }
    } while (choice != 2);
}
