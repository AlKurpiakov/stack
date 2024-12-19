#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* _array;
    size_t _size;
    size_t _top;
    bool _isEmpty = true;

    void Expand();
    void Reduce();

public:

    Stack (size_t size);
    Stack ();
    ~Stack();


    inline bool isEmpty() const;
    inline bool isFull() const;
    

    void Push(const T& elem);
    const T Pop();
    const T Top() const;
    
    void Revers();
    size_t GetSize();
    friend ostream& operator<<(ostream& os, const Stack& s);
};
