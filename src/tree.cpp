#include "tree.hpp"
#include <iostream>

 template <typename T>
 Tree<T>::~Tree() {
       destroyTree(root);
 }

template <typename T>
void Tree<T>::destroyTree(Node* node) {
    if (node != nullptr){
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}


template <typename T>
bool Tree<T>::isEmpty() const{
    return root == nullptr;
}

template <typename T>
void Tree<T>::insert(T val) {
    Node* newNode = new Node(val);
    if(root == nullptr){
        root  = newNode;
    }else{
        Node* current = root;
        Node* parent = nullptr;
        while(true) {
            parent = current;
            if(val < current->data){
                current = current->left;
               if(current == nullptr){
                parent->left = newNode;
                break;
               }
            }else {
                current = current->right;
                if(current == nullptr){
                    parent->right = newNode;
                    break;
                }
            }

        }
    }
}


template <typename T>
void Tree<T>::printInOrder(Node* node) const {
    if(node != nullptr){
        printInOrder(node->left);
        std::cout << node->data << " ";
        printInOrder(node->right);
    }
}

template <typename T>
void Tree<T>::printPreOrder(Node* node) const {
    if(node != nullptr){
        std::cout << node->data << " ";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}


template <typename T>
void Tree<T>::printPostOrder(Node* node) const {
    if(node != nullptr){
        printPreOrder(node->left);
        printPreOrder(node->right);
        std::cout << node->data << " ";
    }
}



template <typename T>
void Tree<T>::print() const {
    printInOrder(root);
    std:cout << std::endl;
}


















