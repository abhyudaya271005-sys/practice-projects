#include<iostream>
#include<vector>
#include<string>
#include <cstdlib>
#include <ctime> 
using namespace std;
class Balance{
    protected:
    int bal;
    public:
    Balance() {  //ye rha hamara custom constructor[unparameterized]
        srand(time(0));            
        bal = (rand() % 9000) + 1000; 
    }
    int getBal(){
        return bal;
    }
    void setBal(int newBal) { bal = newBal; }
};
class Withdraw : public Balance{
    public :
    int withdraw;
     int z; 
    public:
    Withdraw(int x,int balanze){
        //ye rha hamara parameterized constructor
        if (x>balanze)
        {
            cout<<" Insufficient Balance "<<endl;
           z=balanze;
        }
        else {
            z=balanze-x;
            cout<<"Withdraw Done!!"<<endl;
        }    
    }
    int withMoney(){
        return z;
    }
};
class User : public Balance{
    public :
    string name;
    int mobNo;
    int accNo;
    public :
    User(int accNo,int mobNo,string name){
        this->name=name;
        this->accNo=accNo;
        this->mobNo=mobNo;
    }        
    void userDetails(){
        cout<<"Name : "<<name<<endl;
        cout<<"Account Number : "<<accNo<<endl;
        cout<<"Mobile Number : "<<mobNo<<endl;
        cout<<"Balance : "<<bal<<endl;
    }
};
class MobNo : public User{
    public :
    int newMob;
    MobNo(int newMob) : User(0, mobNo, "TempUser"){
        mobNo=newMob;
    }
    void newMO(){
        cout<<"Your number "<<newMob<<" has been updates to "<<mobNo<<endl;
    }
};
int main() {
    int choice;
    Balance b1;              
    User u1(0, 0, "");

    do {
        cout << "\nChoose function :" << endl;
        cout << "  1) Check Balance " << endl;
        cout << "  2) Withdraw Cash " << endl;
        cout << "  3) User Details " << endl;
        cout << "  4) Update Mobile.No " << endl;
        cout << "  5) Exit " << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Your balance is: " << b1.getBal() << endl;
            break; 

        case 2: {
            int amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            Withdraw w1(amount, b1.getBal());
            b1.setBal(w1.withMoney());
            cout << "Your remaining balance is: " << w1.withMoney() << endl;
            break;
        }

        case 3: {
            int acc, mob;
            string name;
            cout << "Enter account number, mobile number and name: ";
            cin >> acc >> mob >> name;
            u1 = User(acc, mob, name);  
            u1.userDetails();
            break;
        }

        case 4: {
            int a;
            cout<<"Enter new mobile number :"<<endl;
            cin>>a;
            MobNo m1(a);
            m1.newMO();
            break;
        }

        case 5:
            cout << "Exiting Interface" << endl;
            break;

        default: 
            cout << "Invalid Option" << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}