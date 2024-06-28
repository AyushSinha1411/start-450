/*
QUESTION:
Given a 2D board and a word, find if the word exists in the grid. The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:
Input: board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = "ABCCED"
Output: true
Explanation: The word "ABCCED" can be constructed from the letters of sequentially adjacent cells.

APPROACH:
1. Use a recursive function to explore all possible paths to form the word.
2. At each cell, check if the current character matches the corresponding character in the word.
3. Mark the cell as visited by changing its value to a special character.
4. Recurse in all four possible directions (up, down, left, right).
5. Restore the cell's value after exploring all paths from it.

CODE:
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Recursive function to search for the next character in the word
bool searchNext(vector<vector<char>>& board, string word, int row, int col, int index, int m, int n) {
    // If index reaches the end, we have found the word
    if (index == word.length())
        return true;

    // Check boundaries and if the current cell matches the word character
    if (row < 0 || col < 0 || row == m || col == n || board[row][col] != word[index] || board[row][col] == '!')
        return false;

    // Mark the cell as visited
    char c = board[row][col];
    board[row][col] = '!';

    // Explore all four possible directions
    bool top = searchNext(board, word, row - 1, col, index + 1, m, n);
    bool right = searchNext(board, word, row, col + 1, index + 1, m, n);
    bool bottom = searchNext(board, word, row + 1, col, index + 1, m, n);
    bool left = searchNext(board, word, row, col - 1, index + 1, m, n);

    // Restore the cell's value
    board[row][col] = c;

    // Return true if any direction finds the word
    return top || right || bottom || left;
}

// Function to check if the word exists in the board
bool exist(vector<vector<char>> board, string word) {
    int m = board.size();
    int n = board[0].size();

    // Search the first character of the word in the board
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0]) {
                if (searchNext(board, word, i, j, 0, m, n))
                    return true;
            }
        }
    }

    return false;
}

/*
TIME COMPLEXITY: O(M * N * 4^L), where M is the number of rows, N is the number of columns, and L is the length of the word. This is because for each cell, we explore up to 4 directions.
SPACE COMPLEXITY: O(L), due to the recursion stack for the length of the word.
*/
