/*
EXAMPLE:
Input: arr = {10, 9, 2, 5, 3, 7, 101, 18}
Output: 4
Explanation: The LIS is {2, 3, 7, 101}, so the length is 4.

QUESTION:
Given an integer array `arr`, find the length of the longest increasing subsequence (LIS) and print the subsequence.

APPROACH:
1. Use dynamic programming to calculate the length of the LIS.
2. Maintain a `dp` array where `dp[i]` stores the length of the LIS ending at index `i`.
3. Maintain a `hash` array to reconstruct the LIS by storing the previous index of each element in the subsequence.
4. Initialize each element of `dp` to 1 (minimum length of LIS) and `hash` to the index itself.
5. Iterate through the array and update the `dp` and `hash` arrays.
6. Find the maximum value in the `dp` array which gives the length of the LIS.
7. Use the `hash` array to reconstruct the subsequence.
8. Print the subsequence in the correct order.

CODE:
*/

// Function to find the length of the longest increasing subsequence and print the subsequence
int longestIncreasingSubsequence(int arr[], int n){
    vector<int> dp(n, 1);
    vector<int> hash(n, 1);
    
    for (int i = 0; i <= n - 1; i++) {
        hash[i] = i; // initializing with current index
        for (int prev_index = 0; prev_index <= i - 1; prev_index++) {
            if (arr[prev_index] < arr[i] && 1 + dp[prev_index] > dp[i]) {
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
    }
    
    int ans = -1;
    int lastIndex = -1;
    
    for (int i = 0; i <= n - 1; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            lastIndex = i;
        }
    }
    
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    
    while (hash[lastIndex] != lastIndex) { // till not reach the initialization value
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);    
    }
    
    // reverse the array 
    reverse(temp.begin(), temp.end());
    
    cout << "The subsequence elements are: ";
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
    
    return ans;
}

/*
TIME COMPLEXITY:
- O(n^2), where n is the number of elements in the array. Each state in the DP array is computed at most once.

SPACE COMPLEXITY:
- O(n), for the dp and hash arrays.

EXAMPLE USAGE:
int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
int n = sizeof(arr) / sizeof(arr[0]);
int result = longestIncreasingSubsequence(arr, n);
cout << "Length of LIS: " << result << endl; // Output: Length of LIS: 4
*/
