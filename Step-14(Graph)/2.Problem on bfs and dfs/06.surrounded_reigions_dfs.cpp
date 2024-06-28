/*
QUESTION:
Given a 2D grid of 'O's and 'X's, fill all 'O's that are not on the boundary or not connected to an 'O' on the boundary with 'X'.

EXAMPLE:
Input:
n = 4, m = 4
mat = [
    {'X', 'X', 'X', 'X'},
    {'X', 'O', 'O', 'X'},
    {'X', 'X', 'O', 'X'},
    {'X', 'O', 'X', 'X'}
]
Output:
[
    {'X', 'X', 'X', 'X'},
    {'X', 'X', 'X', 'X'},
    {'X', 'X', 'X', 'X'},
    {'X', 'O', 'X', 'X'}
]

APPROACH:
1. Perform DFS from the boundary 'O's to mark all 'O's connected to the boundary as visited.
2. Traverse through the grid and convert all unvisited 'O's to 'X'.
3. Return the modified grid.

CODE:
*/

#include <vector>
using namespace std;

// Helper function to perform DFS
void dfs(int row, int col, vector<vector<int>> &vis, 
    vector<vector<char>> &mat, int delrow[], int delcol[]) {
    vis[row][col] = 1; 
    int n = mat.size();
    int m = mat[0].size();
    
    // Check for top, right, bottom, left
    for (int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i]; 
        // Check for valid coordinates and unvisited 'O's
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
            dfs(nrow, ncol, vis, mat, delrow, delcol); 
        }
    }
}

public:
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, 1, 0, -1}; 
    vector<vector<int>> vis(n, vector<int>(m, 0)); 

    // Traverse first row and last row
    for (int j = 0; j < m; j++) {
        // Check for unvisited 'O's in the boundary rows
        // First row
        if (!vis[0][j] && mat[0][j] == 'O') {
            dfs(0, j, vis, mat, delrow, delcol); 
        }
        // Last row
        if (!vis[n-1][j] && mat[n-1][j] == 'O') {
            dfs(n-1, j, vis, mat, delrow, delcol); 
        }
    }
    
    for (int i = 0; i < n; i++) {
        // Check for unvisited 'O's in the boundary columns
        // First column
        if (!vis[i][0] && mat[i][0] == 'O') {
            dfs(i, 0, vis, mat, delrow, delcol); 
        }
        // Last column
        if (!vis[i][m-1] && mat[i][m-1] == 'O') {
            dfs(i, m-1, vis, mat, delrow, delcol); 
        }
    }
    
    // If unvisited 'O', then convert to 'X'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && mat[i][j] == 'O') 
                mat[i][j] = 'X'; 
        }
    }
    
    return mat; 
}

/*
EXAMPLE USAGE:
int n = 4, m = 4;
vector<vector<char>> mat = {
    {'X', 'X', 'X', 'X'},
    {'X', 'O', 'O', 'X'},
    {'X', 'X', 'O', 'X'},
    {'X', 'O', 'X', 'X'}
};
vector<vector<char>> result = fill(n, m, mat);
// Output:
// [
//     {'X', 'X', 'X', 'X'},
//     {'X', 'X', 'X', 'X'},
//     {'X', 'X', 'X', 'X'},
//     {'X', 'O', 'X', 'X'}
// ]

TIME COMPLEXITY:
- O(n * m), where n is the number of rows and m is the number of columns. Each cell is processed once.

SPACE COMPLEXITY:
- O(n * m) for the visited matrix and the recursion stack.
*/
