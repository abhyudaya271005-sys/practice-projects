#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Course {
    string subject;
public:
    Course(string s = "") : subject(s) {}
    string getSubject() const { return subject; }
};

class Student {
public:
    int rollNo;
    string name;
    int age;
    string dept;
    int year;
    vector<Course> courses;
    vector<int> marks;

    int totalMarks() const {
        int sum = 0;
        for (int m : marks) sum += m;
        return sum;
    }
};

class UGstudent {
    vector<Student> students;

public:
    void addStudent(string name, string dept, int rollNo, int age, int yr, vector<string> courseNames) {
        Student s;
        s.name = name;
        s.dept = dept;
        s.rollNo = rollNo;
        s.age = age;
        s.year = yr;

        for (auto &c : courseNames)
            s.courses.push_back(Course(c));

        students.push_back(s);
        cout << "Student added successfully!\n";
    }

    Student* findStudent(int rollNo) {
        for (auto &s : students) {
            if (s.rollNo == rollNo)
                return &s;
        }
        return nullptr;
    }

    void studentDetail(int rollNo) {
        Student* s = findStudent(rollNo);
        if (!s) {
            cout << "Incorrect Roll Number...\n";
            return;
        }

        cout << "Name: " << s->name << endl;
        cout << "Roll No: " << s->rollNo << endl;
        cout << "Age: " << s->age << endl;
        cout << "Dept: " << s->dept << endl;
        cout << "Year: " << s->year << endl;

        cout << "Courses:\n";
        for (auto &c : s->courses)
            cout << "  " << c.getSubject() << endl;

        cout << "Marks:\n";
        for (int m : s->marks)
            cout << "  " << m << endl;

        cout << "Total Marks: " << s->totalMarks() << endl;
    }

    void enterMarks(int rollNo) {
        Student* s = findStudent(rollNo);
        if (!s) {
            cout << "Incorrect Roll Number...\n";
            return;
        }

        s->marks.clear(); // clear old marks
        for (auto &c : s->courses) {
            int m;
            cout << "Enter marks for " << c.getSubject() << ": ";
            cin >> m;
            s->marks.push_back(m);
        }
        cout << "Marks updated successfully!\n";
    }

    void editStudent(int rollNo) {
        Student* s = findStudent(rollNo);
        if (!s) {
            cout << "Incorrect Roll Number...\n";
            return;
        }

        int ch;
        do {
            cout << "\n1) Name\n2) Age\n3) Department\n4) Year\n5) Finish\nChoice: ";
            cin >> ch;
            cin.ignore();

            if (ch == 1) {
                cout << "Enter new name: ";
                getline(cin, s->name);
            } else if (ch == 2) {
                cout << "Enter new age: ";
                cin >> s->age;
            } else if (ch == 3) {
                cout << "Enter new department: ";
                getline(cin, s->dept);
            } else if (ch == 4) {
                cout << "Enter new year: ";
                cin >> s->year;
            }
        } while (ch != 5);

        cout << "Editing finished!\n";
    }

    void allStudents() {
        for (auto &s : students) {
            cout << "----------------------\n";
            studentDetail(s.rollNo);
        }
    }

    void compareStudents(int r1, int r2) {
        Student* s1 = findStudent(r1);
        Student* s2 = findStudent(r2);

        if (!s1 || !s2) {
            cout << "One or both roll numbers not found.\n";
            return;
        }

        int t1 = s1->totalMarks();
        int t2 = s2->totalMarks();

        cout << s1->name << " total = " << t1 << endl;
        cout << s2->name << " total = " << t2 << endl;

        if (t1 > t2)
            cout << s1->name << " has higher marks.\n";
        else if (t1 < t2)
            cout << s2->name << " has higher marks.\n";
        else
            cout << "Both have equal marks.\n";
    }
};

int main() {
    UGstudent sys;
    int choice;

    string teacherPass;
    cout << "Enter teacher password (teach123 or teach456): ";
    cin >> teacherPass;

    if (teacherPass != "teach123" && teacherPass != "teach456") {
        cout << "Wrong password!\n";
        return 0;
    }

    do {
        cout << "\n1) Add Student\n2) View Student\n3) Edit Student\n4) Compare Students\n5) Show All\n6) Enter Marks\n7) Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name, dept;
            int roll, age, year, n;

            cout << "Name: ";
            getline(cin, name);
            cout << "Department: ";
            getline(cin, dept);
            cout << "Roll No: ";
            cin >> roll;
            cout << "Age: ";
            cin >> age;
            cout << "Year: ";
            cin >> year;

            cout << "Number of courses: ";
            cin >> n;
            cin.ignore();

            vector<string> courses;
            for (int i = 0; i < n; i++) {
                string c;
                cout << "Course " << i + 1 << ": ";
                getline(cin, c);
                courses.push_back(c);
            }

            sys.addStudent(name, dept, roll, age, year, courses);
        }
        else if (choice == 2) {
            int r;
            cout << "Enter roll no: ";
            cin >> r;
            sys.studentDetail(r);
        }
        else if (choice == 3) {
            int r;
            cout << "Enter roll no: ";
            cin >> r;
            sys.editStudent(r);
        }
        else if (choice == 4) {
            int a, b;
            cout << "Enter first roll no: ";
            cin >> a;
            cout << "Enter second roll no: ";
            cin >> b;
            sys.compareStudents(a, b);
        }
        else if (choice == 5) {
            sys.allStudents();
        }
        else if (choice == 6) {
            int r;
            cout << "Enter roll no: ";
            cin >> r;
            sys.enterMarks(r);
        }

    } while (choice != 7);

    cout << "Exiting...\n";
    return 0;
}
