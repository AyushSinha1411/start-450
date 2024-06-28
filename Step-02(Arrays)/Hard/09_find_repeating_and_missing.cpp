/*
QUESTION:
Given an array 'a' of size n where every element is in the range from 1 to n, find the one repeating and one missing number.

Example:
Input:
a = [3, 1, 3], n = 3
Output:
[3, 2] // 3 is the repeating number and 2 is the missing number

APPROACH:
1. Calculate the sum of first n natural numbers (Sn) and the sum of squares of first n natural numbers (S2n).
2. Calculate the sum (S) and the sum of squares (S2) of elements in the array.
3. Find the difference between Sn and S, and between S2n and S2 to get X - Y and X^2 - Y^2 respectively.
4. Use the equations X + Y = (X^2 - Y^2) / (X - Y) to find the values of X and Y.
5. X is the repeating number and Y is the missing number.

CODE:
*/

#include <vector>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size(); // Size of the array

    // Calculate Sn and S2n
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    // Calculate X - Y and X^2 - Y^2
    long long val1 = S - SN;
    long long val2 = S2 - S2N;

    // Calculate X + Y
    val2 = val2 / val1;

    // Find X and Y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

/*
TIME COMPLEXITY: O(n), where n is the size of the array.
SPACE COMPLEXITY: O(1), as the space used is constant.
*/
