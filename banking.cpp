#include <iostream>
#include <string>
using namespace std;

// Base class
class Account {
protected:
    int accNumber;
    string holderName;
    double balance;
public:
    Account(int number, string name, double bal = 0.0){
        this->accNumber = number;
        this->holderName = name;
        this->balance = bal;
    } 
    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }
    virtual void withdraw(double amount) {
        if(amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
    virtual void display() {
        cout << "Account Number: " << accNumber << endl;
        cout << "Holder: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Derived class
class SavingsAccount : public Account {
public:
    SavingsAccount(int number, string name, double bal = 0.0)
        : Account(number, name, bal) {}

    void display(){
        cout << "[Savings Account]" << endl;
        Account::display();
    }
};

// Derived class
class CurrentAccount : public Account {
public:
    CurrentAccount(int number, string name, double bal = 0.0)
        : Account(number, name, bal) {}

    void display() {
        cout << "[Current Account]" << endl;
        Account::display();
    }
};

int main() {
    // Create objects
    SavingsAccount s1(101, "Animesh", 5000);
    CurrentAccount c1(102, "Priyanshu", 3000);

    cout<<endl;
    // Use OOP methods
    s1.deposit(1000);
    c1.withdraw(500);

    cout<<endl;
    // Polymorphism
    Account *acc;
    acc = &s1;
    acc->display();

    cout<<endl;
    acc = &c1;
    acc->display();


    cout << endl;
    return 0;
}