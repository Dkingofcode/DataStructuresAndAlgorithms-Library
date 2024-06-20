#include "queue.hpp"
#include <iostream>

template <typename T>
Queue<T>::~Queue() {
    while (front != nullptr){
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename T>
void Queue<T>::push(T val){
    Node* newNode = new Node(val);
    newNode->next = front;
    front = newNode;
}

template <typename T>
void Queue<T>::pop() {
    if (front == nullptr) return;
    Node* temp = front;
    front = front->next;
    delete temp;
}

template <typename T>
T Queue<T>::peek() {
    if (front == nullptr) throw std::runtime_error("Stack is empty");
    return front->data;
}


template <typename T>
bool Queue<T>::isEmpty() {
    return front == nullptr;
}

template <typename T>
void Queue<T>::print() {
    Node* current = front;
    while(current != nullptr){
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std:cout << "nullptr" << std::endl;
}
























// #include "stack.hpp"
// #include <iostream>

// template <typename T>
// Stack<T>::~Stack() {
//     while (top != nullptr) {
//         Node* temp = top;
//         top = top->next;
//         delete temp;
//     }
// }

// template <typename T>
// void Stack<T>::push(T val) {
//     Node* newNode = new Node(val);
//     newNode->next = top;
//     top = newNode;
// }

// template <typename T>
// void Stack<T>::pop() {
//     if (top == nullptr) return;
//     Node* temp = top;
//     top = top->next;
//     delete temp;
// }

// template <typename T>
// T Stack<T>::peek() {
//     if (top == nullptr) throw std::runtime_error("Stack is empty");
//     return top->data;
// }

// template <typename T>
// bool Stack<T>::isEmpty() {
//     return top == nullptr;
// }

// template <typename T>
// void Stack<T>::print() {
//     Node* current = top;
//     while (current != nullptr) {
//         std::cout << current->data << " -> ";
//         current = current->next;
//     }
//     std::cout << "nullptr" << std::endl;
// }
