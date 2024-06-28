/*
QUESTION:
Write a function to print all divisors of a given number n.

Example:
Input: n = 36
Output: 1 36 2 18 3 12 4 9 6
Explanation: The divisors of 36 are 1, 2, 3, 4, 6, 9, 12, 18, and 36.

APPROACH:
1. Iterate from 1 to the square root of n.
2. For each number i, check if it divides n.
3. If i divides n, print i.
4. If i is not equal to n/i, print n/i as well.

CODE:
*/

#include <iostream>
#include <cmath>
using namespace std;

// Function to print all divisors of a given number n
void printDivisors(int n) {
    // Note that this loop runs till square root of n
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal, print only one
            if (n / i == i) {
                cout << " " << i;
            } else { // Otherwise print both
                cout << " " << i << " " << n / i;
            }
        }
    }
}

/*
TIME COMPLEXITY: O(sqrt(N)), where N is the input number. This is because we only iterate up to the square root of n.
SPACE COMPLEXITY: O(1), as no additional space is required beyond the input parameter.
*/
