/*
QUESTION:
Find the largest element in an array of integers.

Example:
Input:
arr = [2, 5, 1, 3, 0], n = 5
Output:
The largest element in the array is: 5

APPROACH:
1. Initialize the first element of the array as the maximum element.
2. Iterate through the array.
3. If the current element is greater than the maximum element, update the maximum element.
4. Return the maximum element.

CODE:
*/

#include <bits/stdc++.h>

using namespace std;

// Function to find the largest element in an array
int findLargestElement(int arr[], int n) {
    int max = arr[0]; // Initialize max with the first element
    for (int i = 0; i < n; i++) { // Iterate through the array
        if (max < arr[i]) { // If current element is greater than max
            max = arr[i]; // Update max
        }
    }
    return max; // Return the largest element
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(1), as no extra space is used.
*/
