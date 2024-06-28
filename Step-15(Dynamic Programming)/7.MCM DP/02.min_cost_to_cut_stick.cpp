/*
EXAMPLE:
Input: n = 7, c = 3, cuts = [1, 3, 4]
Output: 16
Explanation: The optimal order of cuts is (1, 4), (3, 4), (1, 3) with a total cost of 16.

QUESTION:
Given a stick of length `n` and an array `cuts` representing the positions to cut the stick, compute the minimum cost of making all the cuts. The cost of a cut is the length of the stick being cut.

APPROACH:
1. Use a recursive function with memoization to find the minimum cost of making all the cuts.
2. Base case: If no cuts are to be made (i > j), the cost is 0.
3. Use a partitioning loop to divide the problem into smaller subproblems and recursively calculate the cost for each part.
4. Use a DP table to store the results of subproblems and avoid redundant calculations.
5. Return the minimum cost for making all the cuts.

CODE:
*/
//Recursive 
// Function to calculate the minimum cost incurred
int findMinimumCost(int i, int j, vector<int> &cuts) {
    // Base case: If i is greater than j, there are no cuts to consider.
    if (i > j) {
        return 0;
    }

    int mini = INT_MAX;

    for (int ind = i; ind <= j; ind++) {
        // Calculate the cost for making a cut at position 'ind'.
        int ans = cuts[j + 1] - cuts[i - 1] +
                  findMinimumCost(i, ind - 1, cuts) +
                  findMinimumCost(ind + 1, j, cuts);

        mini = min(mini, ans);
    }

    return mini;
}

// Function to compute the minimum cost
int minimumCost(int n, int c, vector<int> &cuts) {
    // Modify the cuts array by adding 0 at the beginning and 'n' at the end.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    // Call the recursive function to find the minimum cost.
    return findMinimumCost(1, c, cuts);
}
//Time Complexity: Exponential

//DP
// Function to calculate the minimum cost incurred
int findMinimumCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
    // Base case: If i is greater than j, there are no cuts to consider.
    if (i > j) {
        return 0;
    }

    // Check if the result is already computed
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int mini = INT_MAX;

    for (int ind = i; ind <= j; ind++) {
        // Calculate the cost for making a cut at position 'ind'.
        int ans = cuts[j + 1] - cuts[i - 1] +
                  findMinimumCost(i, ind - 1, cuts, dp) +
                  findMinimumCost(ind + 1, j, cuts, dp);

        mini = min(mini, ans);
    }

    // Store the result in the DP array and return
    return dp[i][j] = mini;
}

// Function to compute the minimum cost
int minimumCost(int n, int c, vector<int> &cuts) {
    // Modify the cuts array by adding 0 at the beginning and 'n' at the end.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    // Create a DP table to store calculated values.
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

    // Call the recursive function to find the minimum cost.
    return findMinimumCost(1, c, cuts, dp);
}

// Function to compute the minimum cost incurred using tabulation
int minimumCostTabulation(int n, int c, vector<int> &cuts) {
    // Modify the cuts array by adding 0 at the beginning and 'n' at the end.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    // Create a DP table to store calculated values.
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--) {
        for (int j = 1; j <= c; j++) {
            if (i > j) continue;

            int mini = INT_MAX;

            for (int ind = i; ind <= j; ind++) {
                // Calculate the cost for making a cut at position 'ind'.
                int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];

                mini = min(mini, ans);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][c];
}

/*
TIME COMPLEXITY:
- Recursive approach: O(c^3), where c is the number of cuts, due to the nested loops and recursive calls.
- Tabulation approach: O(c^3), due to the nested loops for filling the DP table.

SPACE COMPLEXITY:
- Recursive approach: O(c^2) for the DP table.
- Tabulation approach: O(c^2) for the DP table.

EXAMPLE USAGE:
int n = 7;
int c = 3;
vector<int> cuts = {1, 3, 4};
int resultMemoization = minimumCost(n, c, cuts);
int resultTabulation = minimumCostTabulation(n, c, cuts);
cout << resultMemoization << endl; // Output: 16
cout << resultTabulation << endl; // Output: 16
*/
