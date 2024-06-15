#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>

class Sorting {
    public: 
      static void bubbleSort(std::vector<int>& arr);

      static void insertionSort(std::vector<int>& arr);

      static void selectionSort(std::vector<int>& arr);

      static void mergeSort(std::vector<int>& arr, int left, int right);

      static void quickSort(std::vector<int>& arr, int low, int high);

      
};

#include "sorting.cpp"

#endif

























// #ifndef SORTING_HPP
// #define SORTING_HPP

// #include <vector>

// class Sorting {
// public:
//     static void bubbleSort(std::vector<int>& arr);
// };

// #include "sorting.cpp"

// #endif
