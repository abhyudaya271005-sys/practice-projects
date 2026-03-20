#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void calculator();
void numberGuessingGame();
void pointerDemo();
void multiplicationTable();
int main(){
    int choice;
    do{
    cout<<"Multiple Function App"<<endl;
    cout<<"1) Calculator "<<endl;
    cout<<"2) Guess the number Game"<<endl;
    cout<<"3) Pointer Demo"<<endl;
    cout<<"4) Multiplication Table"<<endl;
    cout<<"5) Exit"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1 : calculator();break;
    case 2 : numberGuessingGame();break;
    case 3 : pointerDemo();break;
    case 4 : multiplicationTable();break;
    case 5 : cout<<"Exiting Interface";break;
    
    default: cout << "Invalid choice. Try again.\n";
    }
   } while (choice!=5);
    
    return 0;
}
void calculator() {
    double a, b;
    char op;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter the operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> b;

    switch (op) {
        case '+':
            cout << "Result is : " << a + b << endl;
            break;
        case '-':
            cout << "Result is : " << a - b << endl;
            break;
        case '*':
            cout << "Result is : " << a * b << endl;
            break;
        case '/':
            if (b != 0) {
                cout << "Result is : " << a / b << endl;
            } else {
                cout << "Cannot divide by zero" << endl;
            }
            break;
        default:
            cout << "Invalid operator" << endl;
    }
}

void numberGuessingGame() {
    srand(time(0));
    int number = rand() % 100 + 1;
    int guess;

    do {
        cout << "Enter your guess (1-100): ";
        cin >> guess;

        if (guess < number) {
            cout << " You guessed a little low, guess higher."<<endl<<endl;
        } else if (guess > number) {
            cout << " You guessed a little high, guess lower."<<endl<<endl;
        } else {
            cout << " Congrats!!!! You guessed right."<<endl<<endl;
        }
    } while (guess != number);
}
void pointerDemo(){
    int num = 69;
    int* a = &num;
    cout<<" The address of num is "<<&num<<endl;
    cout<<" The value of num is "<<*a<<endl;
}
void multiplicationTable(){
    int a ;
    cout<<"Enter a number"<<endl;
    cin>>a;
    for (int i = 0; i <=50; i++)
    {
      cout<<a<<" X "<<i<<" = "<<a*i<<endl;
    }
    
}