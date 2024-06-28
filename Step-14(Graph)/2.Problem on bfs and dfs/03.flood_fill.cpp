/*
QUESTION:
Given an image represented by a 2D array, where each element represents a pixel's color, perform a flood fill operation starting from a given pixel (sr, sc) with a new color. The flood fill operation changes the color of the starting pixel and all connected pixels of the same initial color to the new color.

EXAMPLE:
Input:
image = {
    {1, 1, 1},
    {1, 1, 0},
    {1, 0, 1}
}
sr = 1, sc = 1, newColor = 2

Output:
{
    {2, 2, 2},
    {2, 2, 0},
    {2, 0, 1}
}

APPROACH:
1. Use Depth First Search (DFS) to traverse the image starting from the given pixel (sr, sc).
2. Change the color of the current pixel to the new color.
3. Recursively apply the same operation to the neighboring pixels (up, down, left, right) if they have the same initial color and have not been visited yet.

CODE:
*/

#include <vector>
using namespace std;

// Helper function to perform DFS
void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newColor, int delRow[], int delCol[], int iniColor) {
    // Color the current pixel with the new color
    ans[row][col] = newColor; 
    int n = image.size();   // Number of rows
    int m = image[0].size(); // Number of columns
    
    // Traverse 4 neighbors (up, right, down, left)
    for (int i = 0; i < 4; i++) {
        int nrow = row + delRow[i]; 
        int ncol = col + delCol[i]; 
        // Check for valid coordinates, same initial color, and unvisited pixel
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
            dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor); 
        }
    }
}

// Main function to perform flood fill
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    // Get initial color of the starting pixel
    int iniColor = image[sr][sc]; 
    vector<vector<int>> ans = image; 
    // Arrays to store row and column deltas for 4 neighbors
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1}; 
    // Start DFS from the given pixel
    dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor); 
    return ans; 
}

/*
EXAMPLE USAGE:
vector<vector<int>> image = {
    {1, 1, 1},
    {1, 1, 0},
    {1, 0, 1}
};
int sr = 1, sc = 1, newColor = 2;
vector<vector<int>> result = floodFill(image, sr, sc, newColor); 
// Output: 
// {
//     {2, 2, 2},
//     {2, 2, 0},
//     {2, 0, 1}
// }

TIME COMPLEXITY:
- O(N * M), where N is the number of rows and M is the number of columns in the image. Each pixel is visited once.

SPACE COMPLEXITY:
- O(N * M) in the worst case due to the recursion stack in DFS.
*/
