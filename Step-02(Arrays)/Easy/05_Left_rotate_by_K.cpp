/*
QUESTION:
Rotate an array to the right or left by k elements.

Example:
Input:
arr = [1, 2, 3, 4, 5, 6, 7], n = 7, k = 3
Output:
Rotate to right: [5, 6, 7, 1, 2, 3, 4]
Rotate to left: [4, 5, 6, 7, 1, 2, 3]

APPROACH:
To rotate the array, we can use the reversal algorithm:
1. Reverse different parts of the array depending on the rotation direction.
2. Reverse the entire array to achieve the final rotation.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to reverse elements in an array from start to end indices
void Reverse(int arr[], int start, int end) {
    while (start <= end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate k elements to the right
void RotateeletoRight(int arr[], int n, int k) {
    // Reverse the first n-k elements
    Reverse(arr, 0, n - k - 1);
    // Reverse the last k elements
    Reverse(arr, n - k, n - 1);
    // Reverse the whole array
    Reverse(arr, 0, n - 1);
}

// Function to rotate k elements to the left
void RotateeletoLeft(int arr[], int n, int k) {
    // Reverse the first k elements
    Reverse(arr, 0, k - 1);
    // Reverse the last n-k elements
    Reverse(arr, k, n - 1);
    // Reverse the whole array
    Reverse(arr, 0, n - 1);
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(1), as no extra space is used.
*/
