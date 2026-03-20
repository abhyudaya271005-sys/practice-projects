#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <thread>
#include<chrono>
using namespace std;
void basicTimer();
void simpleCalculator();
void miniHabitTracker();
void dailyQuoteGenerator();

int main(){
    int choose;
    do
    {
        cout<<"MULTI UTILITY APP"<<endl<<endl;
        cout<<"Choose the program you would like to use "<<endl;
        cout<<" 1) Basic Timer "<<endl;
        cout<<" 2) Simple Calculator "<<endl;
        cout<<" 3) Mini Habit Tracker "<<endl;
        cout<<" 4) Daily Quote Generator "<<endl;
        cout<<" 5) EXIT "<<endl;
        cin>>choose;
     switch (choose){
        case 1 : basicTimer();break;
        case 2 : simpleCalculator();break;
        case 3 : miniHabitTracker();break;
        case 4 : dailyQuoteGenerator();break;
        case 5 : cout<<" Exiting interface ";break;
        default : cout<<" Invalid choice , Try again "<<endl; 
    }
} 
    while(choose!=5);

      return 0;
}
void simpleCalculator(){
    int a;
    int b;
    char x;
    cout<<" Type the desired number : "<<endl;
    cin>>a;
    cout<<" Choose the function ( + , - , / , * , % , s for sqrt )"<<endl;
    cin>>x;
    if(x=='s'){
        cout<<" The square root of "<<a<<" is "<<sqrt(a)<<endl;
        return ;
    }
    cout<<" Type the second number : "<<endl;
    cin>>b;
    switch (x)
    {
    case '+' :
            cout<<" The answer is "<<a+b;break;
    case '-' :
            cout<<" The answer is "<<a-b;break;
    case '*' :                
            cout<<" The answer is "<<a*b;break;
    case '/' :  
    if(b!=0){
            cout<<" The answer is "<<a/b;     
    }
    else{
        cout<<" Division not possible "<<endl;
        break;
    }
    case '%' :
            cout<<" The answer is "<<a*100/b<<endl;break;

    default: cout<<" Invalid operator "<<endl;
        break;
    }

}
void basicTimer(){
    int a;
    cout<<" Enter countdown in seconds : "<<endl;
    cin>>a;
    cout<<" Starting Timer in 3...2....1..."<<endl;
    for (int i = a; i > 0; --i)
    {
        cout<<" Time left : "<<i<<" seconds\r "<<flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    cout<<" TIME'S UP !!!"<<endl;
}
void miniHabitTracker(){
    vector<string> habits = {" Drink Water " , " Eat Food " , " Study"  , " Exercise "};
    vector<string> status ;
    string input;
    ofstream file("habits.txt", ios::app);

    time_t now = time(0);
    tm* ltm = localtime(&now);
    file << "Date: " << 1900 + ltm->tm_year << "/" 
         << 1 + ltm->tm_mon << "/" << ltm->tm_mday << endl;

    for (string habit : habits) {
        cout << "Did you complete \"" << habit << "\" today? (y/n): ";
        cin >> input;
        status.push_back((input == "y" || input == "Y") ? "Yes" : "No");
    }

    for (int i = 0; i < habits.size(); ++i) {
        file << habits[i] << ": " << status[i] << endl;
    }
    file << "-------------------------" << endl;
    file.close();

    cout << "Progress saved!" << endl;

}
void dailyQuoteGenerator(){
    vector<string> quotes = {
     " BHAG!!!",
     " I'm selfish, impatient and a little insecure. I make mistakes, I am out of control and at times hard to handle. But if you can't handle me at my worst, then you sure as hell don't deserve me at my best. ",
     " So many books, so little time. ",
     " Two things are infinite: the universe and human stupidity; and I'm not sure about the universe. ",
     " A room without books is like a body without a soul. ",
     " Be the change that you wish to see in the world. ",
     " You only live once, but if you do it right, once is enough. ",
     " In three words I can sum up everything I've learned about life: it goes on. ",
     " If you tell the truth, you don't have to remember anything. ",
     " A friend is someone who knows all about you and still loves you. ",
     " To live is the rarest thing in the world. Most people exist, that is all. ",
};
srand(time(0));
    int index = rand() % quotes.size();

    cout << "\nQuote of the Day:\n" << quotes[index] << endl;
}
