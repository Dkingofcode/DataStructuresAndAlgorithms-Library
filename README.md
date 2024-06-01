# Data Structures and Algorithms Library

This library provides implementations of common data structures and algorithms in C++.

## Data Structures
- Linked List
- Stack
- Queue
- Hash Table
- Tree
- Graph

## Algorithms
- Sorting (Bubble Sort, Insertion Sort, Quick Sort, etc.)
- Searching (Binary Search, Linear Search)
- Graph Algorithms (DFS, BFS, Dijkstra's, etc.)

## Usage

### Linked List
```cpp
#include "linked_list.hpp"

int main() {
    LinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.print(); // Output: 3 -> 2 -> 1 -> nullptr
    return 0;
}
