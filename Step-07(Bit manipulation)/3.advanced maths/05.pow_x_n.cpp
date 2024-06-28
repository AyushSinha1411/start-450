/*
QUESTION:
Implement a function to calculate x raised to the power n (x^n).

Example:
Input: x = 2.0, n = 10
Output: 1024.0
Explanation: 2.0^10 = 1024.0

APPROACH:
1. Use a loop to repeatedly square the base and multiply it to the result if the current exponent is odd.
2. Handle negative exponents by taking the reciprocal of the result.
3. Use a long long integer to handle cases where n is INT_MIN.

CODE:
*/

#include <iostream>
using namespace std;

// Function to calculate x raised to the power n (x^n)
double myPow(double x, int n) {
    double ans = 1.0;
    long long nn = n;
    if (nn < 0) nn = -1 * nn;
    while (nn) {
        if (nn % 2) {
            ans = ans * x;
            nn = nn - 1;
        } else {
            x = x * x;
            nn = nn / 2;
        }
    }
    if (n < 0) ans = (double)(1.0) / (double)(ans);
    return ans;
}

/*
TIME COMPLEXITY: O(log N), where N is the exponent. This is because we divide the exponent by 2 in each iteration.
SPACE COMPLEXITY: O(1), as no additional space is required beyond the input parameters.
*/