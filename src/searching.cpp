//  LinearSearch(array, key)
//    for each item in the array 
//      if item == value
//       return its index

#include "searching.hpp"


int linearSearch(std::vector<int> array, int value){
    for(int i = 0; i < array.size(); i++){
        if(array[i] == value){
            return i;
        }
    }
}


//  Iterative method
// BinarySearch(array, key)
//    do until the pointers low and high meet each other
//    mid = (low + high) / 2
//    if (x == arr[mid])
//         return mid
//    else if (x > arr[mid]) // x is on the right side
//         low = mid + 1
//    else                  // x is on the left side
//         high = mid - 1

int binarySearch(std::vector<int> array, int x, int low, int high){

    // Repeat until the pointers  low and high meet
    while(low <= high){
        int mid = low + (high - low) / 2;

        if(array[mid] == x){
           return mid;
        }else if(array[mid] < x){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
}

//  Recursive Method
//     binarySearch(arr, x, low, high)
//        if low > high 
//           return False
//        else
//           mid = (low + high) / 2
//           if x == arr[mid]
//                return mid
//           else if x > arr[mid]
//               return binarySearch(arr, x, mid + 1, high)
//           else
//              return binarySearch(arr, x, low, mid - 1);


//    while(low <= high){
//         int mid = low + (high - low) / 2;

//         if(array[mid] == x){
//            return mid;
//         }else if(array[mid] < x){
//             return binarySearch(array, x, mid + 1, high);
//         }else{
//             return binarySearch(array, x, low, mid - 1);
//         }
//     }