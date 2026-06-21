#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Student {
    string id;
    string name;
    int score;
};

template <class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

template <class T>
T getMin(T a, T b) {
    return (a < b) ? a : b;
}

void printMenu() {
    cout << "\n=== Student Grade Management System ===\n";
    cout << "1. Add student\n";
    cout << "2. List all students\n";
    cout << "3. Sort by score\n";
    cout << "4. Search by id\n";
    cout << "5. Show statistics\n";
    cout << "0. Exit\n";
    cout << "Please select an option: ";
}

int main() {
    vector<Student> students;
    int choice = -1;

    while (choice != 0) {
        printMenu();
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            Student newStudent;
            cout << "Enter student ID: ";
            cin >> newStudent.id;

            auto it = find_if(students.begin(), students.end(),
                      [&](const Student& s) {
                          return s.id == newStudent.id;
                      });
            
            if (it != students.end()) {
                cout << "Student ID already exists. Updating information...\n";

                cout << "Enter new Name: ";
                cin.ignore();
                getline(cin, it->name);

                cout << "Enter new Score: ";
                cin >> it->score;

                cout << "Student updated successfully.\n";
            }else{
                cout << "Enter student Name: ";
                cin.ignore();
                getline(cin, newStudent.name);

                do {
                    cout << "Enter student Score (0~100): ";
                    cin >> newStudent.score;

                    if (newStudent.score < 0 || newStudent.score > 100)
                        cout << "Invalid score! Please enter a score between 0 and 100.\n";

                } while (newStudent.score < 0 || newStudent.score > 100);

                students.push_back(newStudent);
                cout << "Student added successfully.\n";
            }

        } else if (choice == 2) {
            if (students.empty()) {
                cout << "No students found.\n";
            } else {
                cout << "\n--- Student List ---\n";
                cout << left << setw(15) << "ID" << setw(20) << "Name" << "Score\n";
                cout << string(45, '-') << "\n";
                for (const auto& s : students) {
                    cout << left << setw(15) << s.id << setw(20) << s.name << s.score << "\n";
                }
            }

        } else if (choice == 3) {
            if (students.empty()) {
                cout << "No students to sort.\n";
            } else {
                sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                    return a.score > b.score;
                });
                cout << "Students sorted by score (descending).\n";
            }

        } else if (choice == 4) {
            string searchId;
            cout << "Enter student ID to search: ";
            cin >> searchId;

            auto it = find_if(students.begin(), students.end(), 
                              [&](const Student& s) { return s.id == searchId; });
            
            if (it != students.end()) {
                cout << "\nStudent Found:\n";
                cout << "ID: " << it->id << ", Name: " << it->name << ", Score: " << it->score << "\n";
            } else {
                cout << "Student ID not found.\n";
            }

        } else if (choice == 5) {
            if (students.empty()) {
                cout << "No statistics available. The list is empty.\n";
            } else {
                int totalScore = 0;
                int maxScore = students[0].score;
                int minScore = students[0].score;
                int passCount = 0;
                int failCount = 0;

                for (const auto& s : students) {
                    totalScore += s.score;
                    maxScore = getMax<int>(maxScore, s.score);
                    minScore = getMin<int>(minScore, s.score);
                    
                    if (s.score >= 60) {
                        passCount++;
                    } else {
                        failCount++;
                    }
                }

                double average = static_cast<double>(totalScore) / students.size();

                cout << "\n--- Grade Statistics ---\n";
                cout << "Class Average: " << fixed << setprecision(2) << average << "\n";
                cout << "Highest Score: " << maxScore << "\n";
                cout << "Lowest Score:  " << minScore << "\n";
                cout << "Pass Count:    " << passCount << "\n";
                cout << "Fail Count:    " << failCount << "\n";
            }

        } else if (choice == 0) {
            cout << "Exiting the program. Goodbye!\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}