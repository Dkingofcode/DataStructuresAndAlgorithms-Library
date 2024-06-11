// #include "sorting.hpp"

// void Sorting::bubbleSort(std::vector<int>& arr) {
//     int n = arr.size();
//     for (int i = 0; i < n - 1; ++i) {
//         for (int j = 0; j < n - 1 - i; ++j) {
//             if (arr[j] > arr[j + 1]) {
//                 std::swap(arr[j], arr[j + 1]);
//             }
//         }
//     }
// }

#include "sorting.hpp"

//  Bubble Sort Algorithm
// bubbleSort(array)
//   for i <= 1 to indexofLastUnSortedElement - 1
//     if leftElement > rightElement  
//        swap leftElement and rightElement
//  end bubbleSort

void Sorting::bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n - 1 - i; ++j){
            if(arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//  Insertion Sort Algorithm

//  insertionSort(array)
//    mark first element as sorted
//    for each unsorted element
//      extract element X
//      for j <= lastSortedElement down to 0
//         if currentElement j > X
//           move sortedElement to the right by 1 
//      break loop
//   end insertionSort     


void Sorting::insertionSort(std::vector<int>& arr){
    int n = arr.size();
    int i, key, j;
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0...i - 1],
        // that are greater than key,
        // to one position ahead of their 
        // current position
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    } 
        
}


//    Selection sort
//   selectionSort(array)
//     repeat(size - 1) times
//     set the first unsorted element as the minimum
//     for each of the unsorted elements
//       if element < minimum
//         set element as newMinumum
//     swap minimum with first unsorted position
//    end selectionSort 

void Sorting::selectionSort(std::vector<int>& arr) {

}










