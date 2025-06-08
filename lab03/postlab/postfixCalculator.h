//
// Created by Samuel Campbell on 2/5/22.
//

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include <stack>
#include <string>
#include <iostream>


using namespace std;

class postfixCalculator {
public:
    postfixCalculator();
    ~postfixCalculator();

    bool isOperator(const string& input);
    void performOp(const string& input, stack<int>& calcStack);

    void add();
    void subtract();

private:

};
#endif
