#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class List {
    private:
        NodeList<T>* head;

    public:
        List();
        bool isEmpty();
        NodeList<T>* getHead() const;
        void insert(T val);
        void insertHead(T val);
        void insertTail(T val);
        void insertInOrder(T val);

        friend ostream& operator << (ostream& out, const List<T> &list) {
            out << "List head: " << list.head << endl;
            NodeList<T>* ptr = list.head;
            while(ptr != nullptr) {
                out << "\t" << *ptr << endl;
                ptr = ptr -> getNext();
            }

            return out;
        }
};

template <typename T>
List<T> :: List() {
    this -> head = nullptr;
}

template <typename T>
bool List<T> :: isEmpty() {
    return head == nullptr;
}

template <typename T>
void List<T> :: insert(T val) {
    if(isEmpty()) {
        head = new NodeList<T> (val);
        return;
    }
}

template <typename T>
void List<T> :: insertHead(T val) {
    NodeList<T>* temp = new NodeList<T> (val);
    temp -> next = head;
    this -> head = temp;
}

template <typename T>
NodeList<T>* List<T> :: getHead() const {
    return head;
}

template <typename T>
void List<T> :: insertTail(T val) {
    if(this -> isEmpty()) {
        insertHead(val);
        return;
    }
    
    NodeList<T>* ptr = head;
    while(ptr -> getNext() != nullptr) {
        ptr = ptr -> getNext();
    }

    NodeList<T>* temp = new NodeList<T> (val);
    ptr -> next = temp;
}

template <typename T>
void List<T> :: insertInOrder(T val) {
    if(this -> isEmpty()) {
        this ->insertHead(val);
        return;
    }

    if(val <= head -> val) {
        this -> insertHead(val);
        return;
    }

    NodeList<T>* ptr = head;
    while(ptr -> getNext() && (val >= ptr -> val)) {
        
        if(val <= ptr -> next -> val) {
            break;
        }
        ptr = ptr -> getNext();
    }

    if(!(ptr -> next)) {
        this -> insertTail(val);
        return;
    }

    NodeList<T>* toInsert = new NodeList<T> (val);
    toInsert -> next = ptr -> next;
    ptr -> next = toInsert;
}
#endif