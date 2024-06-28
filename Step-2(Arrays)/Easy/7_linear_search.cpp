/*
QUESTION:
Search for a given number in an array of integers and return its index.

Example:
Input:
arr = [2, 4, 6, 8, 10], n = 5, num = 8
Output:
3

APPROACH:
1. Iterate through the array.
2. Compare each element with the given number.
3. If a match is found, return the index.
4. If no match is found after the entire array is traversed, return -1.

CODE:
*/
#include <bits/stdc++.h>
using namespace std;
int search(int arr[], int n, int num) {
    for (int i = 0; i < n; i++) { // Iterate through the array
        if (arr[i] == num) // Compare each element with the given number
            return i; // Return the index if a match is found
    }
    return -1; // Return -1 if no match is found
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(1), as no extra space is used.
*/