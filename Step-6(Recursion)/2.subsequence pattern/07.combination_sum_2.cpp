/*
QUESTION:
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.

Example:
Input: candidates = [10, 1, 2, 7, 6, 1, 5], target = 8
Output: [[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]]
Explanation: All unique combinations that sum up to 8 are returned.

APPROACH:
1. Sort the input array to handle duplicates.
2. Use a recursive function to explore all possible combinations that sum up to the target.
3. At each step, use a for loop to try including each candidate starting from the current index.
4. Skip duplicate elements to ensure unique combinations.
5. Add valid combinations to the result.

CODE:
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive function to find all unique combinations that sum up to the target
void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
    if (target == 0) {
        ans.push_back(ds); // Add the current combination to the result
        return;
    }
    for (int i = ind; i < arr.size(); i++) {
        // Skip duplicates
        if (i > ind && arr[i] == arr[i - 1]) continue;
        // If the current element is greater than the target, break the loop
        if (arr[i] > target) break;
        // Include the current element and recurse
        ds.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}

// Function to return a list of all unique combinations of candidates where the chosen numbers sum to target
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); // Sort the input array to handle duplicates
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}

/*
TIME COMPLEXITY: O(2^N * K), where N is the number of elements in the array, and K is the average length of the combinations. This is because each element can either be included or excluded, leading to 2^N combinations, and each combination takes O(K) time to process.
SPACE COMPLEXITY: O(K * X), where K is the average length of the combinations, and X is the number of valid combinations. This is because we store all the valid combinations.
*/
