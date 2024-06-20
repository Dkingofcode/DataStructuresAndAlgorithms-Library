#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

template <typename T>
class HashTable {
    private:
         struct Node {
            T data;
            Node* next;
            Node(T val) : data(val), next(nullptr) {}
         };
         Node* ;

         public:
             HashTable() : top(nullptr) {}
             ~HashTable();

             void push(T val);
             void pop();
             T peek();
             bool isEmpty();
             void print();
};

#include "hashtable.cpp"

#endif

