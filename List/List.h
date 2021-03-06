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
        NodeList<T>* getTail() const;
        void insert(T val);
        void insertHead(T val);
        void insertTail(T val);
        void insertInOrder(T val);
        void removeHead();
        void removeTail();
        void remove(T val);

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
NodeList<T>* List<T> :: getTail() const {
    NodeList<T>* ptr = head;
    while(ptr -> next != nullptr) {
        ptr = ptr -> next;
    }
    return ptr;
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

template <typename T>
void List<T> :: removeHead() {
    if(this -> isEmpty()) {
        cout << "Is empty!!" << endl;
        return;
    }

    NodeList<T>* temp = head;
    head = head -> next;
}

template <typename T>
void List<T> :: removeTail() {
    if(this -> isEmpty()) {
        cout << "Is empty!!" << endl;
        return;
    }

    NodeList<T>* curr = head;
    NodeList<T>* prev = nullptr;

    while(curr -> next) {
        prev = curr;
        curr = prev -> next;
    }

    prev -> next = nullptr;
    delete curr;
}

template <typename T>
void List<T> :: remove(T val) {
	if(this->isEmpty()) {
		cout << "Empty list!" << endl;
		return;
	}

    if(head->val == val) {
        this->removeHead();
        return;
    }

    NodeList<T> *cur = head;
	NodeList<T> *prev = nullptr;

    while(cur->next && cur->val != val) {
		prev = cur;
		cur = cur->next;
	}
		
    if(!(cur->next) && cur->val != val) {
        cout << "Element with value " << val << "not found" << endl;
        return;
    }
    
    prev->next = cur->next;
    delete cur;
}
#endif