#include <iostream>
#include "Account.h"
using namespace std;


//Loop
bool mainLoop(){
    char a;
    cin >> a;
    if(a == 'q'){
        return true;
    }else{
        return false;
    }
    /*
    cout << "What would you like to do?" << endl;
    string input;
    cin >> input;
    if(input == "h" || "help" || "h " || "help " || "H" || "Help" || "H " || "Help "){
        cout << "Here are a list of commands: " << endl << "See Balance (sb)" << endl << "Withdraw (W)" << endl << "Deposit (D)" << endl;
    }else if(input == "W" || "Withdraw"){
    }
     */
}

void login(string accountName){
    cout << "Press 'l' to login or 'c' to create an account." << endl;
    char loginQuestionOneInput;
    cin >> loginQuestionOneInput;
    if(loginQuestionOneInput == 'l'){
         cout << "There is nothing to do yet here, sorry." << endl;
    }else if(loginQuestionOneInput == 'c'){
        account a;
        initialize(a);
    }
}

int main() {

    //Init
    cout << "Welcome to the Bank! Please enter the name of your account." << endl;
    string name;
    cin >> name;
    login(name);
    while(true){
        if(mainLoop()){
            break;
        }
    }
    return 0;
}


