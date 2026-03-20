#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n--- Student Record Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            cout << "Enter roll number: ";
            cin >> s.roll;
            cout << "Enter name: ";
            cin.ignore(); // flush leftover newline
            getline(cin, s.name);
            cout << "Enter marks: ";
            cin >> s.marks;
            students.push_back(s);
        } else if (choice == 2) {
            cout << "\n--- Student List ---\n";
            for (const auto& s : students) {
                cout << "Roll: " << s.roll << ", Name: " << s.name << ", Marks: " << s.marks << "\n";
            }
        }
    } while (choice != 3);

    return 0;
}