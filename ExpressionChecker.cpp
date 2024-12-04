#include "ExpressionChecker.h"
#include "Table.h"
#include <optional>


bool ExpressionChecker::CheckBrackets (const std::string& s){
    Table<int, int> t1("(", ")");
    Stack<int> st;
    for (size_t i = 0; i < s.size(); i++){
        if(s[i]=='(')
            st.Push(i);
        if(s[i]==')'){
            try{
            t1.AppendRow(st.Pop(), i);

            }
            catch(const char* error_message){
                t1.AppendRow(std::nullopt, i);
                std::cout<<"error in brackets "<<i<<std::endl;
                std::cout<<t1<<std::endl;
                return false;
            }
        }  
    }
    while(!st.isEmpty()){
        t1.AppendRow(st.Pop(), std::nullopt);
    }
    std::cout<<t1<<std::endl;
    return st.isEmpty();
    

}