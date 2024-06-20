#ifndef TREE_HPP
#define TREE_HPP

template <typename T>
class Tree {
    private:
         struct Node {
            T data;
            Node* next;
            Node(T val) : data(val), next(nullptr) {}
         };
         Node* root;

         public:
             tree() : root(nullptr) {}
             ~Tree();

             void push(T val);
             void pop();
             T peek();
             bool isEmpty();
             void print();
};

#include "tree.cpp"

#endif

