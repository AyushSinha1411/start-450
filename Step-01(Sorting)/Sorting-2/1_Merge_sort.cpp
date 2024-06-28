/*
QUESTION:
Implement Merge Sort on an array of integers.

Example:
Input:
arr = [64, 25, 12, 22, 11]
Output:
arr = [11, 12, 22, 25, 64]

APPROACH:
Merge Sort is a divide-and-conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.

1. Divide the array into two halves.
2. Recursively sort each half.
3. Merge the two halves to produce the sorted array.

CODE:
*/

#include <vector>

using namespace std;

// Function to merge two halves of the array
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

/*
TIME COMPLEXITY: O(N log N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(N), due to the temporary arrays used for merging.
*/
