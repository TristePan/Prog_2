#ifndef STACK_H
#define STACK_H

#include "..\List\List.h"
#include <iostream>


template <typename T>
class Stack : protected List<T> {

        int size = 0;
    
    public:

        Stack() : List<T>() {};
        bool isEmpty(); 
        NodeList<T>* top();
        NodeList<T>* bot();
        void push(T val);
        NodeList<T>* pop();

        friend std :: ostream& operator << (std :: ostream& out, Stack<T>& s) {
            return out << (List<T>)s;
        }
};

template <typename T>
bool Stack<T> :: isEmpty() {
    return size == 0;
}


template <typename T>
NodeList<T>* Stack<T> :: top() {
    if(isEmpty())
        return nullptr;

    return List<T> :: getHead();
}

template <typename T>
NodeList<T>* Stack<T> :: bot() {
    if(isEmpty()) {
        return nullptr;
    }
    return List<T> :: getTail();
}

template <typename T>
void Stack<T> :: push(T val) {
    List<T> :: insertHead(val);
    size++;
}

template <typename T>
NodeList<T>* Stack<T> :: pop() {
if(isEmpty())
    return nullptr;
NodeList<T>* ptr = top();
List<T> :: removeHead();
size--;
return ptr;
}

#endif // STACK_H