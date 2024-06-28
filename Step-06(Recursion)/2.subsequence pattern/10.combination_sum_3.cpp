/*
QUESTION:
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Example:
Input: k = 3, n = 7
Output: [[1, 2, 4]]
Explanation: The only combination of 3 numbers that add up to 7 is [1, 2, 4].

APPROACH:
1. Use a backtracking function to explore all possible combinations.
2. At each step, decide whether to include the current number in the combination.
3. Ensure that the sum of the current combination remains within the target and that the combination has exactly k numbers.
4. Add valid combinations to the result.

CODE:
*/

#include <iostream>
#include <vector>
using namespace std;

// Backtracking function to find all combinations of k numbers that add up to n
void backtrack(int remain, int k, vector<int>& comb, int next_start, vector<vector<int>>& results) {
    if (remain == 0 && comb.size() == k) {
        // If the combination is valid, add it to the results
        results.push_back(comb);
        return;
    } else if (remain < 0 || comb.size() == k) {
        // If the sum exceeds the target or the combination size exceeds k, return
        return;
    }

    // Iterate through the reduced list of candidates
    for (int i = next_start; i < 9; ++i) {
        comb.push_back(i + 1);
        backtrack(remain - i - 1, k, comb, i + 1, results);
        comb.pop_back();
    }
}

// Function to return all possible combinations of k numbers that add up to n
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> results;
    vector<int> comb;

    backtrack(n, k, comb, 0, results);
    return results;
}

/*
TIME COMPLEXITY: O(9^k), where k is the number of elements in the combination. This is because there are at most 9 candidates to choose from, and the depth of recursion is k.
SPACE COMPLEXITY: O(k), due to the recursion stack for processing each combination.
*/
