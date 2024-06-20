#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
class Queue {
    private:
         struct Node {
            T data;
            Node* next;
            Node(T val) : data(val), next(nullptr) {}
         };
         Node* front;

         public:
             Queue() : front(nullptr), rear(nullptr) {}
             ~Queue();

             void push(T val);
             void pop();
             T peek() const;
             bool isEmpty() const;
             void print() const;
};

#include "queue.cpp"

#endif   // QUEUE_HPP































// #ifndef STACK_HPP
// #define STACK_HPP

// template <typename T>
// class Stack {
// private:
//     struct Node {
//         T data;
//         Node* next;
//         Node(T val) : data(val), next(nullptr) {}
//     };
//     Node* top;

// public:
//     Stack() : top(nullptr) {}
//     ~Stack();

//     void push(T val);
//     void pop();
//     T peek();
//     bool isEmpty();
//     void print();
// };

// #include "stack.cpp"

// #endif
