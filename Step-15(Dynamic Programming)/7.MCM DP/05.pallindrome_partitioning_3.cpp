/*
EXAMPLE:
Input: str = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa", "b"] could be produced using 1 cut.

QUESTION:
Given a string str, partition it such that every substring of the partition is a palindrome. Return the minimum cuts needed for a palindrome partitioning of the string.

APPROACH:
1. Use dynamic programming to solve the problem.
2. Define a helper function `isPalindrome` to check if a substring is a palindrome.
3. Use a recursive function `minPartitions` to find the minimum number of partitions needed.
4. Use memoization to store results of subproblems in a DP array.
5. Iterate through possible partitions and update the minimum cost.
6. Implement an iterative solution with tabulation for better performance.

CODE:
*/

// Function to check if a substring is a palindrome.
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// Recursive function to find the minimum number of partitions to make palindromes.
int minPartitions(int i, int n, string &str) {
    // Base case: If we've reached the end of the string.
    if (i == n) return 0;

    int minCost = INT_MAX;
    // Consider all possible substrings starting from the current index.
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            // If the substring is a palindrome, calculate the cost and minimize it.
            int cost = 1 + minPartitions(j + 1, n, str);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

// Main function to find the minimum number of partitions for palindrome partitioning.
int palindromePartitioning(string str) {
    int n = str.size();
    // Calling the recursive function and subtracting 1 as it counts partitions, not cuts.
    return minPartitions(0, n, str) - 1;
}

//Time Complexity: Exponential

// Memoization to find the minimum number of partitions to make palindromes.
int minPartitions(int i, int n, string &str, vector<int> &dp) {
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];
    int minCost = INT_MAX;
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            int cost = 1 + minPartitions(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}

// Main function to find the minimum number of partitions for palindrome partitioning.
int palindromePartitioning(string str) {
    int n = str.size();
    vector<int> dp(n, -1);
    return minPartitions(0, n, str, dp) - 1;
}

// Function to find the minimum number of partitions for palindrome partitioning using tabulation.
int palindromePartitioningTabulation(string str) {
    int n = str.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        int minCost = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, str)) {
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0] - 1;
}

/*
TIME COMPLEXITY:
- Both approaches: O(n^2), where n is the length of the string, due to the nested loops and palindrome checks.

SPACE COMPLEXITY:
- Recursive approach with memoization: O(n^2) for the dp array and recursion stack.
- Tabulation approach: O(n^2) for the dp array.

EXAMPLE USAGE:
string str = "aab";
int resultMemoization = palindromePartitioning(str); // Using memoization
int resultTabulation = palindromePartitioningTabulation(str); // Using tabulation
cout << resultMemoization << endl; // Output: 1
cout << resultTabulation << endl; // Output: 1
*/
