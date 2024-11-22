#include "Formula.h"


int Formula::FormulaCheckek (string exp){
    Stack<char> s;
	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] == ')') {
			if (s.isEmpty()) return s.isEmpty();
			s.Pop();
		}
		if (exp[i] == '(') s.Push(exp[i]);
	}

	return s.isEmpty();
}


// int Formula::FormulaConverter(void){

// }
double Formula::FormulaCalculator(){
	Stack<double> st(25);
    double first, sec;
    
    for (int i = 0; i < len_of_postfixform; i++) {
        if (isdigit(PostfixForm[i])) {
            st.Push((PostfixForm[i]));
        }

        else {
            if (PostfixForm[i] == '+') {
                first = st.Pop();
                sec = st.Pop();
                st.Push(first + sec);
            }

            else if (PostfixForm[i] == '*') {
                first = st.Pop();
                sec = st.Pop();
                st.Push(first * sec);
            }
            
            else if (PostfixForm[i] == '-') {
                first = st.Pop();
                sec = st.Pop();
                st.Push(sec - first);
            }

            else if (PostfixForm[i] == '/') {
                first = st.Pop();
                sec = st.Pop();
                st.Push(sec / first);
            }
        }
    }
    return st.Pop();
}