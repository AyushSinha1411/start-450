/*
QUESTION:
Given a rotated sorted array 'arr' of distinct elements, implement a function to find the index of the minimum element in the array.

Example:
Input:
arr = [4, 5, 6, 7, 0, 1, 2]
Output:
4 // Index of the minimum element in the array

APPROACH:
1. Implement a modified binary search algorithm to find the index of the minimum element in the rotated sorted array.
2. Check if the search space is already sorted.
3. If the search space is sorted, then the first element of the search space will be the minimum element, and its index will be returned.
4. Otherwise, if the left part is sorted:
   - Keep track of the minimum element found so far and its index.
   - Eliminate the left half of the search space.
5. Otherwise, if the right part is sorted:
   - Keep track of the minimum element found so far and its index.
   - Eliminate the right half of the search space.
6. Continue the binary search process until the minimum element is found.
7. Return the index of the minimum element.

CODE:
*/
#include <bits/stdc++.h>
using namespace std;
int findKRotation(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;

        // Search space is already sorted
        // Then arr[low] will always be
        // the minimum in that search space
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }

        // If left part is sorted
        if (arr[low] <= arr[mid]) {
            // Keep track of the minimum
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half
            low = mid + 1;
        } else { // If right part is sorted

            // Keep track of the minimum
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half
            high = mid - 1;
        }
    }
    return index;
}

/*
TIME COMPLEXITY: O(log n), where n is the size of the array.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
