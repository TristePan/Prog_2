#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include "..\List\List.h"
#include <iostream>

using namespace std;

template <typename T>
class StaticStack : protected List<T> {
        T* array;
        int size = 0;
        int top = -1;
        int maxSize = -1;

    public : 
        StaticStack(int _maxSize);
        bool isEmpty();
        T getTop();
        void push(T val);
        T pop();
        
        friend ostream& operator << (ostream& out, StaticStack<T>& s) {
            out << "Static Stack: maxSize = " << s.maxSize << endl;
            out << "-----" << endl;
            for(int i = s.top; i >= 0; i--) {
                out << s.array[i] << "-";
            }
            out << endl;
            return out;
        }


};

template <typename T>
StaticStack<T> :: StaticStack(int _maxSize) : maxSize(_maxSize) {
    array = new T[maxSize];
}

template <typename T>
T StaticStack<T> :: getTop() {
    if(isEmpty()) {
        return -1;
    }

    return array[top];
}

template <typename T>
bool StaticStack<T> :: isEmpty() {
	return top == -1;
}

template <typename T>
void StaticStack<T> :: push(T val) {
    if(top == maxSize - 1) {
        cout << "Stack is full" << endl;
        return;
    }

    array[++top] = val;
}

template <typename T>
T StaticStack<T> :: pop() {
    if(isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }

    return array[top--];
}






#endif // STATIC_STACK_H