#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <list>
#include <unordered_map>

template <typename T>
class Tree {
    private:
         struct Node {
            T data;
            Node* left;
            Node* right;
            Node(T val) : data(val), left(nullptr), right(nullptr) {}
         };
        Node*  root;
         
         void destroyTree(Node* node);
         void printInOrder(Node* node) const;
         void printPreOrder(Node* node) const;
         void printPostOrder(Node* node) const;

         public:
             Tree() : root(nullptr) {}
             ~Tree();

             bool isEmpty() const;
             void insert(T val);
             void print() const;
};

#include "tree.cpp"

#endif

