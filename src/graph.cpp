#include "graph.hpp"
#include <iostream>

// template <typename T>
// Graph<T>::~Graph() {
//     while (front != nullptr){
//         Node* temp = front;
//         front = front->next;
//         delete temp;
//     }
// }

template <typename T>
void Graph<T>::addVertex(const T& vertex){
    adjList[vertex];  // This will initialize the vertex with the adjacency list;
}

template <typename T>
void Graph<T>::addEdge(const T& src, const T& dest) {
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);  // If the graph is undirected, if the graph is directed pls comment this.
}

template <typename T>
void Graph<T>::removeVertex(const T& vertex) {
    adjList.erase(vertex);

    for(auto& [key, neighbors] : adjList){
        neighbors.remove(vertex);
    }
}


template <typename T>
void Graph<T>::removeEdge(const T& src, const T& dest) {
    adjList[src].remove(dest);
    adjList[dest].remove(src);  // If the graph is undirected, if directed pls comment this
}

template <typename T>
void Graph<T>::printGraph() const {
    for (const auto& [vertex, neighbors] : adjList) {
        std::cout << vertex << ": ";
        for (const auto& neighbor : neighbors) {
            std::cout << neighbor << " ";
        }
    std:cout << std::endl;
    }
}



























