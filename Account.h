//
// Created by haquilus on 6/15/22.
//
#define BANKERSPIN 8294
#ifndef THEBANK_ACCOUNT_H
#define THEBANK_ACCOUNT_H
#include <string>
#include <iostream>
#include <thread>
using namespace std;

class account{
public:

    // init
    string name;
    bool isInitialized = false;

    friend void initialize(account a){
        if(!a.isInitialized){
            cout << "Enter the name of the account holder." << endl;
            cin >> a.name;
            cout << "Enter the amount of money in the account." << endl;
            cin >> a.balance;
            cout << "Enter the banker's pin to confirm your balance." << endl;
            int attemptAtBankersPin;
            cin >> attemptAtBankersPin;
            if(attemptAtBankersPin == BANKERSPIN){
                cout << "Your balance has been confirmed." << endl;
            }else{
                cout << "The pin you have entered is incorrect." << endl
                << "The process will continue, but your balance will be set to $0.";
                a.balance = 0;
            }
            cout << "Create a four digit pin and enter it. It can not be changed later." << endl;
            cin >> a.pin;
            cout << "The initialization process is now complete. Thank you for choosing us.";
            a.isInitialized = true;
        }else{
            cout << "The initialization process has already occurred for this account. Wait, how did you get here?"
            << endl;
        }
    }


    // functions
    static void seeBalance(account a) {
        if(a.isInitialized){
            cout << "What is your pin?" << endl;
            int inputPin;
            cin >> inputPin;
            if(inputPin == a.pin){
                cout << "This is your balance: $" << endl << a.balance << endl;
            }else{
                cout << "Wrong pin." << endl
                << "Now you have to wait one second." << endl;
                this_thread::sleep_for(1s);
            }
        }else{
            cout << "This Account has not been initialized." << endl;
        }
    }

    static void withdraw(account a, int amountToWithdraw) {
        if(a.isInitialized){
            cout << "What is your pin?" << endl;
            int inputPin;
            cin >> inputPin;
            if(inputPin == a.pin){
                a.balance -= amountToWithdraw;
                cout << "Your current balance is: " << a.balance << "." << endl;
            }else{
                cout << "Wrong pin." << endl
                << "Now you have to wait one second." << endl;
                this_thread::sleep_for(1s);
            }
        }else{
            cout << "This Account has not been initialized." << endl;
        }
    }

    static void deposit(account a, int amountToDeposit) {
        if(a.isInitialized){
            cout << "What is your pin?" << endl;
            int inputPin;
            cin >> inputPin;
            cout << "Please ask a teller for assistance in entering their pin." << endl;
            int tryPin;
            cin >> tryPin;
            if(inputPin == a.pin && tryPin == BANKERSPIN){
                a.balance += amountToDeposit;
                cout << "Your current balance is: " << a.balance << "." << endl;
            }else{
                cout << "Wrong pin." << endl
                << "Now you have to wait one second." << endl;
                this_thread::sleep_for(1s);
            }
        }else{
            cout << "This Account has not been initialized." << endl;
        }
    }

private:
    int balance = 0;
    int pin;
};


#endif //THEBANK_ACCOUNT_H
