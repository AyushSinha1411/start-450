/*
QUESTION:
Given a sorted array 'arr' of size 'n' in non-decreasing order and a target element 'k', implement functions to find the first and last occurrence of 'k' in the array, and the count of occurrences of 'k'.

Example:
Input:
arr = [1, 2, 2, 2, 3, 4, 4, 5], n = 8, k = 2
Output:
First Occurrence: 1 // Index of the first occurrence of 2
Last Occurrence: 3 // Index of the last occurrence of 2
Count: 3 // Number of occurrences of 2 in the array

APPROACH:
1. Implement a binary search to find the first occurrence of 'k' in the array.
2. If 'k' is found, update 'first' to the current index and search on the left side.
3. Implement another binary search to find the last occurrence of 'k' in the array.
4. If 'k' is found, update 'last' to the current index and search on the right side.
5. Return the pair containing the first and last occurrence indices.
6. Use the first and last occurrence indices to calculate the count of occurrences of 'k' in the array.

CODE:
*/
#include <bits/stdc++.h>
using namespace std;
int firstOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == k) {
            first = mid;
            high = mid - 1; // Look for smaller index on the left
        } else if (arr[mid] < k) {
            low = mid + 1; // Look on the right
        } else {
            high = mid - 1; // Look on the left
        }
    }
    return first;
}

int lastOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == k) {
            last = mid;
            low = mid + 1; // Look for larger index on the right
        } else if (arr[mid] < k) {
            low = mid + 1; // Look on the right
        } else {
            high = mid - 1; // Look on the left
        }
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOccurrence(arr, n, k);
    if (first == -1) return {-1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}

int count(vector<int>& arr, int n, int x) {
    pair<int, int> ans = firstAndLastPosition(arr, n, x);
    if (ans.first == -1) return 0;
    return (ans.second - ans.first + 1);
}

/*
TIME COMPLEXITY: O(log n), where n is the size of the array.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
