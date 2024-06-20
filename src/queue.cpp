#include "queue.hpp"
#include <iostream>
#include <stdexcept>

template <typename T>
Queue<T>::~Queue() {
    while ( !isEmpty()){
        pop();
    }
}

template <typename T>
void Queue<T>::push(T val){
    Node* newNode = new Node(val);
    if (rear){
        rear->next = newNode;
    }
    rear = newNode;
    if (!front){
        front = rear;
    }
}

template <typename T>
void Queue<T>::pop() {
    if (isEmpty()){
        throw std::runtime_error("Queue underflow: attempting to pop from an empty queue")
    } 
    Node* temp = front;
    front = front->next;
    if (!front){
        rear = nullptr;
    }
    delete temp;
}

template <typename T>
T Queue<T>::peek() const {
    if (isEmpty()){
       throw std::runtime_error("Queue underflow: attempting to peek at an empty queue")
    }
    
    return front->data;
}


template <typename T>
bool Queue<T>::isEmpty() const{
    return front == nullptr;
}

template <typename T>
void Queue<T>::print() const{
    Node* current = front;
    while(current != nullptr){
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std:cout << "nullptr" << std::endl;
}






















