#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stack>
#include <string>


using namespace std;
#include "postfixCalculator.h"


int main(){
    postfixCalculator* px = new postfixCalculator();
    cout << "Welcome to the PostFix Calculator." << endl;

    stack<int> myStack;
    string userInput;
    while (true) {
        cin >> userInput;
        // check for numeric value. if we have a numeric value, this condition will be true, and we push the num to stack.
        int x;
        
    
        
//        if (userInput != "-" && "+" && "*" && "/") {
//            cout <<"OG IF STATEMENT: " <<userInput;
////            x = stoi(userInput);
////            myStack.push(x);
//        }
        if (userInput != "-" && userInput != "+" && userInput != "*" && userInput != "/") {
            cout << "NEW IF STATEMENT " << userInput;
            x = stoi(userInput);
            myStack.push(x);
        }
        /*
        if (isdigit(userInput)) {
            x = stoi(userInput);
            myStack.push(x);
        }

            // check for operator
        else if (px->theOperator(to_string(x))) {
            px->theOperation(userInput, myStack);
            
        }
         
        else if (userInput == "q") {
            return 0; // Quit program
        }

            // invalid output statement
        else {
            cout << "Invalid user input" << endl;
        }
         */
    }
    return 0;
}
