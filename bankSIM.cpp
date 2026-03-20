#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class account {
public:
    string name;
    double deposit, pin;
    int id;
};

class bank {
private:
    vector<account> accounts;
public:
    void createAccount(string name, double deposit, double pin) {
        account a1;
        a1.pin = pin;
        a1.deposit = deposit;
        a1.id = rand() % 100;
        a1.name = name;
        accounts.push_back(a1);

        cout << "User's name : " << name << endl;
        cout << "Deposit : " << deposit << endl;
        cout << "User ID : " << a1.id << endl;
    }

    void viewAccountByPin(double pin) {
        bool found = false;
        for (auto &acc : accounts) {
            if (acc.pin == pin) {
                cout<<"Name: " << acc.name;
                cout<<" | Deposit: " << acc.deposit;
                cout<<" | ID: " << acc.id << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Invalid PIN!" << endl;
        }
    }
    void depositMoney(double pin,int amount){
        bool found = false;
        for (auto &acc : accounts)
        {
           if(acc.pin == pin){
            acc.deposit+=amount;
            cout<<"The new amount is : "<<acc.deposit<<endl;
            found=true;break;
           }
        }
        if(!found)
        cout<<"Invalid PIN"<<endl;
    }
    void withdrawMoney(double pin,int amount){
        bool found=false;
        for (auto &acc : accounts)
        {
            if(acc.pin==pin){
                if(acc.deposit<amount){
                    cout<<"Insufficient Balance"<<endl;
                }
                else{
                acc.deposit-=amount;
                cout<<"The remaining balance is : "<<acc.deposit<<endl;
                found=true;break;
                }
            }
        }
        if(!found)
        cout<<"Invalid PIN "<<endl;
    }
};

int main() {
    int options;
    bank b1;

    cout << "Welcome to Bank Services :" << endl;

    do {
        cout << "\n1. Create account "
             << "\n2. View account "
             << "\n3. Deposit "
             << "\n4. Withdraw "
             << "\n5. Exit "
             << "\nEnter your choice: ";
        cin >> options;

        switch (options) {
        case 1: {
            string name;
            double deposit, pin;
            cout << "Enter name of owner: ";
            cin >> name;
            cout << "Enter deposit amount: ";
            cin >> deposit;
            cout << "Create PIN : ";
            cin >> pin;
            if (deposit <= 0)
                cout << "Invalid deposit value!" << endl;
            else
                b1.createAccount(name, deposit, pin);
            break;
        }
        case 2: {
            double pin;
            cout << "Enter your PIN: ";
            cin >> pin;
            b1.viewAccountByPin(pin);
            break;
        }
        case 3:{
            double pin;int amount;
            cout << "Enter your PIN: ";
            cin >> pin;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            b1.depositMoney(pin,amount);
        }
        case 4:{
            double pin;int amount;
            cout << "Enter your PIN: ";
            cin >> pin;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            b1.withdrawMoney(pin,amount);
        }
        case 5:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid Option" << endl;
            break;
        }
    } while (options != 5);

    return 0;
}