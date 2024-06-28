/*
QUESTION:
Given a grid with obstacles where cells can have a value of 0 (obstacle) or 1 (free path), find the shortest path from the source cell to the destination cell. Return the length of the shortest path in terms of the number of cells, or -1 if there is no path.

APPROACH:
1. Use BFS to traverse the grid, starting from the source cell.
2. Use a queue to store the cells to be processed along with their distance from the source.
3. Initialize a distance matrix to keep track of the shortest distance to each cell.
4. Use delta arrays to check the 4 possible directions (up, right, down, left) from each cell.
5. Update the distance for adjacent cells if a shorter path is found and add them to the queue.
6. If the destination cell is reached, return the distance.
7. If the queue is exhausted and the destination is not reached, return -1.

CODE:
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to find the shortest path from source to destination in a grid.
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        // Edge case: if the source is the same as the destination.
        if (source.first == destination.first && source.second == destination.second)
            return 0;

        // Create a queue for BFS, storing cells with their distances from the source.
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();

        // Create a distance matrix, initially all cells marked as unvisited.
        // Set the source cell distance to 0.
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

        // Delta arrays for 4 possible directions: up, right, down, left.
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // BFS traversal.
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Check the 4 possible directions.
            for (int i = 0; i < 4; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                // Check if the new cell is within bounds, is a free path (1), and offers a shorter path.
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc]) {
                    dist[newr][newc] = 1 + dis;

                    // If the destination cell is reached, return the distance.
                    if (newr == destination.first && newc == destination.second)
                        return dis + 1;

                    // Push the new cell into the queue with updated distance.
                    q.push({1 + dis, {newr, newc}});
                }
            }
        }
        // If no path is found from source to destination, return -1.
        return -1;
    }
};

/*
EXAMPLE USAGE:
vector<vector<int>> grid = {
    {1, 0, 0},
    {1, 1, 0},
    {1, 1, 1}
};
pair<int, int> source = {0, 0};
pair<int, int> destination = {2, 2};
Solution sol;
int result = sol.shortestPath(grid, source, destination);
// Output: 4

TIME COMPLEXITY:
- O(n * m), where n is the number of rows and m is the number of columns.
- Each cell is processed once in the worst case.

SPACE COMPLEXITY:
- O(n * m) for the distance matrix and the BFS queue.
*/
