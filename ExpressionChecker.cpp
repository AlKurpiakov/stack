#include "ExpressionChecker.h"
#include "Table.h"
#include <optional>


bool ExpressionChecker::CheckBrackets (const std::string& s){
    for (size_t i = 0; i < _bracketStack.GetSize(); i++){
        if(s[i]=='(')
            _bracketStack.Push(i);
        if(s[i]==')'){
            try{
            _bracketTab.AppendRow(_bracketStack.Pop(), i);
            }
            catch(const char* error_message){
                _bracketTab.AppendRow(std::nullopt, i);
            }
        }  
    }
    while(!_bracketStack.isEmpty()){
        _bracketTab.AppendRow(_bracketStack.Pop(), std::nullopt);
    }
    _bracketTab.Print();
    return _bracketStack.isEmpty();
    

}