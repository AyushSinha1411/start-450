/*
EXAMPLE:
Input: x = 2.0, n = 10
Output: 1024.0
Explanation: 2.0^10 = 1024.0

QUESTION:
Implement the function `myPow(double x, int n)` that calculates `x` raised to the power `n`.

APPROACH:
1. Initialize `ans` to 1.0 to store the result.
2. Convert `n` to a long long variable `nn` to handle negative values correctly.
3. If `nn` is negative, convert it to positive by multiplying it by -1.
4. Use a while loop to iterate while `nn` is not zero:
   - If `nn` is odd, multiply `ans` by `x` and decrement `nn` by 1.
   - If `nn` is even, square `x` and halve `nn`.
5. If the original `n` is negative, return the reciprocal of `ans`.
6. Return `ans`.

CODE:
*/

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

    if (n < 0) ans = 1.0 / ans;

    return ans;
}

/*
TIME COMPLEXITY:
- The time complexity is O(log n) because in each iteration, the exponent `nn` is halved.

SPACE COMPLEXITY:
- The space complexity is O(1) as we are using a constant amount of extra space.

EXAMPLE USAGE:
double result = myPow(2.0, 10);
cout << result << endl; // Output: 1024.0
*/
