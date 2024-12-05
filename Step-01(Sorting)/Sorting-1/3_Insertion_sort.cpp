/*
QUESTION:
Implement Insertion Sort on an array of integers.

Example:
Input:
arr = [64, 25, 12, 22, 11]
Output:
arr = [11, 12, 22, 25, 64]

APPROACH:
Insertion Sort is a simple sorting algorithm that builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

1. Iterate from the second element to the last element.
2. Compare the current element with the previous elements.
3. Shift all previous elements that are greater than the current element to one position ahead.
4. Insert the current element at the correct position.

CODE:
*/

#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size(); // Get the size of the array

    // Iterate over each element in the array starting from the second element
    for (int i = 0; i < n; ++i) {//!!!!!here it is till i<n and not i<n-1 remember!!!!!
        int j = i;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j > 0 && arr[j-1] > arr[j]) {
            swap(arr[j - 1],arr[j]);
            j--;
        }
    }
}

/*
TIME COMPLEXITY: O(N^2), where N is the number of elements in the array. This is because of the nested loops.
SPACE COMPLEXITY: O(1), as the sorting is done in place and no extra space is required.
*/
