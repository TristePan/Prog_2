#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <typename T>
class NodeList {
    private:
        T val;
        NodeList<T>* next;

    public:
        NodeList(T val);
        NodeList<T>* getNext();

        template <typename U>
        friend class List;

        friend ostream& operator << (ostream& out, const NodeList<T> &node) {
            out << "node val: " << node.val << " - next: " << node.next << endl;
            return out;
        }
};

template <typename T>
NodeList<T> :: NodeList(T val) {
    this -> val = val;
    this -> next = NULL;
}

template <typename T>
NodeList<T>* NodeList<T> :: getNext() {
    return this -> next;
}
#endif