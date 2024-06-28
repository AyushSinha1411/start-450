/*
EXAMPLE:
Input: arr = {1, 11, 2, 10, 4, 5, 2, 1}
Output: 6
Explanation: The longest bitonic subsequence is {1, 2, 10, 4, 2, 1}, which has length 6.

QUESTION:
Given an array `arr` of size `n`, find the length of the longest bitonic subsequence. A bitonic subsequence is a sequence of numbers that first increases and then decreases.

APPROACH:
1. Define two arrays `dp1` and `dp2` to store the lengths of the longest increasing subsequence ending at each element and the longest decreasing subsequence starting at each element, respectively.
2. Calculate the longest increasing subsequence for each element and store the results in `dp1`.
3. Calculate the longest decreasing subsequence for each element and store the results in `dp2`.
4. Iterate through the array and find the maximum value of `dp1[i] + dp2[i] - 1`, which gives the length of the longest bitonic subsequence.

CODE:
*/

// Function to find the length of the longest bitonic subsequence
int longestBitonicSequence(vector<int>& arr, int n) {
    // Initialize two arrays to store the increasing and decreasing subsequences
    vector<int> dp1(n, 1); // dp1[i] stores the length of the longest increasing subsequence ending at arr[i]
    vector<int> dp2(n, 1); // dp2[i] stores the length of the longest decreasing subsequence starting at arr[i]

    // Calculate the longest increasing subsequence
    for (int i = 0; i < n; i++) {
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (arr[prev_index] < arr[i]) {
                dp1[i] = max(dp1[i], 1 + dp1[prev_index]);
            }
        }
    }

    // Reverse the direction of nested loops to calculate the longest decreasing subsequence
    for (int i = n - 1; i >= 0; i--) {
        for (int prev_index = n - 1; prev_index > i; prev_index--) {
            if (arr[prev_index] < arr[i]) {
                dp2[i] = max(dp2[i], 1 + dp2[prev_index]);
            }
        }
    }

    int maxi = -1;

    // Find the maximum length of the bitonic subsequence
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }

    return maxi;
}

/*
TIME COMPLEXITY:
- O(n^2), where n is the size of the array. This is because we have two nested loops for both increasing and decreasing subsequences, resulting in quadratic time complexity.

SPACE COMPLEXITY:
- O(n), for the two arrays `dp1` and `dp2`.

EXAMPLE USAGE:
vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
int result = longestBitonicSequence(arr, arr.size());
cout << result << endl;
// Output: 6
*/
