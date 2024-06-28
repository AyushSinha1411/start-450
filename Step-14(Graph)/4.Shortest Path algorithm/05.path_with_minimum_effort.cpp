/*
QUESTION:
Given a 2D grid of heights, find the minimum effort required to travel from the top-left corner to the bottom-right corner. The effort of a path is defined as the maximum absolute difference in heights between consecutive cells of the path.

APPROACH:
1. Use Dijkstra's algorithm to find the path with the minimum effort.
2. Use a priority queue to always expand the cell with the minimum effort so far.
3. Maintain a distance matrix to keep track of the minimum effort required to reach each cell.
4. Explore all 4 possible directions (up, right, down, left) from each cell.
5. If a shorter path to a neighboring cell is found, update the distance matrix and push the neighbor onto the priority queue.
6. If the bottom-right cell is reached, return the effort associated with it.

CODE:
*/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Create a priority queue containing pairs of cells and their respective
        // distance from the source cell in the form {diff, {row of cell, col of cell}}.
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();

        // Create a distance matrix with initially all the cells marked as unvisited
        // and the dist for source cell (0,0) as 0.
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        // The following delta rows and delta columns arrays are created such that
        // each index represents each adjacent node that a cell may have in a direction.
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Iterate through the matrix by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // Check if we have reached the destination cell,
            // return the current value of difference (which will be minimum).
            if (row == n - 1 && col == m - 1)
                return diff;

            // Explore all 4 possible directions.
            for (int i = 0; i < 4; i++) {
                int newr = row + dr[i];
                int newc = col + dc[i];

                // Checking validity of the cell.
                if (newr >= 0 && newc >= 0 && newr < n && newc < m) {
                    // Effort can be calculated as the max value of differences
                    // between the heights of the node and its adjacent nodes.
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);

                    // If the calculated effort is less than the previous value,
                    // update it as we need the minimum effort.
                    if (newEffort < dist[newr][newc]) {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0; // if unreachable
    }
};

/*
EXAMPLE USAGE:
vector<vector<int>> heights = {
    {1, 2, 2},
    {3, 8, 2},
    {5, 3, 5}
};
Solution sol;
int result = sol.MinimumEffort(heights);
// Output: 2

TIME COMPLEXITY:
- O(n * m * log(n * m)), where n is the number of rows and m is the number of columns.
- Each cell is processed once and we use a priority queue.

SPACE COMPLEXITY:
- O(n * m) for the distance matrix and the priority queue.
*/
