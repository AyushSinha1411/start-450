/*
QUESTION:
Move all zeros in an array to the end while maintaining the relative order of non-zero elements.

Example:
Input:
n = 5, a = [0, 1, 0, 3, 12]
Output:
[1, 3, 12, 0, 0]

APPROACH:
1. Use a pointer `j` to mark the first occurrence of zero.
2. Iterate through the array:
   - If a non-zero element is found, swap it with the element at pointer `j` and increment `j`.
3. Return the modified array.

CODE:
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> moveZeros(int n, vector<int> a) {
    int j = -1; // Initialize pointer j

    // Place the pointer j at the first zero element
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }

    // If no zero element is found, return the array as is
    if (j == -1) return a;

    // Move the pointers i and j, and swap accordingly
    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a; // Return the modified array
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(1), as no extra space is used.
*/
