/*
QUESTION:
Given a matrix representing the distances between pairs of nodes in a graph, where -1 represents no direct path between two nodes, implement the Floyd-Warshall algorithm to find the shortest path between all pairs of nodes. Update the matrix in-place.

APPROACH:
1. Initialize the matrix by replacing all -1 values with a large number (representing infinity) except for the diagonal elements, which are set to 0.
2. Use three nested loops to implement the Floyd-Warshall algorithm. The outermost loop iterates through each node as an intermediate node, and the two inner loops iterate through all pairs of nodes to update their shortest distances.
3. After computing the shortest paths, replace all values representing infinity back to -1 to indicate no path exists.

CODE:
*/

#include <vector>
using namespace std;

class Solution {
public:
    void shortest_distance(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Initialize the matrix: replace -1 with a large number and set diagonal to 0.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 1e9;
                }
                if (i == j) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Implement the Floyd-Warshall algorithm to find shortest paths.
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][k] < 1e9 && matrix[k][j] < 1e9) {
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }

        // Convert the large numbers back to -1 to indicate no path exists.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1e9) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};

/*
EXAMPLE USAGE:
Solution sol;
vector<vector<int>> matrix = {
    {0, 3, -1, 7},
    {8, 0, 2, -1},
    {5, -1, 0, 1},
    {2, -1, -1, 0}
};
sol.shortest_distance(matrix);
// After the function call, matrix will be updated to contain the shortest distances.

TIME COMPLEXITY:
- O(n^3), where n is the number of nodes in the graph. The three nested loops each iterate through n elements.

SPACE COMPLEXITY:
- O(1), as the algorithm updates the matrix in place.

The Floyd-Warshall algorithm is used to find the shortest paths between all pairs of nodes in a graph. It works well with graphs containing negative weights, but it cannot handle graphs with negative weight cycles.
*/
