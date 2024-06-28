/*
QUESTION:
Write a function to find the XOR of all numbers in a given range [l, r].

Example:
Input: l = 2, r = 4
Output: 5
Explanation: XOR of numbers from 2 to 4 is 2 ^ 3 ^ 4 = 5.

APPROACH:
1. Use a helper function `findXOR(int n)` to compute the XOR of all numbers from 0 to n.
2. The XOR from l to r can be calculated using the property: XOR(l to r) = XOR(0 to r) ^ XOR(0 to l-1).

CODE:
*/

#include <iostream>
using namespace std;

int computeXOR(int n)
    {
        // XOR of all numbers from 1 to n can be evaluated with the help of the following observations:
        // If n mod 4 equals 0, then XOR will be same as n.
        // If n mod 4 equals 1, then XOR will be 1.
        // If n mod 4 equals 2, then XOR will be n+1.
        // If n mod 4 equals 3, then XOR will be 0.
        // For example, if n = 6, then n mod 4 = 2, so XOR of all numbers from 1 to 6 will be 6+1 = 7.
        if (n % 4 == 0)
            return n;
        if (n % 4 == 1)
            return 1;
        if (n % 4 == 2)
            return n + 1;
        return 0;
    }

    // Function to compute XOR of all numbers in range [L, R].

    int findXOR(int L, int R)
    {
                // XOR of a range can be computed with the help of the following observations:
        // XOR of all numbers from 1 to R XOR XOR of all numbers from 1 to L-1 gives XOR of all numbers in range L to R.
        // For example, if L = 3 and R = 6, then XOR of all numbers from 3 to 6 will be XOR(1 to 6) XOR XOR(1 to 2) = 7 XOR 1 = 6.
        return computeXOR(L - 1) ^ computeXOR(R);
    }

/*
TIME COMPLEXITY: O(1), as the operations are performed in constant time.
SPACE COMPLEXITY: O(1), as no additional space is required beyond the input parameters.
*/