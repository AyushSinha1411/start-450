/*
QUESTION:
Given an array representing a permutation of numbers, find the next greater permutation in lexicographic order. If no such permutation exists, return the array sorted in ascending order.

Example:
Input:
A = [1, 3, 2]
Output:
The next greater permutation is: [2, 1, 3]

APPROACH:
1. Find the break point by iterating from right to left through the array. The break point is the index where A[i] < A[i + 1].
2. If no break point is found, it means the array is in descending order, so reverse the array and return.
3. Find the next greater element to swap with A[ind]. Iterate from right to left through the array and find the first element greater than A[ind].
4. Swap A[ind] with the next greater element found.
5. Reverse the right half of the array to get the next greater permutation.
6. Return the modified array.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the next greater permutation
vector<int> nextGreaterPermutation(vector<int>& A) {
    int n = A.size(); // Size of the array

    // Step 1: Find the break point
    int ind = -1; // Break point
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            ind = i; // Index i is the break point
            break;
        }
    }

    // If break point does not exist, reverse the array
    if (ind == -1) {
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element and swap it with A[ind]
    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: Reverse the right half of the array
    reverse(A.begin() + ind + 1, A.end());

    return A; // Return the next greater permutation
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(1), as no extra space is used.
*/
