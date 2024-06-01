





























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
