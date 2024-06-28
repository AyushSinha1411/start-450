/*
QUESTION:
Write a function to check if the Kth bit of a given integer n is set (1) or not (0).

Example:
Input: n = 5, k = 1
Output: true
Explanation: For n = 5 (binary 101), the 1st bit (0-based index) is set (1).

APPROACH:
1. Use bitwise AND to check if the Kth bit is set.
2. Shift 1 to the left by K positions and perform bitwise AND with n.
3. If the result is non-zero, the Kth bit is set; otherwise, it is not set.

CODE:
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // Function to check if the Kth bit is set or not
    bool checkKthBit(int n, int k) {
        return (n & (1 << k)) != 0;
    }
};

/*
TIME COMPLEXITY: O(1), as bitwise operations are performed in constant time.
SPACE COMPLEXITY: O(1), as no additional space is required beyond the input parameters.
*/
