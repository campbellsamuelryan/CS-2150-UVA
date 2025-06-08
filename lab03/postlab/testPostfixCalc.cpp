/*
Samuel Campbell
"testPostfixCalc.cpp"
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include "postfixCalculator.h"
using namespace std;

int main() {
    postfixCalculator p;
    string token;
   
    while (cin >> token ) {
        // Do stuff with `token`!
        // For example, we can print each token back out on its own line:
       // cout << token << endl;
        if(isdigit(token[0])) {
            p.addNum(stoi(token));
        }

        //Negative integer check
        else if(token.size() > 1 && token[0] == '-') {
            p.addNum(stoi(token));
        }

        //Addition
        else if(token == "+") {
            p.add();

        }
        //Subtration
        else if(token == "-") {
            p.subtract();
        }

        //Multiplication
        else if(token == "*") {
            p.multiply();

        }

        //Division
        else if(token == "/") {
            p.divide();

        }

        //Negation
        else if(token == "~") {
            p.negate();

        }


    }
    cout << p.getTopValue() << endl;
    return 0;
};
