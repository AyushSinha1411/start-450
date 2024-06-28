/*
QUESTION:
Given an integer n, return all distinct solutions to the n-queens puzzle. Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' indicate a queen and an empty space respectively.

Example:
Input: n = 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.

APPROACH:
1. Use a recursive backtracking approach to generate all possible board configurations.
2. At each step, place a queen in the current column and check if it is safe to place it there.
3. Use three auxiliary arrays to keep track of the attacked positions:
   - `leftrow` to track the rows
   - `upperDiagonal` to track the upper diagonals
   - `lowerDiagonal` to track the lower diagonals
4. If it is safe to place the queen, mark the positions as attacked and recurse to the next column.
5. After exploring all possibilities, unmark the positions (backtrack) and try the next possibility.

CODE:
*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive function to solve the n-queens problem
void solve(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftrow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
            board[row][col] = '.';
            leftrow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

// Function to return all distinct solutions to the n-queens puzzle
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
    return ans;
}

/*
TIME COMPLEXITY: O(N!), where N is the number of queens. This is because there are N! possible arrangements of N queens on an N×N board.
SPACE COMPLEXITY: O(N^2), due to the storage of the board and the recursion stack.
*/
