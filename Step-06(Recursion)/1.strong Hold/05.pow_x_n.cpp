#include <bits/stdc++.h>
using namespace std;

/*
 * Question:
 * Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
 *
 * Approach:
 * 1. Use a recursive function to divide the problem into smaller subproblems.
 * 2. If n is 0, return 1 (base case).
 * 3. If n is negative, convert the problem to positive exponentiation by taking the reciprocal of x.
 * 4. For positive n, recursively calculate pow(x, n // 2) and square the result.
 * 5. If n is odd, multiply the result by x once more.
 */

double myPowHelper(double x, long long n) {
    // Base case: n is 0
    if (n == 0) return 1.0;
    
    // Recursive step: calculate the power for n // 2
    double half = myPowHelper(x, n / 2);
    
    // If n is even, the result is half * half
    // If n is odd, the result is half * half * x
    return (n % 2 == 0) ? half * half : half * half * x;
}

double myPow(double x, int n) {
    long long N = n;
    // If n is negative, convert the problem to positive exponentiation
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    
    // Start the recursive calculation
    return myPowHelper(x, N);
}
/*
 * Time Complexity:
 * The time complexity is O(log n) because we halve the exponent in each recursive step.
 *
 * Space Complexity:
 * The space complexity is O(log n) due to the recursion stack.
 */
