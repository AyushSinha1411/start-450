/*
QUESTION:
Write a function to find the prime factorization of a given number x using the smallest prime factor (SPF) method. The SPF for every number up to MAXN should be precomputed using a sieve method.

Example:
Input: x = 100
Output: [2, 2, 5, 5]
Explanation: The prime factorization of 100 is 2^2 * 5^2.

APPROACH:
1. Use a sieve method to precompute the smallest prime factor (SPF) for every number up to MAXN.
2. Store the SPF for each number in an array `spf`.
3. Use the precomputed SPF array to find the prime factorization of a given number x.
4. Divide x by its SPF repeatedly to get all prime factors.

CODE:
*/

#include <iostream>
#include <vector>
using namespace std;

#define MAXN 100001
vector<int> spf(MAXN + 1, 1);

// Function to calculate SPF (Smallest Prime Factor) for every number till MAXN
void sieve() {
    spf[0] = 0;
    spf[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) { // if the number is prime
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j] == 1) // if its smallest prime factor is 1
                    spf[j] = i;
            }
        }
    }
}

// Function to return prime factorization of x using SPF
vector<int> getFactorization(int x) {
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

/*
TIME COMPLEXITY:
- Sieve: O(n log log n), where n is MAXN.
- Factorization: O(log n), as we divide x by its smallest prime factor repeatedly.
SPACE COMPLEXITY: O(n), for storing the smallest prime factor for each number up to MAXN.
*/