#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#include<fstream>
using namespace std;

class Products {
public:
    int productID;
    int quantity;
    double price;
    string name;
};

void addStock(int id,string name,int qnty,double price,map<int,Products>&a){
    Products p1;
    p1.productID=id;
    p1.name=name;
    p1.quantity=qnty;
    p1.price=price;
    a[id]=p1;
}

void updateStock(int id,int amt,map<int,Products>&a){
    if(a.find(id)!=a.end()){
        a[id].quantity+=amt;
        cout<<"Updated stock for "<<a[id].name<<" to "<<a[id].quantity<<endl;
    } else {
        cout<<"Invalid UID"<<endl;
    }
}

class Customers {
public:
    int customerID;
    string name;
    int phone;
    string address;
    vector<int> orderIDs;
};

vector<Customers> customerList;

void customerAdd(string customerName,int cID,int cPhone,string cAdd){
    Customers c1;
    c1.name=customerName;
    c1.address=cAdd;
    c1.customerID=cID;
    c1.phone=cPhone;
    customerList.push_back(c1);
}

class Orders {
public:
    int orderID;
    int customerID;
    double totalPrice;
    string orderDate;
    string status;
};

vector<Orders> ordersList;

int main(){
    cout<<"Welcome to Inventory & Billing"<<endl;
    int x,id,qnty,UID,amt,cID,cPhone;
    double price;
    string productName,customerName,cAdd;
    map<int,Products>a;

    do{
        cout<<"1) Add new product"<<endl;
        cout<<"2) Update product info"<<endl;
        cout<<"3) Add new customer"<<endl;
        cout<<"4) Create new order"<<endl;
        cout<<"5) Display product catalog"<<endl;
        cout<<"6) Display customer list"<<endl;
        cout<<"7) Show all orders"<<endl;
        cout<<"8) Exit"<<endl;
        cin>>x;
        cin.ignore();

        switch(x){
        case 1:
            cout<<"Enter product ID:";
            cin>>id;
            cout<<"Enter product name:";
            cin>>productName;
            cout<<"Enter product quantity:";
            cin>>qnty;
            cout<<"Enter product price:";
            cin>>price;
            addStock(id,productName,qnty,price,a);
            break;

        case 2:
            cout<<"Enter product ID:";
            cin>>UID;
            cout<<"Enter amount to update:";
            cin>>amt;
            updateStock(UID,amt,a);
            break;

        case 3:
            cout<<"Enter customer name:";
            getline(cin,customerName);
            cout<<"Enter customer ID:";
            cin>>cID;
            cout<<"Enter customer phone:";
            cin>>cPhone;
            cin.ignore();
            cout<<"Enter customer address:";
            getline(cin,cAdd);
            customerAdd(customerName,cID,cPhone,cAdd);
            break;

        case 4:{
            Orders newOrder;
            cout<<"Enter Order ID:";
            cin>>newOrder.orderID;
            cout<<"Enter Customer ID:";
            cin>>newOrder.customerID;
            cout<<"Enter Order Date (dd-mm-yyyy):";
            cin>>newOrder.orderDate;
            newOrder.status="Pending";
            newOrder.totalPrice=0.0;

            int numProducts;
            cout<<"How many products to add?";
            cin>>numProducts;

            for(int i=0;i<numProducts;i++){
                int pid,qty;
                cout<<"Enter Product ID:";
                cin>>pid;
                cout<<"Enter Quantity:";
                cin>>qty;

                if(a.find(pid)!=a.end()){
                    if(a[pid].quantity>=qty){
                        a[pid].quantity-=qty;
                        double cost=qty*a[pid].price;
                        newOrder.totalPrice+=cost;
                        cout<<"Added "<<qty<<" of "<<a[pid].name<<" (Cost:"<<cost<<")"<<endl;
                    } else {
                        cout<<"Not enough stock for "<<a[pid].name<<endl;
                    }
                } else {
                    cout<<"Invalid Product ID!"<<endl;
                }
            }
            ordersList.push_back(newOrder);
            cout<<"Order created successfully! Total Price="<<newOrder.totalPrice<<endl;
            break;
        }

        case 5:
            cout<<"Product Catalog:"<<endl;
            for(auto&p:a){
                cout<<"ID:"<<p.second.productID<<"| ame:"<<p.second.name<<"|Quantity:"<<p.second.quantity<<"|Price:"<<p.second.price<<endl;
            }
            break;

        case 6:
            cout<<"Customer List:"<<endl;
            for(auto&c:customerList){
                cout<<"ID:"<<c.customerID<<"|Name:"<<c.name<<"|Phone:"<<c.phone<<"|Address:"<<c.address<<endl;
            }
            break;

        case 7:
            cout<<"Orders List:"<<endl;
            for(auto&o:ordersList){
                cout<<"Order ID:"<<o.orderID<<"|Customer ID:"<<o.customerID<<"|Date:"<<o.orderDate<<"|Status:"<<o.status<<"|Total Price:"<<o.totalPrice<<endl;
            }
            break;

        case 8:
            cout<<"Exiting program..."<<endl;
            break;

        default:
            cout<<"Invalid option!"<<endl;
            break;
        }
    } while(x!=8);

    return 0;
}