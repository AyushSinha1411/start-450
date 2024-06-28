/*
QUESTION:
Given two sorted arrays arr1 and arr2 of size n and m respectively, merge them into one sorted array without using extra space. Modify the given arrays in-place.

Example:
Input:
arr1 = [1, 3, 5, 7], n = 4
arr2 = [0, 2, 6, 8, 9], m = 5
Output:
arr1 = [0, 1, 2, 3]
arr2 = [5, 6, 7, 8, 9]

APPROACH:
1. Initialize two pointers: left (pointing to the last element of arr1) and right (pointing to the first element of arr2).
2. Swap elements between arr1 and arr2 until arr1[left] is smaller than arr2[right].
3. Sort arr1 and arr2 individually using the built-in sort function.

CODE:
*/

#include <algorithm>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) {
    int left = n - 1; // Pointer for arr1
    int right = 0;   // Pointer for arr2

    // Swap elements until arr1[left] is smaller than arr2[right]
    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        } else {
            break;
        }
    }

    // Sort arr1[] and arr2[] individually
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

/*
TIME COMPLEXITY: O((n + m) log(n + m)), where n and m are the sizes of arr1 and arr2 respectively, due to sorting.
SPACE COMPLEXITY: O(1), as the operation is performed in-place without using extra space.
*/
