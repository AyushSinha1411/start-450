#include <bits/stdc++.h>
using namespace std;

/*
 * Question:
 * Find all possible combinations of `k` numbers that add up to a number `n`, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 * Return all possible combinations in a list.
 *
 * Approach:
 * 1. Use a recursive function to explore all possible combinations.
 * 2. Skip duplicates to ensure each combination is unique.
 * 3. Sort the array initially to handle duplicates efficiently.
 */

// Recursive function to generate combinations
void combinationSum3Helper(int ind, int k, int target, vector<int> &combination, vector<vector<int>> &ans) {
    // Base case: if the combination size is k and target is 0, add the combination to the result
    if (combination.size() == k && target == 0) {
        ans.push_back(combination);
        return;
    }
    // If combination size exceeds k or target becomes negative, return
    if (combination.size() > k || target < 0) {
        return;
    }
    
    // Explore combinations starting from the current index
    for (int i = ind; i <= 9; i++) {
        // Include the current number in the combination
        combination.push_back(i);
        // Recurse with the next index, reduced target, and updated combination
        combinationSum3Helper(i + 1, k, target - i, combination, ans);
        // Backtrack: remove the last number added
        combination.pop_back();
    }
}

// Function to return all combinations of k numbers that add up to n
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans; // To store the final combinations
    vector<int> combination; // To store the current combination being built
    combinationSum3Helper(1, k, n, combination, ans); // Start the recursion from number 1
    return ans; // Return the result
}

/*
 * Time Complexity:
 * The time complexity is O(2^n) because each element can either be included or excluded from the combination.
 *
 * Space Complexity:
 * The space complexity is O(k) for storing the current combination and O(2^n) for storing all combinations.
 */
