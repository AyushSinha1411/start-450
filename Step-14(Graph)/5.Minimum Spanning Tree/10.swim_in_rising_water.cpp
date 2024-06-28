/*
QUESTION:
Given a grid of size n x n where each cell in the grid has a value representing the height of water, find the minimum time required to swim from the top-left corner to the bottom-right corner. You can swim to adjacent cells (left, right, up, down) and must wait until the water height is less than or equal to the current cell height.

APPROACH:
1. Use a priority queue (min-heap) to process cells in increasing order of their height.
2. Mark cells as visited to avoid processing them multiple times.
3. Use BFS to explore all connected nodes whose height is less than or equal to the current maximum height.
4. Continue processing until the bottom-right corner is reached.

CODE:
*/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
    // Function to check if the given coordinates are within the grid
    bool validPos(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // Visited array to keep track of visited cells
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        // Directions array to move in 4 possible directions
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
        // Priority queue (min-heap) to process cells in increasing order of height
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // Initialize with the starting cell (0, 0)
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        int ans = max(grid[0][0], grid[n-1][n-1]); // Initialize the answer with the max height of the start and end cells
        
        // Process cells until the priority queue is empty
        while (!pq.empty()) {
            vector<int> node = pq.top(); pq.pop();
            int i = node[1], j = node[2];
            ans = max(ans, node[0]); // Update the answer with the current cell's height
            
            // BFS queue to explore all connected nodes whose height <= current max height
            queue<vector<int>> bfsq;
            bfsq.push({i, j});
            
            while (!bfsq.empty()) {
                node = bfsq.front(); bfsq.pop();
                int i = node[0], j = node[1];
                
                for (vector<int>& dir : dirs) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if (validPos(ni, nj, n) && !visited[ni][nj]) {
                        if (ni == n-1 && nj == n-1) return ans; // If we reached the bottom-right corner, return the answer
                        visited[ni][nj] = true; // Mark the neighbor as visited
                        if (grid[ni][nj] <= ans) {
                            bfsq.push({ni, nj}); // Add to BFS queue if height <= current max height
                        } else {
                            pq.push({grid[ni][nj], ni, nj}); // Add to priority queue if height > current max height
                        }
                    }
                }
            }
        }
        
        return ans; // Return the minimum time required to reach the bottom-right corner
    }
};

/*
TIME COMPLEXITY:
- O(N^2 * log(N)), where N is the size of the grid. The priority queue operations dominate the time complexity.

SPACE COMPLEXITY:
- O(N^2), for the visited array and priority queue.

EXAMPLE USAGE:
Solution sol;
vector<vector<int>> grid = {
    {0, 2, 1},
    {1, 3, 2},
    {2, 1, 0}
};
int result = sol.swimInWater(grid);
// result will contain the minimum time required to swim from the top-left to the bottom-right corner.
*/
