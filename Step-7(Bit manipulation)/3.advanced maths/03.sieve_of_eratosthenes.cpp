/*
QUESTION:
Write a function to find all prime numbers less than or equal to a given number n using the Sieve of Eratosthenes algorithm.

Example:
Input: n = 30
Output: 2 3 5 7 11 13 17 19 23 29
Explanation: The prime numbers less than or equal to 30 are 2, 3, 5, 7, 11, 13, 17, 19, 23, and 29.

APPROACH:
1. Create a boolean array "prime[0..n]" and initialize all entries as true.
2. A value in prime[i] will finally be false if i is not a prime, else true.
3. Iterate from 2 to the square root of n, marking the multiples of each prime number as false.
4. Print all prime numbers.

CODE:
*/

#include <iostream>
#include <cstring>
using namespace std;

// Function to find all prime numbers less than or equal to n using the Sieve of Eratosthenes algorithm
void SieveOfEratosthenes(int n) {
    // Create a boolean array "prime[0..n]" and initialize all entries as true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or equal to the square of it
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            cout << p << " ";
        }
    }
}

/*
TIME COMPLEXITY: O(n log log n), where n is the input number. This is because the algorithm iterates over the numbers up to n and marks the multiples of each prime.
SPACE COMPLEXITY: O(n), as it requires a boolean array of size n+1.
*/