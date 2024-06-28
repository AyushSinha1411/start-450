/*
QUESTION:
Write a function to solve a Sudoku puzzle by filling the empty cells. A sudoku solution must satisfy all the rules: each of the digits 1-9 must occur exactly once in each row, column, and 3x3 sub-grid.

Example:
Input: board = [
 ['5','3','.','.','7','.','.','.','.'],
 ['6','.','.','1','9','5','.','.','.'],
 ['.','9','8','.','.','.','.','6','.'],
 ['8','.','.','.','6','.','.','.','3'],
 ['4','.','.','8','.','3','.','.','1'],
 ['7','.','.','.','2','.','.','.','6'],
 ['.','6','.','.','.','.','2','8','.'],
 ['.','.','.','4','1','9','.','.','5'],
 ['.','.','.','.','8','.','.','7','9']]
Output: The filled board should be a valid Sudoku solution.

APPROACH:
1. Use a backtracking approach to fill the empty cells ('.') in the Sudoku board.
2. Use a helper function `isValid` to check if placing a digit in a specific cell is valid according to Sudoku rules.
3. Recursively try filling each empty cell with digits from '1' to '9' and backtrack if the current digit placement does not lead to a solution.
4. Return true if a valid solution is found, otherwise backtrack and try other possibilities.

CODE:
*/

#include <iostream>
#include <vector>
using namespace std;

// Helper function to check if placing a digit in a cell is valid according to Sudoku rules
bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c) return false; // Check the column
        if (board[row][i] == c) return false; // Check the row
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false; // Check the 3x3 sub-grid
    }
    return true;
}

// Recursive function to solve the Sudoku puzzle
bool solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == '.') { // Find an empty cell
                for (char c = '1'; c <= '9'; c++) { // Try placing digits from '1' to '9'
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c; // Place the digit
                        if (solveSudoku(board)) return true; // Recur to place the next digit
                        else board[i][j] = '.'; // Backtrack if the placement does not lead to a solution
                    }
                }
                return false; // Return false if no valid digit can be placed in the current cell
            }
        }
    }
    return true; // Return true if the entire board is filled successfully
}

/*
TIME COMPLEXITY: O(9^(N^2)), where N is the size of the board (N=9). This is because each cell can take 9 possible digits.
SPACE COMPLEXITY:  O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.
*/
