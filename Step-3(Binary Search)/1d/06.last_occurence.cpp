/*
QUESTION:
You are given a sorted array 'v' of size 'n' in non-decreasing order. Implement a function to find the last occurrence of a given key 'key' in the array. If the key is not present, return -1.

Example:
Input:
n = 7, key = 5, v = [1, 2, 2, 3, 4, 5, 5]
Output:
6 // Last occurrence of 5 is at index 6

APPROACH:
1. Initialize 'start' to 0 and 'end' to n - 1.
2. Initialize 'res' to -1 to store the result.
3. Use binary search to find the last occurrence of 'key' in the array.
4. Iterate until 'start' is less than or equal to 'end'.
5. Calculate 'mid' as the average of 'start' and 'end'.
6. If the element at 'mid' is equal to 'key', update 'res' to 'mid' and search on the right side.
7. If 'key' is less than the element at 'mid', search on the left side.
8. If 'key' is greater than the element at 'mid', search on the right side.
9. Repeat steps 4-8 until 'start' becomes greater than 'end'.
10. Return 'res'.

CODE:
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int n, int key, vector<int> &v) {
    int start = 0; // Starting index of the array
    int end = n - 1; // Ending index of the array
    int res = -1; // Initialize result to -1

    while (start <= end) { // Perform binary search until start <= end
        int mid = start + (end - start) / 2; // Calculate the middle index
        if (v[mid] == key) { // If key is found
            res = mid; // Update result to current index
            start = mid + 1; // Search on the right side for the last occurrence
        } else if (key < v[mid]) { // If key is smaller than element at mid
            end = mid - 1; // Search on the left side
        } else { // If key is greater than element at mid
            start = mid + 1; // Search on the right side
        }
    }
    return res; // Return the last occurrence index of key
}

/*
TIME COMPLEXITY: O(log n), where n is the size of the array.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
