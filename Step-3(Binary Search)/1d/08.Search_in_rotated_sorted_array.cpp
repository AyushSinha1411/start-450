/*
QUESTION:
Given a rotated sorted array 'arr' of size 'n' and a target element 'k', implement a function to search for 'k' in the array.

Example:
Input:
arr = [4, 5, 6, 7, 0, 1, 2], n = 7, k = 0
Output:
4 // Index of 0 in the array

APPROACH:
1. Implement a binary search algorithm to search for the target element 'k'.
2. Check if the left part or the right part of the array is sorted.
3. If the left part is sorted:
   - If the target element 'k' lies within the range of the sorted left part, update the high pointer.
   - Otherwise, update the low pointer.
4. If the right part is sorted:
   - If the target element 'k' lies within the range of the sorted right part, update the low pointer.
   - Otherwise, update the high pointer.
5. Continue the binary search process until the target element 'k' is found or the low pointer exceeds the high pointer.
6. Return the index of the target element if found, otherwise return -1.

CODE:
*/
#include <bits/stdc++.h>
using namespace std;
int search(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        // If mid points the target
        if (arr[mid] == k) return mid;

        // If left part is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                // Element exists
                high = mid - 1;
            } else {
                // Element does not exist
                low = mid + 1;
            }
        } else { // If right part is sorted
            if (arr[mid] <= k && k <= arr[high]) {
                // Element exists
                low = mid + 1;
            } else {
                // Element does not exist
                high = mid - 1;
            }
        }
    }
    return -1;
}

/*
TIME COMPLEXITY: O(log n), where n is the size of the array.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
