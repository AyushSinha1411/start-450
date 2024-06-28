/*
QUESTION:
Calculate the number of possible subgraphs for a given complete graph with 'n' nodes.

EXAMPLE:
Input: n = 3
Output: 8
Explanation: A complete graph with 3 nodes has 3 edges. Each edge can either be present or absent in a subgraph. Therefore, there are 2^3 = 8 possible subgraphs.

APPROACH:
1. Calculate the total number of edges in a complete graph with 'n' nodes.
2. For each edge, there are two choices: include it in the subgraph or exclude it.
3. The total number of possible subgraphs is 2 raised to the power of the total number of edges.

CODE:
*/

#include <cmath>

long long count(int n) {
    // Calculate the total number of edges in a complete graph with 'n' nodes
    int total_edges = n * (n - 1) / 2;

    // Calculate the number of possible subgraphs
    // Each edge can either be included or excluded in the subgraph
    return 1LL * pow(2, total_edges);
}

/*
EXAMPLE USAGE:
int n = 3;
long long result = count(n); // Returns 8

TIME COMPLEXITY:
- O(1), since the operations of calculating the number of edges and raising 2 to the power of total_edges are constant-time operations.

SPACE COMPLEXITY:
- O(1), since no additional space is used apart from a few variables.
*/
