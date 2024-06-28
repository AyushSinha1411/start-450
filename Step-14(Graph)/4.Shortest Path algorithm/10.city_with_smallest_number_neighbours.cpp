/*
QUESTION:
Given the number of cities (n) and the number of edges (m) with a list of edges representing roads between cities where each road is represented by [city1, city2, distance], find the city with the smallest number of reachable cities within a given distance threshold. If there are multiple cities with the same number of reachable cities, return the city with the greatest index.

APPROACH:
1. Represent the roads as an adjacency matrix where each cell (i, j) contains the distance between city i and city j. Initialize the matrix with INT_MAX to represent unreachable distances.
2. Use the Floyd-Warshall algorithm to find the shortest paths between all pairs of cities.
3. Count the number of cities that are reachable from each city within the given distance threshold.
4. Track the city with the smallest number of reachable cities. If there are multiple cities with the same count, choose the city with the greatest index.

CODE:
*/

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize the distance matrix with INT_MAX
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (auto it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        // Set the distance from each city to itself as 0
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // Apply the Floyd-Warshall algorithm to find shortest paths between all pairs of cities
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Find the city with the smallest number of reachable cities within the distance threshold
        int cntCity = n;
        int cityNo = -1;
        for (int city = 0; city < n; city++) {
            int cnt = 0;
            for (int adjCity = 0; adjCity < n; adjCity++) {
                if (dist[city][adjCity] <= distanceThreshold) {
                    cnt++;
                }
            }

            // Update the city with the smallest number of reachable cities
            // If there are multiple, choose the one with the greatest index
            if (cnt <= cntCity) {
                cntCity = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }
};

/*
EXAMPLE USAGE:
Solution sol;
vector<vector<int>> edges = {
    {0, 1, 3},
    {1, 2, 1},
    {2, 0, 4},
    {0, 3, 2},
    {3, 1, 1}
};
int result = sol.findCity(4, 5, edges, 4);
// Output: 3

TIME COMPLEXITY:
- O(n^3), where n is the number of cities. This complexity is due to the three nested loops used in the Floyd-Warshall algorithm.

SPACE COMPLEXITY:
- O(n^2) for the distance matrix used to store shortest paths between all pairs of cities.
*/
