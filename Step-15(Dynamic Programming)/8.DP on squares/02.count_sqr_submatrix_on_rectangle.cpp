/*
EXAMPLE:
Input: n = 4, m = 5, arr = [
  [0, 1, 1, 1, 0],
  [1, 1, 1, 1, 0],
  [0, 1, 1, 1, 1],
  [1, 1, 1, 1, 0]
]
Output: 15
Explanation: The matrix contains 15 square submatrices with all 1's.

QUESTION:
Given a binary matrix `arr` of dimensions `n x m`, count the number of square submatrices that have all 1's.

APPROACH:
1. Initialize a DP array `dp` of the same dimensions as `arr`.
2. Copy the first row and first column of `arr` to `dp` as they represent single-element squares.
3. For each cell in the matrix starting from (1,1), if the cell contains 1, update the `dp` cell with the minimum value from the top, left, and top-left diagonal cells plus one.
4. Sum all the values in the `dp` matrix to get the total count of square submatrices.

CODE:
*/

int countSquares(int n, int m, vector<vector<int>> &arr) {
    // Create a DP array to store the size of the largest square submatrix ending at each cell.
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initialize the first row and first column of the DP array.
    for (int j = 0; j < m; j++) dp[0][j] = arr[0][j];
    for (int i = 0; i < n; i++) dp[i][0] = arr[i][0];

    // Fill in the DP array.
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j],
                                   min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
    }

    // Sum all values in the DP array to get the total count of square submatrices.
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += dp[i][j];
        }
    }
    return sum;
}

/*
TIME COMPLEXITY:
- The time complexity is O(n * m) as we iterate through each cell of the matrix.

SPACE COMPLEXITY:
- The space complexity is O(n * m) for the DP array.

EXAMPLE USAGE:
vector<vector<int>> mat = {
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 0},
    {0, 1, 1, 1, 1},
    {1, 1, 1, 1, 0}
};
int result = countSquares(4, 5, mat);
cout << result << endl; // Output: 15
*/
