/*
QUESTION:
Check if an array is sorted in non-decreasing order.

Example:
Input:
arr = [1, 2, 3, 4, 5], n = 5
Output:
True

APPROACH:
To determine if an array is sorted in non-decreasing order:
1. Iterate through the array starting from the second element.
2. Compare each element with the previous element.
3. If any element is smaller than the previous element, the array is not sorted.
4. If no such element is found, the array is sorted.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if the array is sorted
bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) { // Start from the second element
        if (arr[i] < arr[i - 1]) // Compare current element with the previous one
            return false; // Return false if current element is smaller
    }
    return true; // Return true if no elements are out of order
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(1), as no extra space is used.
*/
