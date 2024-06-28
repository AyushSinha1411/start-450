/*
QUESTION:
Given a grid of size n * m with binary values (0s and 1s), find the distance of the nearest 1 for each cell in the grid.

EXAMPLE:
Input:
grid = [
    [0, 1, 0],
    [0, 0, 0],
    [1, 0, 0]
]
Output:
[
    [1, 0, 1],
    [1, 1, 2],
    [0, 1, 2]
]

APPROACH:
1. Initialize a queue to perform BFS and a visited matrix to keep track of visited cells.
2. Traverse the grid and for each cell containing 1, mark it as visited and push it into the queue with a distance of 0.
3. Perform BFS and for each cell, update the distance for its neighbors if they are valid and unvisited, then push them into the queue with the updated distance.
4. Continue until the queue is empty and return the distance matrix.

CODE:
*/

#include <vector>
#include <queue>
using namespace std;

// Function to find the distance of nearest 1 in the grid for each cell
vector<vector<int>> nearest(vector<vector<int>> grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    // Visited and distance matrix
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    
    // Queue to store <coordinates, steps>
    queue<pair<pair<int, int>, int>> q;
    
    // Traverse the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Start BFS if cell contains 1
            if (grid[i][j] == 1) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            } else {
                // Mark unvisited
                vis[i][j] = 0;
            }
        }
    }
    
    // Directions for traversing up, right, down, left
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    
    // Traverse till queue becomes empty
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;
        
        // For all 4 neighbors
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            // Check for valid unvisited cell
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }
    
    // Return distance matrix
    return dist;
}

/*
EXAMPLE USAGE:
vector<vector<int>> grid = {
    {0, 1, 0},
    {0, 0, 0},
    {1, 0, 0}
};
vector<vector<int>> result = nearest(grid);
// Output:
// [
//     [1, 0, 1],
//     [1, 1, 2],
//     [0, 1, 2]
// ]

TIME COMPLEXITY:
- O(n * m), where n is the number of rows and m is the number of columns. Each cell is processed once.

SPACE COMPLEXITY:
- O(n * m) for the distance and visited matrices and the queue.
*/
