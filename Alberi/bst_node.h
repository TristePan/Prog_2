#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>

template <typename T>
class BSTNode {
    protected:
        T key;
        BSTNode<T>* left;
        BSTNode<T>* right;

        template <typename U>
        friend class BST;

    public:
        //Costructor
        BSTNode(T key) : key(key);

        void setLeft(BSTNode<T>* left);
        void setRight(BSTNode<T>* right);
        BSTNode<T>* getLeft();
        BSTNode<T>* getRight();
        void setKey(T key);
        T getKey();
        

        friend std :: ostream& oeprator <<(std :: ostream& out, BSTNode<T>& node) {
            out << "BSTNode@" << &node << "Key = " << node.key << " Left = " << node.left << " Right = " << node.right;
            return out;
        }

        //distructor
        ~BSTNode() {
            delete left;
            delete right;
        }
  
};

template <typename T>
BSTNode<T> :: BSTNode(T key) : key(key) {
    left = nullptr;
    right = nullptr;
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
BSTNode<T>* BSTNode<T> :: getLeft() {
    return left;
}

template <typename T>
BSTNode<T>* BSTNode<T> :: getRight() {
    return right;
}

template <typename T>
void BSTNode<T> :: setKey(T key) {
    this -> key = key;
}

template <typename T>
T BSTNode<T> :: getKey() {
    return key;
}

#endif