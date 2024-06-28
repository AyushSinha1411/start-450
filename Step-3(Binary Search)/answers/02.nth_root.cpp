/*
QUESTION:
Given two integers 'n' and 'm', where 'n' is the power and 'm' is the number, find the nth root of 'm'.

Example:
Input:
n = 2, m = 16
Output:
4 // 4 is the square root of 16

APPROACH:
1. Implement binary search to find the nth root of 'm'.
2. Define a function 'func' to calculate 'mid' raised to the power 'n'.
3. Initialize low and high pointers for binary search.
4. While low is less than or equal to high, perform binary search.
5. Calculate mid as (low + high) / 2.
6. Calculate midN using the 'func' function:
    - If midN equals 1, return mid as the nth root of 'm'.
    - If midN equals 0, update low = mid + 1 to search in the right half.
    - If midN equals 2, update high = mid - 1 to search in the left half.
7. Continue the binary search process until low becomes greater than high.
8. Return -1 if the nth root is not found.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Return 1 if mid raised to the power n is equal to m,
// return 0 if less than m, return 2 if greater than m.
int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

// Function to find the nth root of m using binary search.
int NthRoot(int n, int m) {
    // Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1) {
            return mid;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

/*
TIME COMPLEXITY: O(log m), where m is the given integer.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
