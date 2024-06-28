/*
QUESTION:
Given an undirected graph and a number m, determine if the graph can be colored with at most m colors such that no two adjacent vertices of the graph are colored with the same color.

Example:
Input: graph = {{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}}, m = 3, N = 4
Output: true
Explanation: It is possible to color the graph using 3 colors such that no two adjacent vertices have the same color.

APPROACH:
1. Use backtracking to try coloring each vertex with one of the m colors.
2. Use a helper function `isSafe` to check if the current color assignment is valid.
3. Recursively assign colors to each vertex and backtrack if a conflict is found.
4. Return true if a valid coloring is found, otherwise return false.

CODE:
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to check if it is safe to color the node with the given color
bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
    for (int k = 0; k < n; k++) {
        if (k != node && graph[k][node] == 1 && color[k] == col) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the m-coloring problem
bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
    if (node == N) {
        return true;
    }

    for (int i = 1; i <= m; i++) {
        if (isSafe(node, color, graph, N, i)) {
            color[node] = i;
            if (solve(node + 1, color, m, N, graph)) return true;
            color[node] = 0;
        }
    }
    return false;
}

// Function to determine if the graph can be colored with at most m colors
bool graphColoring(bool graph[101][101], int m, int N) {
    int color[N] = {0};
    if (solve(0, color, m, N, graph)) return true;
    return false;
}

/*
TIME COMPLEXITY: O(m^N), where N is the number of vertices and m is the number of colors. This is because each vertex can be assigned one of m colors.
SPACE COMPLEXITY: O(N), due to the recursion stack for processing each vertex.
*/
