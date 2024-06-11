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















