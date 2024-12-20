#include "Formula.h"

Formula::Formula(string exp, size_t num_of_un) : _prior("sign", "prior", 6) , _unknow("u", "n", num_of_un){
    _expr = exp;
    _num_of_un = num_of_un;
    _prior.AppendRow('(', 0);
    _prior.AppendRow(')', 1);
    _prior.AppendRow('+', 2);
    _prior.AppendRow('-', 2);
    _prior.AppendRow('*', 3);
    _prior.AppendRow('/', 3);
}

void Formula::FormulaConverter(){
    ExpressionChecker ech(this->_expr, _num_of_un);
    ech.CheckBrackets(this->_expr);
    ech.CheckFormula(this->_expr);
    ech.PrintMistakes(this->_expr);
    string num;

    for (int i = 0; i < _expr.size(); i++) {
        if ((isalnum(_expr[i])) || (_expr[i] == '.')) { 
            _postfix += _expr[i];
            num += _expr[i];
        } 
        
        else if (_expr[i] == '(') {
            if (_expr[i+1] == '-') { _expr.insert(i, "0"); }
            _opStack.Push(_expr[i]);

        } 
        
        else if (_expr[i] == ')') {
            while (!_opStack.isEmpty() && _opStack.Top() != '(') {
                _postfix += _opStack.Pop();
            }
            _opStack.Pop();
        }

        else if (isalpha(_expr[i])){
            _set.insert(_expr[i]);
            _postfix += _expr[i];
        }

        else {
            _stack.Push(static_cast(stod(num)));
            num = "";

            while (!_opStack.isEmpty() && _prior.GetElemFromCol2(_opStack.Top()) >= _prior.GetElemFromCol2(_expr[i])) {
                _postfix += _opStack.Pop();
            }
            _opStack.Push(_expr[i]);
        }
    }

    while (!_opStack.isEmpty()) 
        _postfix += _opStack.Pop();
    

    if(_num_of_un != 0)
        for(char ch : _set){
            double tmp;
            cout << "Введите значение для переменной" << ch << ":";
            cin >> tmp;
            _unknow.AppendRow(ch, tmp);
            cout << endl;
        }

}

double Formula::FormulaCalculator(){
    double first, sec;
    string num;
    Stack<double> stack;
    for (int i = 0; i < this->_expr.size(); i++) {
        if (isdigit(_postfix[i]) || _postfix[i] == '.'){
            while (isdigit(_postfix[i+1]) || _postfix[i+1] == '.') {
                i++;
            }
            stack.Push(stod(num));
        }

        else {
            first = stack.Pop();
            sec = stack.Pop();
            if (_postfix[i] == '+') {
                stack.Push(first + sec);
            }

            else if (_postfix[i] == '*') {
                stack.Push(first * sec);
            }
            
            else if (_postfix[i] == '-') {
                stack.Push(sec - first);
            }

            else if (_postfix[i] == '/') {
                stack.Push(sec / first);
            }
        }
    }
    return stack.Pop();
}