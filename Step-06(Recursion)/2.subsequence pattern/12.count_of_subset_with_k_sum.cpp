/*
QUESTION:
Given an array of integers and a sum, count the number of subsets that add up to the given sum. The result should be returned modulo 10^9 + 7.

Example:
Input: arr = [1, 2, 3, 4], sum = 5
Output: 3
Explanation: The subsets that add up to 5 are [1, 4], [2, 3], and [1, 2, 2].

APPROACH:
1. Use a recursive function to count the number of subsets that add up to the given sum.
2. At each step, decide whether to include the current element in the subset or not.
3. Use modulo operation to prevent overflow.
4. Return the total count of such subsets.

CODE:
*/

#include <iostream>
using namespace std;

int mod = (int)(1e9 + 7); // Initialize mod value for calculations
int N; // Size of the array

// Recursive function to count the number of subsets that add up to the given sum
int fun(int pos, int sum, int arr[]) {
    if (pos >= N)
        return sum == 0; // Check if sum is zero when array position reaches end

    int ans = 0; // Initialize answer with zero

    // Recursively call function for next position with sum unchanged
    ans += fun(pos + 1, sum, arr);
    ans %= mod; // Take modulo of the answer to avoid overflow

    // Recursively call function for next position with reduced sum
    if (arr[pos] <= sum)
        ans += fun(pos + 1, sum - arr[pos], arr);
        ans %= mod;

    return ans; // Return the calculated answer
}

// Function to count the number of subsets that add up to the given sum
int perfectSum(int arr[], int n, int sum) {
    N = n; // Assign n to N variable

    return fun(0, sum, arr); // Call recursive function with initial parameters
}

/*
TIME COMPLEXITY: O(2^N), where N is the size of the array. This is because each element can either be included or excluded from the subset.
SPACE COMPLEXITY: O(N), due to the recursion stack for processing each element in the array.
*/
