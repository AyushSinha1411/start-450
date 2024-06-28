/*
QUESTION:
Implement Quick Sort on an array of integers.

Example:
Input:
arr = [64, 25, 12, 22, 11]
Output:
arr = [11, 12, 22, 25, 64]

APPROACH:
Quick Sort is a divide-and-conquer algorithm. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.

1. Choose a pivot element from the array.
2. Partition the array into two sub-arrays: elements less than the pivot and elements greater than the pivot.
3. Recursively apply the above steps to the sub-arrays.
4. Combine the sorted sub-arrays and the pivot to get the final sorted array.

CODE:
*/

#include <vector>

using namespace std;

// Function to partition the array
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}

/*
TIME COMPLEXITY: O(N log N) on average, where N is the number of elements in the array. In the worst case, it is O(N^2).
SPACE COMPLEXITY: O(log N) due to the recursive stack space.
*/
