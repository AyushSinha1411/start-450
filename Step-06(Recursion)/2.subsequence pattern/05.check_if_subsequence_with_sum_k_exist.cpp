/*
QUESTION:
Given an array of integers and a target sum, determine if there exists a subsequence of the array that adds up to the target sum.

Example:
Input: arr = [1, 2, 3, 4], k = 5
Output: true
Explanation: There exists a subsequence [1, 4] or [2, 3] that adds up to 5.

APPROACH:
1. Use a recursive function to check if there exists a subsequence that adds up to the target sum.
2. At each step, decide whether to include the current element in the sum or not.
3. Return true if any combination matches the target sum, otherwise return false.

CODE:
*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive function to check if there exists a subsequence that adds up to the target sum
bool solve(vector<int> &arr, int index, int sum, int s) {
    if (index == arr.size()) {
        return (s == sum); // Check if the current sum equals the target sum
    }

    if (sum > s) {
        return false; // If the current sum exceeds the target sum, return false
    }

    // Include the current element in the sum and recurse
    sum += arr[index];
    if (solve(arr, index + 1, sum, s)) return true;
    
    // Exclude the current element from the sum and recurse
    sum -= arr[index];
    if (solve(arr, index + 1, sum, s)) return true;

    return false;
}

// Function to determine if there exists a subsequence that adds up to the target sum
bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
    return solve(arr, 0, 0, k); // Call recursive function with initial parameters
}

/*
TIME COMPLEXITY: O(2^N), where N is the size of the array. This is because each element can either be included or excluded from the subset.
SPACE COMPLEXITY: O(N), due to the recursion stack for processing each element in the array.
*/
