/*
QUESTION:
Write a function to determine if a given integer n is a power of two. Return true if n is a power of two, and false otherwise.

Example:
Input: n = 16
Output: true
Explanation: 16 is a power of two (2^4).

APPROACH:
1. If n is 0, return false as 0 is not a power of two.
2. Use bitwise AND to check if n is a power of two.
3. For a number to be a power of two, only one bit in its binary representation should be set.
4. n & (n - 1) will be 0 only if n is a power of two.

CODE:
*/

#include <iostream>
using namespace std;

// Function to determine if a given integer is a power of two
bool isPowerOfTwo(int n) {
    if (n == 0) return false; // 0 is not a power of two
    long x = n;
    return (x & (x - 1)) == 0;
}

/*
TIME COMPLEXITY: O(1), as bitwise operations are performed in constant time.
SPACE COMPLEXITY: O(1), as no additional space is required beyond the input parameter.
*/
