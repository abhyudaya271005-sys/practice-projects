#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;
void calculator(){
    float a,b,l,w,r,h,z;
    string x;
    int choose;
    cout<<"Advanced Calculator"<<endl<<"Please select your operation :";
    cout<<"[+]"<<setw(5)<<"[-]"<<setw(5)<<"[*]"<<setw(5)<<"[/]"<<endl<<"[s for squareroot]"<<endl<<"[aa for area of shapes]"<<endl<<"[f for factorial]";
    cin>>x;

    if (x=="s")
    {
        cout<<"Enter the number :";
    cin>>a;
        cout<<"The squareroot of "<<a<<" is "<<sqrt(a);
        return;
    }
    if (x=="aa")
    {
        cout<<"Choose the shape for area :"<<endl;
        
        do
        {
           cout<<"1) Area of Rectangle"<<endl;
           cout<<"2) Area of Circle"<<endl;
           cout<<"3) Area of Triangle"<<endl;
           cout<<"4) Area of Square"<<endl;
           cout<<"5) Area of Trapezium"<<endl;
           cout<<"6) Area of Kite"<<endl;
           cout<<"7) Area of Rhombus"<<endl;
           cout<<"Choose 0 to exit"<<endl;
           cin>>choose;
        switch (choose)
        {
        case 1 :
            cout<<"Enter the length and width "<<endl;
            cin>>l;
            cin>>w;
            cout<<"The area is "<<l*w<<endl;break;
        case 2 :
            cout<<"Enter the radius "<<endl;
            cin>>r;
            cout<<"The area is "<<3.14*r*r<<endl;break;
        case 3 :
            cout<<"Enter the height and base "<<endl;
            cin>>h;
            cin>>z;
            cout<<"The area is "<<0.5*h*z<<endl;break;
        case 4 :
            cout<<"Enter the length of side"<<endl;
            cin>>a;
            cout<<"The area is "<<a*a<<endl;break;
        case 5 :
            cout<<"Enter the lenght of sides and height"<<endl;
            cin>>a;
            cin>>b;
            cin>>h;
            cout<<"The area is "<<((a+b)*h)/2<<endl;break;
        case 6 :
            cout<<"Enter the length and height"<<endl;
            cin>>l;
            cin>>h;
            cout<<"The area is "<<(l*h)/2<<endl;break;
        case 7 :
            cout<<"Enter the length and height"<<endl;
            cin>>a;
            cin>>b;
            cout<<"The area is "<<(a*b)/2<<endl;break;
        case 0 :
             cout<<"Exiting area calc.";break;

        default: cout<<"INVALID OPERATOR"<<endl;
            break;
        }
    } while (choose!=0);
    }
    if (x=="f")
    {
        int num;
unsigned long long fact = 1;

cout << "Enter a non-negative integer: ";
cin >> num;

if (num < 0) {
    cout << "Factorial is not defined for negative numbers.";
    return;
}

for (int i = 1; i <= num; ++i) {
    fact *= i;
}

cout << "Factorial of " << num << " is " << fact;

    }
    if (x=="+")
    {
        cout<<"Enter the numbers "<<endl;
        cin>>a;
        cin>>b;
        cout<<"The sum is "<<a+b<<endl;
    }
    if (x=="-")
    {
        cout<<"Enter the numbers "<<endl;
        cin>>a;
        cin>>b;
        cout<<"The difference of the numbers is "<<a-b<<endl;
    }
    if (x=="*")
    {
        cout<<"Enter the numbers "<<endl;
        cin>>a;
        cin>>b;
        cout<<"The result is "<<a*b<<endl;
    }
    if (x=="/")
    {
        cout<<"Enter the numbers "<<endl;
        cin>>a;
        cin>>b;
        if (b!=0)
        {
            cout<<"The division is "<<a/b<<endl;
        }
        else
        {
            cout<<" DIVISION BY ZERO IS NOT POSSIBLE "<<endl;
        }
    }
}
int main() {
    calculator();
    return 0;
}
