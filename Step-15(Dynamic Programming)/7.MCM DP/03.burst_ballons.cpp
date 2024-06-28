/*
EXAMPLE:
Input: nums = [3, 1, 5, 8]
Output: 167
Explanation: The optimal order to burst the balloons is [1, 5, 8, 3]. 
The total coins collected are 3*1*5 + 3*5*8 + 3*8*1 + 1*3*1 = 167.

QUESTION:
Given an array of balloons `nums` where each balloon has a number of coins associated with it, you need to burst all the balloons to collect the coins. When you burst a balloon, the coins collected are equal to the product of the balloon's number and the numbers of its adjacent balloons. The goal is to find the maximum coins you can collect by bursting the balloons in an optimal order.

APPROACH:
1. Use a recursive function with memoization to find the maximum coins obtained.
2. Base case: If the start index `i` is greater than the end index `j`, return 0.
3. Use a partitioning loop to divide the problem into smaller subproblems and recursively calculate the coins for each part.
4. Use a DP table to store the results of subproblems and avoid redundant calculations.
5. Return the maximum coins for bursting all the balloons.

CODE:
*/

// Recursive function to calculate the maximum coins obtained
int maxCoinsHelper(int i, int j, vector<int> &nums) {
    if (i > j) return 0;
    int maxCoins = INT_MIN;
    
    // Iterate through each possible balloon to burst last
    for (int k = i; k <= j; k++) {
        // Calculate the coins obtained by bursting the k-th balloon last
        int coins = nums[i - 1] * nums[k] * nums[j + 1];
        
        // Recursively calculate the maximum coins for the remaining balloons
        int remainingCoins = maxCoinsHelper(i, k - 1, nums) + maxCoinsHelper(k + 1, j, nums);
        
        // Update the maximum coins
        maxCoins = max(maxCoins, coins + remainingCoins);
    }
    
    return maxCoins;
}

// Function to calculate the maximum coins obtained
int maxCoins(vector<int> &nums) {
    int n = nums.size();
    
    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    // Call the helper function to compute the maximum coins
    return maxCoinsHelper(1, n, nums);
}
//Time Complexity: Exponential

// memoization function to calculate the maximum coins obtained
int maxCoinsHelper(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int maxCoins = INT_MIN;
    
    // Iterate through each possible balloon to burst last
    for (int k = i; k <= j; k++) {
        // Calculate the coins obtained by bursting the k-th balloon last
        int coins = nums[i - 1] * nums[k] * nums[j + 1];
        
        // Recursively calculate the maximum coins for the remaining balloons
        int remainingCoins = maxCoinsHelper(i, k - 1, nums, dp) + maxCoinsHelper(k + 1, j, nums, dp);
        
        // Update the maximum coins
        maxCoins = max(maxCoins, coins + remainingCoins);
    }
    
    return dp[i][j] = maxCoins;
}

// Function to calculate the maximum coins obtained
int maxCoins(vector<int> &nums) {
    int n = nums.size();
    
    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    // Create a DP array for memoization
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    
    // Call the helper function to compute the maximum coins
    return maxCoinsHelper(1, n, nums, dp);
}

// Function to calculate the maximum coins obtained using tabulation
int maxCoinsTabulation(vector<int> &nums) {
    int n = nums.size();
    
    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    // Create a DP array for memoization
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (i > j) continue;
            int maxi = INT_MIN;
            
            // Iterate through each possible balloon to burst last
            for (int ind = i; ind <= j; ind++) {
                // Calculate the coins obtained by bursting the ind-th balloon last
                int coins = nums[i - 1] * nums[ind] * nums[j + 1];
                
                // Calculate the maximum coins for the remaining balloons
                int remainingCoins = dp[i][ind - 1] + dp[ind + 1][j];
                
                // Update the maximum coins
                maxi = max(maxi, coins + remainingCoins);
            }
            
            dp[i][j] = maxi;
        }
    }
    
    return dp[1][n];
}

/*
TIME COMPLEXITY:
- Recursive approach with memoization: O(n^3), where n is the number of balloons, due to the nested loops and recursive calls.
- Tabulation approach: O(n^3), due to the nested loops for filling the DP table.

SPACE COMPLEXITY:
- Recursive approach with memoization: O(n^2) for the DP table.
- Tabulation approach: O(n^2) for the DP table.

EXAMPLE USAGE:
vector<int> nums = {3, 1, 5, 8};
int resultMemoization = maxCoins(nums);
int resultTabulation = maxCoinsTabulation(nums);
cout << resultMemoization << endl; // Output: 167
cout << resultTabulation << endl; // Output: 167
*/
