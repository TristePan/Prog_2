#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "DLList.h"

using namespace std;

template <typename T>
class Queue : protected DLList<T> {

    protected :
        int size = 0;
    
    public :

        Queue() : DLList<T>() {};
        bool isEmpty();
        void enqueue(T val);
        DLNode<T> dequeue();

        friend ostream& operator <<(ostream& out, Queue<T>& q) {
            out << "Queue starting at " << &(queue.head);
            DLNode<T>* ptr = q.head;
            while(ptr != nullptr) {
                out << ptr->data << endl;
                ptr = ptr->getNext();
            }
            return out;
        }
};

#endif