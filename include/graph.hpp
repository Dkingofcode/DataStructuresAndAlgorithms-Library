#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <list>
#include <unordered_map>

template <typename T>
class Graph {

         public:
             Graph() = default;
             ~Graph() = default;

             void addVertex(const T& vertex);
             void addEdge(const T& src, const T& dest);
             void removeVertex(const T& vertex);
             void removeEdge(const T& src, const T& dest);
             void printGraph() const;

         private:
               std::unordered_map<T, std::list<T>> adjList;    
};

#include "graph.cpp"

#endif  // GRAPH_HPP

