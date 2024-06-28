/*
QUESTION:
Given an array 'arr' of integers, find a peak element in it. An array element is considered a peak if it is greater than its neighbors.

Example:
Input:
arr = [1, 2, 3, 1]
Output:
2 // Index of the peak element, which is 3 in this case

APPROACH:
1. Implement binary search to find a peak element in the array.
2. Check for edge cases where the size of the array is 1 or where the peak element is at either end of the array.
3. Initialize low and high pointers to search within the array.
4. While low is less than or equal to high, perform binary search.
5. Calculate mid as (low + high) / 2.
6. If arr[mid] is greater than both its neighbors, return mid as the index of the peak element.
7. If we are in the left part of the array (arr[mid] > arr[mid - 1]), move towards the right by setting low = mid + 1.
8. If we are in the right part of the array (arr[mid] > arr[mid + 1]) or arr[mid] is a common point, move towards the left by setting high = mid - 1.
9. Continue the binary search process until a peak element is found.
10. Return the index of the peak element.

CODE:
*/
#include <bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> &arr) {
    int n = arr.size(); // Size of array.

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        // If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else high = mid - 1;
    }
    // Dummy return statement
    return -1;
}

/*
TIME COMPLEXITY: O(log n), where n is the size of the array.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
