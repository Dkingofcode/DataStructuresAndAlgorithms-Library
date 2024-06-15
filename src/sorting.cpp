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
       
       for(int i = 0; i < arr.size() - 1; i++){
         int minimum = arr[i];
         int j = i + 1;
         while(j >= 0 && arr[j] < minimum){
            minimum = arr[j];
            arr[i] = minimum;
            j--;
        }
    }
}

 
 void merge(std::vector<int>& arr, int p, int q, int r){

    // Create L and R
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for(int i = 0; i < n1; i++){
        L[i] = arr[p + i];
    }

    for(int j = 0; j < n2; j++){
        M[j] = arr[q + 1 + j];
    }

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of L or R, pick largest
    // elements from L or M and place them in the correct position

    while(i < n1 && j < n2){
        if(L[i] <= M[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M
    // pick up the remaining elements and put in A[p..r]
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
       arr[k] = M[j];
       j++;
       k++; 
    }
   } 


   

void Sorting::mergeSort(std::vector<int>& arr, int left, int right){   
   
  // int left = 0;
  // int right = arr.size() - 1;
   
   if(left < right){

    // m is the point where the array is divided
    int middle = left + (right - left) / 2;

    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
   
   //Merge the sorted subarrays
   merge(arr, left, middle, right);
   };
};


// quickSort(array, leftIndex, rightIndex)
//   if (leftIndex < rightIndex)
//     pivotIndex <= partition(array, leftIndex, rightIndex)
//     quickSort(array, leftIndex, pivotIndex - 1)
//     quickSort(array, pivotIndex, rightIndex);


// partition(array, leftIndex, rightIndex)
//      set rightIndex as pivotIndex
//      storeIndex <= leftIndex - 1
//      for i <= leftIndex + 1 to rightmostIndex
//      if element[i] < pivotElement
//         swap element[i] and element[storeIndex]
//         storeIndex++
//      swap pivotElement and element[storeIndex + 1]
//      return storeIndex + 1

void  swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

// function to rearrange the array
int partition(int array[], int low, int high){

    // select the rightmost element as pivot
    int pivot = array[high];

   //  pointer for  greater element
   int i = (low - 1);

   // traverse each element of the array
   // compare them with the pivot
   for (int j = low; j < high; j++){
     if(array[j] <= pivot){

        // if element smaller than pivot is found
        // swap it with the greater element pointed by i
        i++;

        // swap element at i with element at j
        swap(&array[i], &array[j]);
     }
   }

   // swap pivot with the greater element at i
   swap(&array[i + 1], &array[high]);

   // return the partition point
   return (i + 1);

}


void Sorting::quickSort(std::vector<int>& arr, int low, int high){
if (low < high){

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
}


}










