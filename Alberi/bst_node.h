#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>

template <typename T>
class BSTNode {
    protected:
        T key;
        BSTNode<T>* left;
        BSTNode<T>* right;
        BSTNode<T>* parent;
        bool verbose = false;

        template <typename U>
        friend class BST;

    public:
        //Costructor
        BSTNode(T key, bool verbose = false);

        void setLeft(BSTNode<T>* left);
        void setRight(BSTNode<T>* right);
        void setParent(BSTNode<T>* parent);
        void setKey(T key);
        BSTNode<T>* getLeft();
        BSTNode<T>* getRight();
        BSTNode<T>* getParent();
        T getKey();
        

        friend std :: ostream& operator <<(std :: ostream& out, BSTNode<T>& node) {
            if(node.verbose) {
                out << "BSTNode@" << &node << "Key = " << node.key << " Left = " << node.left << " Right = " << node.right << " Parent = " << node.parent;
            } else {
                out << "BSTNode key=" << node.key;
            }
            return out;
        }

        //distructor
        ~BSTNode() {
            delete left;
            delete right;
        }
  
};

template <typename T>
BSTNode<T> :: BSTNode(T key, bool verbose = false) : key(key), verbose(verbose) {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

template <typename T>
void BSTNode<T> :: setLeft(BSTNode<T>* left) {
    this -> left = left;
}

template <typename T>
void BSTNode<T> :: setRight(BSTNode<T>* right) {
    this -> right = right;
}

template <typename T>
void BSTNode<T> :: setKey(T key) {
    this -> key = key;
}

template <typename T>
void BSTNode<T> :: setParent(BSTNode<T>* parent) {
    this -> parent = parent;
}

template <typename T>
BSTNode<T>* BSTNode<T> :: getLeft() {
    return left;
}

template <typename T>
BSTNode<T>* BSTNode<T> :: getRight() {
    return right;
}


template <typename T>
T BSTNode<T> :: getKey() {
    return key;
}

template <typename T>
BSTNode<T>* BSTNode<T> :: getParent() {
    return parent;
}

#endif