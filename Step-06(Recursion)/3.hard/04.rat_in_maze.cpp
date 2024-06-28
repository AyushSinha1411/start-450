/*
QUESTION:
Given a binary matrix, find all possible paths from the top-left cell to the bottom-right cell. You can only move down, left, right, or up, and you can only move to cells with a value of 1.

Example:
Input: m = [[1, 0, 0, 0], [1, 1, 0, 1], [0, 1, 0, 0], [1, 1, 1, 1]], n = 4
Output: ["DDRDRR", "DRDDRR"]
Explanation: There are two paths from the top-left to the bottom-right of the matrix.

APPROACH:
1. Use a recursive backtracking approach to explore all possible paths.
2. Use a direction array to simplify movement in all four possible directions.
3. Keep track of visited cells to avoid cycles.
4. If the current cell is the bottom-right cell, add the current path to the result.
5. Recur for all valid moves and backtrack to explore other possibilities.

CODE:
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Recursive function to solve the maze problem
void solve(int i, int j, vector<vector<int>>& a, int n, vector<string>& ans, string move, vector<vector<int>>& vis, int di[], int dj[]) {
    // If the bottom-right cell is reached, add the path to the result
    if (i == n - 1 && j == n - 1) {
        ans.push_back(move);
        return;
    }
    string dir = "DLRU"; // Directions: Down, Left, Right, Up
    for (int ind = 0; ind < 4; ind++) {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        // Check if the next move is within bounds, not visited, and valid
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
            vis[i][j] = 1;
            solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
            vis[i][j] = 0; // Backtrack
        }
    }
}

// Function to find all possible paths from the top-left to the bottom-right of the matrix
vector<string> findPath(vector<vector<int>>& m, int n) {
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int di[] = {+1, 0, 0, -1}; // Row direction array
    int dj[] = {0, -1, +1, 0}; // Column direction array
    if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
    return ans;
}

/*
TIME COMPLEXITY: O(4^(N^2)), where N is the size of the matrix. This is because each cell has up to 4 possible directions to explore.
SPACE COMPLEXITY: O(N^2), due to the recursion stack and the visited matrix.
*/
