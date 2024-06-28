/*
QUESTION:
Given an array of integers, return a list of the sums of all possible subsets of the array.

Example:
Input: arr = [1, 2, 3], n = 3
Output: [0, 1, 2, 3, 3, 4, 5, 6]
Explanation: The sums of all subsets are [0, 1, 2, 3, 3, 4, 5, 6].

APPROACH:
1. Use a recursive function to generate all possible subset sums.
2. At each step, decide whether to include the current element in the sum.
3. Add the sum of the current subset to the result when all elements have been considered.
4. Sort the result list before returning it.

CODE:
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive helper function to generate subset sums
void subsetSumsHelper(int ind, vector<int>& arr, int n, vector<int>& ans, int sum) {
    if (ind == n) {
        ans.push_back(sum); // Add the sum of the current subset to the result
        return;
    }
    // Include the current element in the sum and recurse
    subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
    // Exclude the current element from the sum and recurse
    subsetSumsHelper(ind + 1, arr, n, ans, sum);
}

// Function to return a list of the sums of all possible subsets of the array
vector<int> subsetSums(vector<int> arr, int n) {
    vector<int> ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end()); // Sort the result list
    return ans;
}

/*
TIME COMPLEXITY: O(2^N * log(2^N)), where N is the number of elements in the array. This is because there are 2^N possible subsets, and we sort the result list at the end.
SPACE COMPLEXITY: O(2^N), to store all subset sums.
*/
