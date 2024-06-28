/*
QUESTION:
Given a rotated sorted array 'arr' of size 'n' that may contain duplicates and a target element 'k', implement a function to search for 'k' in the array.

Example:
Input:
arr = [2, 5, 6, 0, 0, 1, 2], k = 0
Output:
true // 0 is found in the array

APPROACH:
1. Implement a modified binary search algorithm to search for the target element 'k'.
2. Check if the left part or the right part of the array is sorted.
3. If the left part is sorted:
   - If the target element 'k' lies within the range of the sorted left part, update the high pointer.
   - Otherwise, update the low pointer.
4. If the right part is sorted:
   - If the target element 'k' lies within the range of the sorted right part, update the low pointer.
   - Otherwise, update the high pointer.
5. Handle the edge case where arr[low] == arr[mid] == arr[high].
6. Continue the binary search process until the target element 'k' is found or the low pointer exceeds the high pointer.
7. Return true if the target element is found, otherwise return false.

CODE:
*/
#include <bits/stdc++.h>
using namespace std;
bool searchInARotatedSortedArrayII(vector<int>& arr, int k) {
    int n = arr.size(); // Size of the array
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        // If mid points the target
        if (arr[mid] == k) return true;

        // Edge case
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

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
    return false;
}

/*
TIME COMPLEXITY: O(log n), where n is the size of the array.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
