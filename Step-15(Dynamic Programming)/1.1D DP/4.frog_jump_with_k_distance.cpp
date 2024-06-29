/*
EXAMPLE:
Input: height = [10, 20, 30, 10], k = 2
Output: 20
Explanation: The frog can jump from height[0] to height[2] (cost 20) and then from height[2] to height[3] (cost 0), totaling 20.

QUESTION:
Given an array `height` of n integers where `height[i]` represents the height of the ith step, and an integer `k` representing the maximum number of steps the frog can jump, calculate the minimum energy required for the frog to jump from the first step to the last step. The frog can jump up to k steps at a time.

APPROACH:
1. Use memoization (top-down approach) to store previously computed energy values.
2. Use tabulation (bottom-up approach) to iteratively compute the minimum energy required.

CODE:
*/

class Solution {
private:
  // Function to find the minimum cost to reach the end using at most 'k' jumps
int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k) {
    // Base case: If we are at the beginning (index 0), no cost is needed.
    if (ind == 0) return 0;
    
    // If the result for this index has been previously calculated, return it.
    if (dp[ind] != -1) return dp[ind];
    
    int mmSteps = INT_MAX;
    
    // Loop to try all possible jumps from '1' to 'k'
    for (int j = 1; j <= k; j++) {
        // Ensure that we do not jump beyond the beginning of the array
        if (ind - j >= 0) {
            // Calculate the cost for this jump and update mmSteps with the minimum cost
            int jump = solveUtil(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            mmSteps = min(jump, mmSteps);
        }
    }
    
    // Store the minimum cost for this index in the dp array and return it.
    return dp[ind] = mmSteps;
}
    
public:
  // Function to find the minimum cost to reach the end of the array
int solve(int n, vector<int>& height, int k) {
    vector<int> dp(n, -1); // Initialize a memoization array to store calculated results
    return solveUtil(n - 1, height, dp, k); // Start the recursion from the last index
}
};

// Tabulation (Bottom-Up Approach)
class SolutionTabulation {
public:
// Function to find the minimum cost to reach the end using at most 'k' jumps
int solveUtil(int n, vector<int>& height, vector<int>& dp, int k) {
    dp[0] = 0;

    // Loop through the array to fill in the dp array
    for (int i = 1; i < n; i++) {
        int mmSteps = INT_MAX;

        // Loop to try all possible jumps from '1' to 'k'
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                mmSteps = min(jump, mmSteps);
            }
        }
        dp[i] = mmSteps;
    }
    return dp[n - 1]; // The result is stored in the last element of dp
}

// Function to find the minimum cost to reach the end of the array
int solve(int n, vector<int>& height, int k) {
    vector<int> dp(n, -1); // Initialize a memoization array to store calculated results
    return solveUtil(n, height, dp, k);
}
};

/*
TIME COMPLEXITY:
- Memoization: O(n * k), where n is the number of steps and k is the maximum number of steps the frog can jump. Each step may need to check up to k previous steps.
- Tabulation: O(n * k), as it iterates over each step and checks up to k previous steps.

SPACE COMPLEXITY:
- Memoization: O(n), for the dp array.
- Tabulation: O(n), for the dp array.

EXAMPLE USAGE:
vector<int> height = {10, 20, 30, 10};
int n = height.size();
int k = 2;
Solution solMemo;
int energyMemo = solMemo.minimizeCostMemoization(height, n, k); // Minimum energy using memoization
SolutionTabulation solTab;
int energyTab = solTab.minimizeCostTabulation(height, n, k); // Minimum energy using tabulation
*/
