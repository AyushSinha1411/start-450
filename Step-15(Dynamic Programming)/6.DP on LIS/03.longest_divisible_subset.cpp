/*
EXAMPLE:
Input: arr = {1, 2, 3, 4, 6, 8, 12, 24}
Output: {1, 2, 4, 8, 24}
Explanation: The longest divisible subset is {1, 2, 4, 8, 24}.

QUESTION:
Given an integer array `arr`, return the longest subset where every pair (i, j) of elements in the subset satisfies:
- `arr[i] % arr[j] == 0` or `arr[j] % arr[i] == 0`.

APPROACH:
1. Sort the array in ascending order.
2. Use a DP array `dp` where `dp[i]` stores the length of the longest divisible subset ending at `arr[i]`.
3. Use a hash array `hash` where `hash[i]` stores the previous index in the longest divisible subset ending at `arr[i]`.
4. Iterate through the array and update the `dp` and `hash` arrays based on the divisibility condition.
5. Find the index of the last element in the longest divisible subset.
6. Reconstruct the subset using the `hash` array.
7. Reverse the subset to get it in the correct order and return it.

CODE:
*/

// Function to find the longest divisible subset
vector<int> divisibleSet(vector<int>& arr) {
    int n = arr.size();

    // Sort the array in ascending order
    sort(arr.begin(), arr.end());

    vector<int> dp(n, 1);   // dp[i] stores the length of the divisible subset ending at arr[i]
    vector<int> hash(n);    // hash[i] stores the previous index in the divisible subset ending at arr[i]

    for (int i = 0; i < n; i++) {
        hash[i] = i; // Initialize with the current index
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (arr[i] % arr[prev_index] == 0 && 1 + dp[prev_index] > dp[i]) {
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
    }

    int ans = -1;
    int lastIndex = -1;

    for (int i = 0; i < n; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);

    // Reconstruct the divisible subset using the hash table
    while (hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    // Reverse the array to get the correct order
    reverse(temp.begin(), temp.end());

    return temp;
}

/*
TIME COMPLEXITY:
- O(n^2), where n is the number of elements in the array. This is due to the nested loops used to update the `dp` and `hash` arrays.

SPACE COMPLEXITY:
- O(n), for the `dp` and `hash` arrays.

EXAMPLE USAGE:
vector<int> arr = {1, 2, 3, 4, 6, 8, 12, 24};
vector<int> result = divisibleSet(arr);
for (int num : result) {
    cout << num << " ";
}
// Output: 1 2 4 8 24
*/
