/*
QUESTION:
Given a sorted array 'arr' consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find and return this single element that appears only once.

Example:
Input:
arr = [1, 1, 2, 2, 3, 3, 4, 4, 5]
Output:
5 // The single non-duplicate element in the array

APPROACH:
1. Implement a binary search algorithm to find the single non-duplicate element in the sorted array.
2. Check for edge cases where the single non-duplicate element is either at the beginning or end of the array.
3. Initialize low and high pointers to search within the array.
4. While low is less than or equal to high, perform binary search.
5. Calculate mid as (low + high) / 2.
6. If arr[mid] is the single element, return arr[mid].
7. Check if we are in the left part or right part of the array.
8. If we are in the left part and arr[mid] is equal to arr[mid - 1] (or in the right part and arr[mid] is equal to arr[mid + 1]), eliminate the left (or right) half of the search space.
9. Otherwise, eliminate the right (or left) half of the search space.
10. Continue the binary search process until the single non-duplicate element is found.
11. Return the single non-duplicate element.

CODE:
*/
#include <bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); // Size of the array.

    // Edge cases:
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        // If arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        // We are in the left:
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
                || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            // Eliminate the left half:
            low = mid + 1;
        }
        // We are in the right:
        else {
            // Eliminate the right half:
            high = mid - 1;
        }
    }

    // Dummy return statement:
    return -1;
}

/*
TIME COMPLEXITY: O(log n), where n is the size of the array.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
