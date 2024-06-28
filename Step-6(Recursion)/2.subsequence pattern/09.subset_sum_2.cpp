/*
QUESTION:
Given an integer array nums that may contain duplicates, return all possible subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.

Example:
Input: nums = [1, 2, 2]
Output: [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]
Explanation: All possible subsets without duplicates are generated.

APPROACH:
1. Use a recursive function to generate all possible subsets.
2. At each step, decide whether to include the current element in the subset.
3. Skip duplicate elements to ensure unique subsets.
4. Add each generated subset to the result.

CODE:
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive function to generate all unique subsets
void findSubsets(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
    ans.push_back(ds); // Add the current subset to the result
    for (int i = ind; i < nums.size(); i++) {
        // Skip duplicate elements
        if (i != ind && nums[i] == nums[i - 1]) continue;
        // Include the current element in the subset and recurse
        ds.push_back(nums[i]);
        findSubsets(i + 1, nums, ds, ans);
        // Exclude the current element from the subset and recurse
        ds.pop_back();
    }
}

// Function to return all unique subsets of the array
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end()); // Sort the array to handle duplicates
    findSubsets(0, nums, ds, ans);
    return ans;
}

/*
TIME COMPLEXITY: O(2^N * N), where N is the number of elements in the array. This is because there are 2^N possible subsets and each subset takes O(N) time to process.
SPACE COMPLEXITY: O(2^N * N), to store all subsets.
*/
