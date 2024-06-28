/*
EXAMPLE:
Input: arr = [1, 3, 5, 4, 7]
Output: 2
Explanation: The longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7], both of length 4. Therefore, the number of LIS is 2.

QUESTION:
Given an array `arr`, find the number of longest increasing subsequences (LIS) in the array.

APPROACH:
1. Use dynamic programming to calculate the length of the longest increasing subsequence ending at each element.
2. Use another array to keep track of the count of longest increasing subsequences ending at each element.
3. Traverse the array to update the lengths and counts for each element based on previous elements.
4. Find the maximum length of the LIS.
5. Sum the counts of all subsequences with the maximum length.

CODE:
*/

// Function to find the count of Longest Increasing Subsequences (LIS)
int findNumberOfLIS(vector<int>& arr) {
    int n = arr.size();

    vector<int> dp(n, 1); // dp[i] stores the length of the LIS ending at arr[i]
    vector<int> ct(n, 1); // ct[i] stores the count of LIS ending at arr[i]

    int maxi = 1; // Initialize the maximum length as 1

    for (int i = 0; i < n; i++) {
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (arr[prev_index] < arr[i] && dp[prev_index] + 1 > dp[i]) {
                dp[i] = dp[prev_index] + 1;
                // Inherit count
                ct[i] = ct[prev_index];
            } else if (arr[prev_index] < arr[i] && dp[prev_index] + 1 == dp[i]) {
                // Increase the count
                ct[i] = ct[i] + ct[prev_index];
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int numberOfLIS = 0;

    for (int i = 0; i < n; i++) {
        if (dp[i] == maxi) {
            numberOfLIS += ct[i];
        }
    }

    return numberOfLIS;
}

/*
TIME COMPLEXITY:
- O(n^2), where n is the size of the array. This is due to the nested loops used for updating the lengths and counts of LIS.

SPACE COMPLEXITY:
- O(n), for the arrays `dp` and `ct`.

EXAMPLE USAGE:
vector<int> arr = {1, 3, 5, 4, 7};
int result = findNumberOfLIS(arr);
cout << result << endl;
// Output: 2
*/
