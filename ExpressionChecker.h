#pragma once
#include "Stack.h"
#include "Table.h"

class ExpressionChecker{
public:
    bool CheckBrackets(const std::string& s);
    bool ChectVariable();
    void FillVariable();
    bool CheckFormula(const std::string& s);
    bool GetState();
};