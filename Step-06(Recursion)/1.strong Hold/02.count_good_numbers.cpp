#include <bits/stdc++.h>
using namespace std;

/*
 * Question:
 * You are given a positive integer `n`. Count all possible strings of length `n` that consist of digits 0 to 9 such that the following conditions are true:
 * - If the index is even, the digit must be a prime number (2, 3, 5, 7) or 0.
 * - If the index is odd, the digit must be an odd number.
 *
 * Approach:
 * 1. Use a recursive function to divide the problem into smaller subproblems.
 * 2. If n is 0, return 1 (base case).
 * 3. Calculate the number of valid digits for each position.
 * 4. For even positions, there are 5 choices (2, 4, 6, 8, 0) which are either even or prime.
 * 5. For odd positions, there are 5 choices (1, 3, 5, 7, 9) which are odd numbers.
 * 6. Recursively calculate the count for the remaining positions.
 */

// Define the modulo value
const int MOD = 1e9 + 7;

// Recursive function to compute power
long long power(long long x, long long y) {
    if (y == 0)
        return 1;
    long long p = power(x, y / 2) % MOD;
    p = (p * p) % MOD;
    if (y % 2 == 0)
        return p;
    else
        return (x * p) % MOD;
}

// Main function to count good numbers
long long countGoodNumbers(long long n) {
    long long evenPos = (n + 1) / 2; // Number of even positions
    long long oddPos = n / 2; // Number of odd positions
    return (power(5, evenPos) * power(4, oddPos)) % MOD;
}


/*
 * Time Complexity:
 * The time complexity is O(log n) due to the power function using divide and conquer.
 *
 * Space Complexity:
 * The space complexity is O(log n) due to the recursion stack in the power function.
 */
