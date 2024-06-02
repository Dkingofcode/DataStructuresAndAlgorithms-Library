#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

template <typename T>
class LinkedList {
    private:
          struct Node{
              T data;
              Node* next;
              Node (T val) : data(val), next(nullptr) {} 
          };
          Node* head;

    public:
          LinkedList() : head(nullptr) {}
          ~LinkedList();

          void insert(T val);
          void remove(T val);
          bool search(T val);
          void print();

};

#include "linked_list.cpp"

#endif


















// #ifndef LINKED_LIST_HPP
// #define LINKED_LIST_HPP

// template <typename T>
// class LinkedList {
// private:
//     struct Node {
//         T data;
//         Node* next;
//         Node(T val) : data(val), next(nullptr) {}
//     };
//     Node* head;

// public:
//     LinkedList() : head(nullptr) {}
//     ~LinkedList();

//     void insert(T val);
//     void remove(T val);
//     bool search(T val);
//     void print();
// };

// #include "linked_list.cpp"

// #endif
