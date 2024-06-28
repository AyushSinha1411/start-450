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
    int dp[1000001]; // Array to store computed values
    
    // Helper function to compute minimum energy using recursion and memoization
    int helper(int n, vector<int>& height, int k) {
        if (n == 0) return 0; // Base case: if at the first step, no energy is needed
        
        if (dp[n] != -1) return dp[n]; // Return precomputed value if available
        
        int miniStep = INT_MAX; // Initialize minimum energy
        
        // Try all possible jumps from 1 to k
        for (int i = 1; i <= k; i++) {
            if (n - i >= 0) {
                int jump = helper(n - i, height, k) + abs(height[n] - height[n - i]);
                miniStep = min(miniStep, jump);
            }
        }
        return dp[n] = miniStep; // Store and return the computed minimum energy
    }
    
public:
    // Function to initiate the memoization approach
    int minimizeCostMemoization(vector<int>& height, int n, int k) {
        memset(dp, -1, sizeof(dp)); // Initialize the dp array with -1
        return helper(n - 1, height, k); // Call the helper function starting from the last step
    }
};

// Tabulation (Bottom-Up Approach)
class SolutionTabulation {
public:
    // Function to compute minimum energy using tabulation
    int minimizeCostTabulation(vector<int>& height, int n, int k) {
        vector<int> dp(n, INT_MAX); // Initialize dp array with maximum values
        dp[0] = 0; // No energy needed for the first step
        
        // Iterate over each step
        for (int i = 1; i < n; i++) {
            // Try all possible jumps from 1 to k
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    int jump = dp[i - j] + abs(height[i] - height[i - j]);
                    dp[i] = min(dp[i], jump);
                }
            }
        }
        return dp[n - 1]; // Return the minimum energy required for the last step
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
