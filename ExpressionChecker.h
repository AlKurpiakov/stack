#pragma once
#include "Stack.h"
#include "Table.h"

class ExpressionChecker{
private:
    Table<string, double> _valTab;
    Table<int, int> _bracketTab;
    Stack<int> _bracketStack;

public:
    bool CheckBrackets(const std::string& s);
    bool ChectVariable();
    void FillVariable();
    bool CheckFormula(const std::string& s);
    bool GetState();
};