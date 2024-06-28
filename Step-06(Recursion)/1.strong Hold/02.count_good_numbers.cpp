/*
QUESTION:
Given a positive integer n, return the number of good numbers of length n. A good number is defined as a number with even digits (0, 2, 4, 6, 8) at even indices and prime digits (2, 3, 5, 7) at odd indices. The result should be returned modulo 10^9 + 7.

Example:
Input: n = 4
Output: 400
Explanation: 
Even indices can be 0, 2, 4, 6, 8 (5 options) 
Odd indices can be 2, 3, 5, 7 (4 options)
So, the number of good numbers of length 4 is 5^2 * 4^2 = 25 * 16 = 400.

APPROACH:
1. Use modular exponentiation to efficiently compute powers modulo 10^9 + 7.
2. Calculate the number of even and odd indexed positions in the number of length n.
3. Compute the result using the power function to raise the count of possible digits to their respective positions.

CODE:
*/

#include <iostream>
using namespace std;

typedef long long ll;

// Modulo value
int p = 1e9 + 7;

// Function to calculate x^y efficiently modulo p
ll power(long long x, long long y) {
    long long res = 1;    
    x = x % p; // Update x if it is more than or equal to p
    if (x == 0) return 0; 

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) res = (res * x) % p;
        
        // y = y / 2
        y = y >> 1; 
        x = (x * x) % p;
    }
    return res;
}

// Function to count good numbers of length n
int countGoodNumbers(long long n) {
    ll count_of_4s = n / 2;
    ll count_of_5s = n - count_of_4s;
    ll ans = (power(4LL, count_of_4s) % p * power(5LL, count_of_5s) % p) % p;
    return (int)ans;
}

/*
TIME COMPLEXITY: O(log N), where N is the length of the number. This is because the power function uses modular exponentiation which takes logarithmic time.
SPACE COMPLEXITY: O(1), as we are using constant extra space.
*/
