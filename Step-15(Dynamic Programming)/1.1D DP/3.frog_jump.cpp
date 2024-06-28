/*
QUESTION:
Given an array `height` of n integers, where `height[i]` represents the height of the ith step, calculate the minimum energy required for a frog to jump from the first step to the last step. The frog can jump either to the next step or to the step after next.

APPROACH:
1. Use memoization to store previously computed energy values.
2. Use tabulation to iteratively compute the minimum energy required.
3. Use a space-optimized approach to reduce space complexity by only storing the last two values.

CODE:
*/

// Memoization approach
int f(int idx, vector<int>& height, vector<int>& dp) {
    if (idx == 0) {
        return 0;
    }
    if (dp[idx] != -1) {
        return dp[idx];
    }
    int left = abs(height[idx] - height[idx - 1]) + f(idx - 1, height, dp);
    int right = INT_MAX;
    if (idx > 1) {
        right = abs(height[idx] - height[idx - 2]) + f(idx - 2, height, dp);
    }
    return dp[idx] = min(left, right);
}

int minimumEnergyMemoization(vector<int>& height, int n) {
    vector<int> dp(n, -1);
    return f(n - 1, height, dp);
}

// Tabulation approach
int minimumEnergyTabulation(vector<int>& height, int n) {
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int left = dp[i - 1] + abs(height[i] - height[i - 1]);
        int right = INT_MAX;
        if (i > 1) {
            right = dp[i - 2] + abs(height[i] - height[i - 2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}

// Space-optimized approach
int minimumEnergySpaceOptimized(vector<int>& height, int n) {
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++) {
        int left = prev + abs(height[i] - height[i - 1]);
        int right = INT_MAX;
        if (i > 1) {
            right = prev2 + abs(height[i] - height[i - 2]);
        }
        int cur = min(left, right);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}



/*
TIME COMPLEXITY:
- Memoization: O(n), as each step is computed once.
- Tabulation: O(n), as it iterates from 1 to n.
- Space-optimized approach: O(n), as it iterates from 1 to n.

SPACE COMPLEXITY:
- Memoization: O(n), for the dp array.
- Tabulation: O(n), for the dp array.
- Space-optimized approach: O(1), as it uses only a constant amount of space.

EXAMPLE USAGE:
vector<int> height = {10, 20, 30, 10};
int n = height.size();
int energy_memo = minimumEnergyMemoization(height, n); // Minimum energy using memoization
int energy_tab = minimumEnergyTabulation(height, n); // Minimum energy using tabulation
int energy_opt = minimumEnergySpaceOptimized(height, n); // Minimum energy using space optimization
*/
