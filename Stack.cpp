#include "Stack.h"

template<typename T>
Stack<T>::Stack (size_t size) {
    _size = size;
    _top = 0;
    _array = new T[size]
}

template<typename T>
Stack<T>::Stack (){
    _size = 10;
    _top = 0;
    _array = new T[size]
}

template<typename T>
Stack<T>::~Stack (){
    delete [] _array;
    _array = nullptr;
}

template<typename T>
inline void Stack<T>::Expand() {
    _size *= 2;
    int* arr = new int[_size];
    for (size_t i = 0; i < _size / 2; i++) arr[i] = _array[i];
    delete[] _array;
    _array = arr;
}

template<typename T>
inline void Stack<T>::Reduce() {
    _size = _top + 1;
    T* arr = new T[_size];
    for (size_t i = 0; i < _size; i++) arr[i] = _array[i];
    delete[] _array;
    _array = arr;
}

template<typename T>
inline bool Stack<T>::isEmpty() const{
    return _isEmpty;
}

template<typename T>
inline bool Stack<T>::isFull() const{
    return (_top == _size - 1 && !_isEmpty);
}

template<typename T>
void Stack<T>::Push(const T& elem){
    if (_isEmpty) _isEmpty = false;
    else _top++;
    if (isFull()) Expand();
    _array[_top] = elem;
}

template<typename T>
const T Stack<T>::Pop(){
    if (_isEmpty) return nullptr;
    if (_top == 0) {
        _isEmpty = true;
        return _array[_top];
    }
    if (_top * 2 <= _size  && _size > 100) Reduce();
    return _array[_top--];
}

template<typename T>
const T Stack<T>::Top() const{
    if (_isEmpty) throw ;
    return _array[_top];
}

template<typename T>
ostream& operator<<(ostream& os, const Stack<T>& s){
    if (s._isEmpty) return os;
    for (size_t i = 0; i < s._top; i++){
        os << s.Pop() << " ";
    }
    return os;
}

template<typename T>
ostream& operator<<(ostream& os, const Stack<T>& s){
        if (s._isEmpty) throw;
        for (size_t i = 0; i < s._top; i++){
            os << s._array[i] << " ";
        }
        return os;
}