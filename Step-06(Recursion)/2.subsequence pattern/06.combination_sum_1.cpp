/*
QUESTION:
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. The same number may be chosen from candidates an unlimited number of times.

Example:
Input: candidates = [2, 3, 6, 7], target = 7
Output: [[2, 2, 3], [7]]
Explanation: 2 and 3 can be used multiple times to sum up to 7. 

APPROACH:
1. Use a recursive function to explore all possible combinations that sum up to the target.
2. At each step, decide whether to include the current element in the combination.
3. If the current element is included, decrease the target by the value of the current element and recurse with the same index (to allow repeated use).
4. If the current element is not included, move to the next element.
5. Add valid combinations to the result.

CODE:
*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive function to find all combinations that sum up to the target
void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
    if (ind == arr.size()) {
        if (target == 0) {
            ans.push_back(ds); // Add the current combination to the result
        }
        return;
    }

    // Include the current element and recurse
    if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }

    // Exclude the current element and move to the next element
    findCombination(ind + 1, target, arr, ans, ds);
}

// Function to return a list of all unique combinations of candidates where the chosen numbers sum to target
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}

/*
TIME COMPLEXITY: O(2^N * K), where N is the number of elements in the array, and K is the average length of the combinations. This is because each element can either be included or excluded, leading to 2^N combinations, and each combination takes O(K) time to process.
SPACE COMPLEXITY: O(K * X), where K is the average length of the combinations, and X is the number of valid combinations. This is because we store all the valid combinations.
*/
