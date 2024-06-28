/*
EXAMPLE:
Input: arr = {2, 3, 2}
Output: 3
Explanation: The houses are arranged in a circular manner. Robbing house 1 and house 3 is not allowed as they are adjacent in a circular arrangement. Thus, the maximum sum we can rob is 3 (from house 2).

QUESTION:
Given an array of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police. The houses are arranged in a circular manner.

APPROACH:
1. Since the houses are in a circular arrangement, we need to handle two scenarios:
   a. Include the first house and exclude the last house.
   b. Exclude the first house and include the last house.
2. Use dynamic programming to solve each scenario.
3. The final result is the maximum of the two scenarios.

CODE:
*/

// Function to solve the maximum sum problem for a linear array
long long int solve(vector<int>& arr) {
    int n = arr.size();
    long long int prev = arr[0];  // Maximum sum including the previous house
    long long int prev2 = 0;      // Maximum sum excluding the previous house

    for (int i = 1; i < n; i++) {
        long long int pick = arr[i];
        if (i > 1) {
            pick += prev2;  // If picking the current house, add the maximum sum excluding the previous house
        }
        long long int nonPick = 0 + prev;  // If not picking the current house, the sum remains the same as the previous house

        long long int cur_i = max(pick, nonPick);  // Choose the maximum of picking or not picking the current house
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}

// Function to find the maximum money that can be robbed from houses arranged in a circular manner
long long int robStreet(int n, vector<int>& arr) {
    vector<int> arr1;  // Scenario 1: Exclude the first house and include the last house
    vector<int> arr2;  // Scenario 2: Include the first house and exclude the last house

    if (n == 1) {
        return arr[0];  // If there's only one house, rob it
    }

    // Fill arr1 and arr2 based on the scenarios
    for (int i = 0; i < n; i++) {
        if (i != 0) arr1.push_back(arr[i]);  // Exclude the first house
        if (i != n - 1) arr2.push_back(arr[i]);  // Exclude the last house
    }

    // Solve both scenarios and take the maximum of the two results
    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);

    return max(ans1, ans2);
}

/*
TIME COMPLEXITY:
- O(n) for both the solve function and the robStreet function, where n is the number of houses. Each house is processed once.

SPACE COMPLEXITY:
- O(n) for the additional vectors arr1 and arr2, and O(1) for the solve function.

EXAMPLE USAGE:
vector<int> arr = {2, 3, 2};
int n = arr.size();
long long int result = robStreet(n, arr);  // Maximum money that can be robbed
*/
