/*
QUESTION:
Implement Selection Sort on an array of integers.

Example:
Input:
arr = [64, 25, 12, 22, 11]
Output:
arr = [11, 12, 22, 25, 64]

APPROACH:
Selection Sort works by repeatedly finding the minimum element from the unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array:
1. The subarray which is already sorted.
2. The remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element from the unsorted subarray is picked and moved to the sorted subarray.

CODE:
*/

#include <vector>
#include <algorithm>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size(); // Get the size of the array
    for (int i = 0; i < n - 1; ++i) { // Iterate over each element of the array except the last one
        int minIndex = i; // Assume the current element is the minimum
        for (int j = i + 1; j < n; ++j) { // Iterate over the unsorted subarray to find the actual minimum element
            if (arr[j] < arr[minIndex]) { // Compare the current element with the assumed minimum
                minIndex = j; // Update the index of the minimum element
            }
        }
        // Swap the found minimum element with the first element of the unsorted subarray
        swap(arr[minIndex], arr[i]);
    }
}

/*
TIME COMPLEXITY: O(N^2), where N is the number of elements in the array. This is because of the nested loops.
SPACE COMPLEXITY: O(1), as the sorting is done in place and no extra space is required.
*/
