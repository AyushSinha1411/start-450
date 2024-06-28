/*
QUESTION:
Write a function to divide two integers without using multiplication, division, or mod operators. Return the quotient after dividing the dividend by the divisor.

Example:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10 divided by 3 is 3 with a remainder of 1.

APPROACH:
1. Determine the sign of the quotient based on the signs of the dividend and divisor.
2. Convert both the dividend and divisor to their absolute values.
3. Use bit manipulation to calculate the quotient.
4. Iterate over the bits of the dividend, starting from the most significant bit.
5. Subtract the shifted divisor from the dividend when the current bit is set.
6. Increment the quotient based on the bit position.
7. Return the quotient with the correct sign.

CODE:
*/

#include <iostream>
#include <cmath>
using namespace std;

int divide(int dividend, int divisor) {
    // Handle overflow case
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    int quotient = 0;
    int sign = 1;

    // Check if the signs are different
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
        sign = -1;
    }

    // Make both dividend and divisor positive
    long long absDividend = abs(dividend);
    long long absDivisor = abs(divisor);

    // Iterate over the bits of the dividend, starting from the most significant bit
    for (int i = 31; i >= 0; i--) {
        // Check if the dividend is greater than or equal to (divisor << i)
        if ((absDividend >> i) >= absDivisor) {
            // Subtract the shifted divisor from the dividend
            absDividend -= (absDivisor << i);
            // Increment the quotient
            quotient |= (1 << i);
        }
    }

    // Return the quotient with the correct sign
    return sign * quotient;
}

/*
TIME COMPLEXITY: O(log N), where N is the absolute value of the dividend. This is because we iterate over the bits of the dividend.
SPACE COMPLEXITY: O(1), as no additional space is required beyond the input parameters.
*/