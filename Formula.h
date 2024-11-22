#pragma once
#include "Stack.h"


const int MaxLength = 25;

class Formula {
private:
    char Formula[MaxLength];
    char PostfixForm[MaxLength];
    size_t len_of_postfixform;
    size_t len_of_form;
    
public:
    //TFTrans (char form[]);
    int FormulaCheckek (string exp);
    int FormulaConverter(void);
    double FormulaCalculator (); 
};