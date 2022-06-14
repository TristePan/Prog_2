#ifndef BST_H
#define BST_H

#include "bst_node.h"
#include <iostream>

template <typename T>
class BST {
        
        BSTNode<T>* root;

    public :
        //Costructor
        BST();

        bool isEmpty();
        BSTNode<T>* getRoot();
        void insert(T key);
        void insert(BSTNode<T>* ptr, T key);
        void visit(BSTNode<T>* node);
        void inorder(BSTNode<T>* ptr);
        void inorder();
        BSTNode<T>* min(BSTNode<T>* from);
        BSTNode<T>* min();
        BSTNode<T>* max(BSTNode<T>* from);
        BSTNode<T>* max();
        void remove(T key);
        void BST<T> :: remove(BSTNode<T>* node);

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
BSTNode<T>* BST<T> :: getRoot() {
    return root;
}

template <typename T>
void BST<T> :: insert(T key) {
    if(this -> isEmpty()) {
        root = new BSTNode<T> (key);
        return;
    }
    insert(root, key);
}

//La mia procedura ricorsiva deve avere due parametri :
//-Il valore da inserire
//-La radice del sottoalbero

template <typename T>
void BST<T> :: insert(BSTNode<T>* ptr, T key) {
    if(ptr->left == nullptr && key <= ptr->key) {
        ptr->left = new BSTNode<T>(key);
        ptr->left->setParent(ptr);
        return;
    }
    if(ptr->right == nullptr && key > ptr->key) {
        ptr->right = new BSTNode<T>(key);
        ptr->right->parent = ptr;
        return;
    }
    else if(key <= ptr->key)
        insert(ptr->left, key);
    else
        insert(ptr->right, key);
}

template <typename T>
void BST<T> :: visit(BSTNode<T>* node) {
    std :: cout << *node << std :: endl;
}

template <typename T>
void BST<T> :: inorder(BSTNode<T>* ptr) {
    if(ptr == nullptr) {
        return;
    }
    inorder(ptr -> left);
    visit(ptr);
    inorder(ptr -> right);
}

template <typename T>
void BST<T> :: inorder() {
    
    inorder(root);
}

	







template <typename T>
BSTNode<T>* BST<T> :: min(BSTNode<T>* from) {
		if(isEmpty()) {
			return NULL;
		}
		
		BSTNode<T>* ptr = from;
		while(ptr->left) {
			ptr = ptr->left;
		}
		
		return ptr;
}

template <typename T>
BSTNode<T>* BST<T> :: min() {
		return min(root);
}

template <typename T>
BSTNode<T>* BST<T> :: max() {
		return max(root);
}
	
template <typename T>
BSTNode<T>* max(BSTNode<T>* from) {
	if(isEmpty()) {
		return NULL;
	}
		
	BSTNode<T>* ptr = from;
	while(ptr->right) {
		ptr = ptr->right;
	}	
	return ptr;
}

template <typename T>
void BST<T> :: remove(BSTNode<T>* node) {
    
    //CASO 1
    //Il nodo da eliminare è una foglia
    if(node -> left == nullptr && node -> right == nullptr) {
        if(node = node -> parent -> left) {
            node -> parent -> left = nullptr;
        } else if(node == node -> parent -> right) {
            node -> parent -> right = nullptr;
        }
    }
    
    //CASO 2
    //Il nodo da eliminare ha un solo figlio destro
    if(node -> left == nullptr && node -> right != nullptr) {
        node -> right -> parent = node -> parent;

        //Il nodo da eliminare è il figlio sinistro
        if(node == node -> parent -> left) {
            node -> parent -> left = node -> right;
        }
        //Il nodo da eliminare è il figlio destro
        else if(node == node -> parent -> right) {
            node -> parent -> right = node -> right;
        }
    }

    //Caso 3
    //Il nodo da eliminare ha un solo figlio sinistro
    if(node -> left != nullptr && node -> right == nullptr) {
        node -> left -> parent = node -> parent;

        //Il nodo da eliminare è il figlio sinistro
        if(node == node -> parent -> left) {
            node -> parent -> left = node -> left;
        }
        //Il nodo da eliminare è il figlio destro
        else if(node == node -> parent -> right) {
            node -> parent -> right = node -> left;
        }
    }

    return nullptr;
}

template <typename T>
void BST<T> :: remove(T key) {
    if(this -> isEmpty()) {
        return;
    }

    BSTNode<T>* node = this -> search(key);

    if(node == nullptr) {
        return;
    }

    BSTNode<T>* toDelete = this -> remove(node);

    if(toDelete != nullptr) {
        return;
    }

    //CASO 3
    // Il nodo da eliminare ha due figli
    // Sostituiamo la chiave nle nodo da eliminar con la chiave del suo successore
    BSTNode>T>* next = this -> successor(node);
    
    //Sostituzione della chiave
    T swap = node -> key;
    node -> key = next -> key;
    next -> key = swap;

    //Eliminazione del nodo successore
    toDelete = this -> remove(next);

    return toDelete;


}

#endif