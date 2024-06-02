#include "linkedList.hpp"
#include <iostream>


template <typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void LinkedList<T>::insert(T val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;

}


template <typename T>
void LinkedList<T>::remove(T val) {
    if (head == nullptr) return;

    if(head->data == val){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != val){
         current = current->next;
    }

    if(current->next != nullptr){
        Node* temp = current->next;
    }
}






























// #include "linked_list.hpp"
// #include <iostream>

// template <typename T>
// LinkedList<T>::~LinkedList() {
//     Node* current = head;
//     while (current != nullptr) {
//         Node* next = current->next;
//         delete current;
//         current = next;
//     }
// }

// template <typename T>
// void LinkedList<T>::insert(T val) {
//     Node* newNode = new Node(val);
//     newNode->next = head;
//     head = newNode;
// }

// template <typename T>
// void LinkedList<T>::remove(T val) {
//     if (head == nullptr) return;

//     if (head->data == val) {
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//         return;
//     }

//     Node* current = head;
//     while (current->next != nullptr && current->next->data != val) {
//         current = current->next;
//     }

//     if (current->next != nullptr) {
//         Node* temp = current->next;
//         current->next = current->next->next;
//         delete temp;
//     }
// }

// template <typename T>
// bool LinkedList<T>::search(T val) {
//     Node* current = head;
//     while (current != nullptr) {
//         if (current->data == val) {
//             return true;
//         }
//         current = current->next;
//     }
//     return false;
// }

// template <typename T>
// void LinkedList<T>::print() {
//     Node* current = head;
//     while (current != nullptr) {
//         std::cout << current->data << " -> ";
//         current = current->next;
//     }
//     std::cout << "nullptr" << std::endl;
// }
