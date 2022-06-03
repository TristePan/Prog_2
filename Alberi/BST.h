#ifndef BST_H
#define BST_H

#include "bst_node.h"
#include <iostream>

template <typename T>
class BST {
        
        BSTNode>T>* root;

    public :
        //Costructor
        BST();

        bool isEmpty();
        void insert(T key);
        void insert(BSTNode<T>* ptr, T key);
        void visit(BSTNode<T>* node);
        void inorder(BSTNode<T>* ptr);
        void inorder();
};

template <typename T>
BST<T> :: BST() {
   root = nullptr;
}

template <typename T>
bool BST<T> :: isEmpty() {
    return root = nullptr;
}

template <typename T>
void BST<T> :: insert(T key) {
    if(this -> isEmpty()) {
        root = new BSTNode<T> (key);
        return;
    }
}

//La mia procedura ricorsiva deve avere due parametri :
//-Il valore da inserire
//-La radice del sottoalbero

template <typename T>
void BST<T> :: insert(BSTNode<T>* ptr, T key) {
    if(ptr == nullptr) {
        ptr = new BSTNode<T> (key);
        return;
    }
    else if(key <= ptr -> key)
        insert(ptr -> left, key);
    else
        insert(ptr -> right, key);
}

template <typename T>
void BST<T> :: visit(BSTNode<T>* node) {
    std :: cout  *node << std :: endl;
}

template <typename T>
void BST<T> :: inorder(BSTNode<T>* ptr) {
    if(ptr == nullptr) {
        return;
    }
    inorder(root);
    visit(ptr);
    inorder(ptr -> left);
}
template <typename T>
void BST<T> :: inorder() {
    
    inorder(root);
}

#endif