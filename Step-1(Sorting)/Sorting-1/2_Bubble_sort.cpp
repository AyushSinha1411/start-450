/*
QUESTION:
Implement Bubble Sort on an array of integers.

Example:
Input:
arr = [64, 25, 12, 22, 11]
Output:
arr = [11, 12, 22, 25, 64]

APPROACH:
Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

1. Start from the beginning of the array.
2. Compare each pair of adjacent elements.
3. Swap them if they are in the wrong order.
4. Repeat the process for each element in the array until no swaps are needed.

CODE:
*/

#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size(); // Get the size of the array
    bool swapped; // Flag to indicate if any swap was made in the inner loop

    // Outer loop to traverse through all elements
    for (int i = 0; i < n - 1; ++i) {
        swapped = false; // Reset swapped flag for the current pass

        // Inner loop for comparing adjacent elements
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) { // If the current element is greater than the next element
                swap(arr[j], arr[j + 1]); // Swap the elements
                swapped = true; // Set the flag to true indicating a swap was made
            }
        }

        // If no swaps were made, the array is already sorted
        if (!swapped) {
            break; // Exit the loop early
        }
    }
}

/*
TIME COMPLEXITY: O(N^2), where N is the number of elements in the array. This is because of the nested loops.
SPACE COMPLEXITY: O(1), as the sorting is done in place and no extra space is required.
*/
