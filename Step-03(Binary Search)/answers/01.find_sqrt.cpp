/*
QUESTION:
Given a non-negative integer 'n', find the largest integer 'x' such that 'x^2' is less than or equal to 'n'.

Example:
Input:
n = 8
Output:
2 // 2 is the largest integer whose square is less than or equal to 8

APPROACH:
1. Implement binary search to find the square root of 'n'.
2. Initialize low and high pointers for binary search.
3. While low is less than or equal to high, perform binary search.
4. Calculate mid as (low + high) / 2.
5. Calculate the square of mid and store it in a variable 'val'.
6. If val is less than or equal to 'n', update low = mid + 1 to search in the right half.
7. If val is greater than 'n', update high = mid - 1 to search in the left half.
8. Continue the binary search process until low becomes greater than high.
9. Return high as the largest integer 'x' such that 'x^2' is less than or equal to 'n'.

CODE:
*/
#include <bits/stdc++.h>
using namespace std;
int floorSqrt(int n) {
    int low = 1, high = n;
    // Binary search on the answers:
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n)) {
            // Eliminate the left half:
            low = mid + 1;
        }
        else {
            // Eliminate the right half:
            high = mid - 1;
        }
    }
    return high;
}

/*
TIME COMPLEXITY: O(log n), where n is the given non-negative integer.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
