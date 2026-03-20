#include<iostream>
#include<vector>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Course {
    string subject;
public:
    Course(string s) : subject(s) {}
    string getSubject() const { return subject; }
};
class Student{
    public:
    int rollNo;
    string name;
    int age;
    string dept;
    int year;
    vector<int> marks;
};
class UGstudent : public Student{
    vector<Course> course;
    vector<Student> student;
    public:
    void newStudent(string name,string dept,int rollNo,int age,int yr){
        Student s1;
        s1.name=name;
        s1.dept=dept;
        s1.rollNo=rollNo;
        s1.age=age;
        s1.year=yr;
        student.push_back(s1);
    }
    void addCourse(string coursename){
        course.push_back(Course(coursename));
    }
    void studentDetail(int rollNo){
        for (auto &s : student){
            if (rollNo==s.rollNo)
            {
            cout << "Name: " << s.name<<endl;
            cout << "Roll No: " << s.rollNo<<endl;
            cout << "Age: " << s.age<<endl;
            cout << "Dept: " << s.dept<<endl;
            cout << "Year: " << s.year << endl;
            cout << "Courses: " << endl;
            for (auto &c : course) {
                cout << "  " << c.getSubject() << endl;
            }
            cout << "Marks: " << endl;
            for (int i = 0; i < s.marks.size(); i++) {
            cout << "  " << s.marks[i] << endl;
            }

          break;}
    else{
        cout<<"Incorrect Roll NUmber ..."<<endl;
    }
      }
    }
    void marks(int rollNO){
        int m;
        for (auto &s : student){
        if (rollNO==s.rollNo)
         {
            for(auto &c : course){
        cout<<"Enter Marks for course "<<c.getSubject()<<endl;
        cin>>m;
        s.marks.push_back(m);
            }
         return;
        }
       }
        cout<<"Incorrect Roll NUmber ..."<<endl;
    }
    void showCourses() {
    cout << "Courses:" << endl;
    for (int i = 0; i < course.size(); i++) {
        cout << i+1 << ") " << course[i].getSubject() << endl;
      }
    }
    void edit(int rollNo){
        int b;
        for(auto &s : student){
            if(rollNo==s.rollNo){
                do
                {
                cout<<"Choose what to edit :"<<endl;
                cout<<"1)Name:"<<endl;
                cout<<"2)Age"<<endl;
                cout<<"3)Department"<<endl;
                cout<<"4)Year"<<endl;
                cout<<"5)Courses"<<endl;
                cout<<"6)Finish Editing"<<endl;
                cin>>b;
                switch (b)
                {
                case 1:{
                    string nAME;
                    cout<<"Enter correct Name"<<endl;
                    cin.ignore();
                    getline(cin,nAME);
                    s.name=nAME;       
                break;
                }
                case 2:{
                    int f;
                    cout<<"Enter correct Age"<<endl;
                    cin>>f;
                    s.age=f;
                break;
                }
                case 3:{
                    string depaart;
                    cout<<"Enter correct Department"<<endl;
                    cin.ignore();
                    getline(cin,depaart);
                    s.dept=depaart;                    
                break;
                }
                case 4:{
                    int y;
                    cout<<"Enter correct Year of Admission"<<endl;
                    cin>>y;
                    s.year=y;
                break;
                }
                case 5:{
                    int l;
                    cout<<"Enter 1 to add courses"<<endl;
                    cout<<"Enter 2 to delete courses"<<endl;
                    cin>>l;
                    cin.ignore();
                    if(l==1){
                        string newCourse;
                        cout << "Enter new course name: ";
                        getline(cin, newCourse);
                        addCourse(newCourse);
                    }
                    else{
                        int idx;
                        showCourses();
                        cout<<"Enter index of the course to remove :"<<endl;
                        cin>>idx;
                        removeCourse(idx-1);
                    }
                break;
                }
                case 6:{
                cout<<"Editing Finished!!"<<endl;
                break;
                }
                default:
                cout<<"Invalid choice"<<endl;
                    break;
                }
                } while (b!=6);
                
            }
        }
    }
    void removeCourse(int index) {
    if (index >= 0 && index < course.size()){
        course.erase(course.begin() + index);
        cout << "Course removed successfully!" << endl;
    } else{
        cout << "Invalid course index!" << endl;
       }
   }
   void allStudents(int x){
    for (auto &s : student){
            cout<<"Name: "<<s.name<<endl;
            cout<<"Roll No: "<<s.rollNo<<endl;
            cout<<"Age: "<<s.age<<endl;
            cout<<"Dept: "<<s.dept<<endl;
            cout<<"Year: "<<s.year << endl;
            cout<<"Courses: "<<endl;
            for (auto &c : course) {
                cout<<"  "<<c.getSubject()<<endl;
            } 
            cout << "Marks: " << endl;
            for (int i = 0; i < s.marks.size(); i++) {
            cout << "  " << s.marks[i] << endl;
            }
        }
   }
   void compareStudents(int rollNo1, int rollNo2) {
    Student *st1 = nullptr, *st2 = nullptr;

    for (auto &s : student) {
        if (s.rollNo == rollNo1) st1 = &s;
        if (s.rollNo == rollNo2) st2 = &s;
    }

    if (!st1 || !st2) {
        cout << "One or both roll numbers are incorrect!" << endl;
        return;
    }

    Student &s1 = *st1;
    Student &s2 = *st2;

    cout << "Name: " << s1.name << " vs " << s2.name << endl;
    cout << "Roll No: " << s1.rollNo << " vs " << s2.rollNo << endl;
    cout << "Age: " << s1.age << " vs " << s2.age << endl;
    cout << "Dept: " << s1.dept << " vs " << s2.dept << endl;
    cout << "Year: " << s1.year << " vs " << s2.year << endl;

    cout << "Marks Comparison:" << endl;
    int maxCourses = max(s1.marks.size(), s2.marks.size());
    for (int i = 0; i < maxCourses; i++) {
        cout << "Course " << i+1 << ": ";
        if (i < s1.marks.size()) cout << s1.marks[i]; else cout << "-";
        cout << " vs ";
        if (i < s2.marks.size()) cout << s2.marks[i]; else cout << "-";
        cout << endl;
    }
} 
    void studentReport(string q){
        for(auto &s : student){
            {
                cout<<"Name :"<<s.name<<endl;
                cout<<"Courses :"<<endl;
                for(auto &c : course){
                    cout<<"  "<<c.getSubject()<<endl;
                }
            }
        }
    }
};
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    UGstudent s1;
    static string k;
    int choice, in;
    string name;
    string qt="abcd123";
    string dept;
    string xyz="teach123";
    string abc="teach456";
    int i=123;
    int o=789;
    do {
        cout<<"1) Teacher Login :"<<endl;
        cout<<"2) Student Login :"<<endl;
        cin >> in;
        switch (in) {
        case 1:
            cout<<"Teacher ID : xyz "<<endl;
            cout<<"Teacher ID : abc "<<endl;
            cout<<"Enter Password : "<<endl;
            cin>>k;
            break;
        case 2:
        cout<<"Enter password :"<<endl;
        cin>>qt;
            break;
        default:
            cout<<"INVALID"<<endl;
            break;
        }
    } while (in != 1 && in != 2);
       if(qt=="abcd123"){
        s1.studentReport(qt);
    }
    if (k == xyz || k == abc) {
        do {
            cout<<"1) Add New Student "<<endl;
            cout<<"2) View Student Report "<<endl;
            cout<<"3) Update Student Record "<<endl;
            cout<<"4) Compare Two Students "<<endl;
            cout<<"5) Show all student's details "<<endl;
            cout<<"6) Enter Marks "<< endl;
            cout <<"7) Exit "<<endl;
            cin>>choice;
            cin.ignore();

            switch (choice) {
            case 1: {
                int rollNo, age, yr, n;
                vector<string> course;
                cout<<"Enter student's name "<<endl;
                getline(cin, name);
                cout<<"Enter student's Department "<<endl;
                getline(cin, dept);
                cout<<"Enter student's Roll No"<<endl;
                cin>>rollNo;
                cout<<"Enter student's Age"<<endl;
                cin>>age;
                cout<<"Enter student's Year of Admission"<<endl;
                cin>>yr;
                cout<<"Enter the number of courses enrolled : "<<endl;
                cin>>n;
                cin.ignore();
                for (int i = 0; i < n; i++) {
                    string courseName;
                    cout<<"Course "<<i + 1<<":"<<endl;
                    getline(cin, courseName);
                    s1.addCourse(courseName);
                }
                s1.newStudent(name, dept, rollNo, age, yr);
                break;
            }
            case 2: {
                int x;
                cout<<"Enter the Roll Number of the student :"<<endl;
                cin>>x;
                s1.studentDetail(x);
                break;
            }
            case 3: {
                int a;
                cout<<"Enter Roll Number of student whose detail is to be edited :"<<endl;
                cin>>a;
                s1.edit(a);
                break;
            }
            case 4: {
                int f, g;
                cout<<"Enter the Roll Number of the first student :"<<endl;
                cin>>f;
                cout<<"Enter the roll Number of the second student :"<<endl;
                cin>>g;
                s1.compareStudents(f, g);
                break;
            }
            case 5: {
                int x = 1;
                s1.allStudents(x);
                break;
            }
            case 6: {
                int x;
                cout<<"Enter the Roll Number to feed marks"<<endl;
                cin>>x;
                s1.marks(x);
                break;
            }
            case 7: {
                cout<<"EXITING INTERFACE"<<endl;
                break;
            }
            default: {
                cout<<"Invalid choice !!"<<endl;
                break;
            }
            }
        } while (choice != 7);
    } else {
        cout<<"Wrong password !"<<endl;
    }
    return 0;
}