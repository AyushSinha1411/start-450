/*
QUESTION:
Find the missing number in an array containing numbers from 1 to N with one number missing.

Example:
Input:
a = [1, 2, 4, 5, 6], N = 6
Output:
The missing number in the array is: 3

APPROACH:
1. Calculate the sum of the first N natural numbers using the formula sum = (N * (N + 1)) / 2.
2. Calculate the sum of the elements in the array.
3. The missing number is the difference between the sum of the first N natural numbers and the sum of the array elements.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the missing number in an array
int missingNumber(vector<int>& a, int N) {
    // Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    // Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++) {
        s2 += a[i];
    }

    int missingNum = sum - s2;
    return missingNum;
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(1), as no extra space is used.
*/
