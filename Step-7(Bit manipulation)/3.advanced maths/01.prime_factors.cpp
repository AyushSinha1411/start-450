/*
QUESTION:
Write a function to print all prime factors of a given number n.

Example:
Input: n = 315
Output: 3 3 5 7
Explanation: The prime factors of 315 are 3, 3, 5, and 7.

APPROACH:
1. Print the number of 2s that divide n.
2. For odd factors, start from 3 and check each odd number up to the square root of n.
3. For each odd number, print it and divide n as long as it divides n.
4. If n is a prime number greater than 2 at the end, print n.

CODE:
*/

#include <iostream>
#include <cmath>
using namespace std;

// Function to print all prime factors of a given number n
void primeFactors(int n) {
    // Print the number of 2s that divide n
    while (n % 2 == 0) {
        cout << 2 << " ";
        n = n / 2;
    }

    // n must be odd at this point. So we can skip one element (Note i = i + 2)
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }

    // This condition is to handle the case when n is a prime number greater than 2
    if (n > 2) {
        cout << n << " ";
    }
}

/*
TIME COMPLEXITY: O(sqrt(N)), where N is the input number. This is because we only check up to the square root of n for factors.
SPACE COMPLEXITY: O(1), as no additional space is required beyond the input parameter.
*/