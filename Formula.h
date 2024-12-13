#pragma once
#include <string.h>
#include "Stack.h"
#include "Table.h"

const int MaxLength = 25;

class Formula {
private:
    string _expr;
    string _postfix;
    Stack<char> _stack;
    Table <char,int> _prior;
public:
    Formula(string exp);
    void BuildPostfix();
    double Calculate();
};






