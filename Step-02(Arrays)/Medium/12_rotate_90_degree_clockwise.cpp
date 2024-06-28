/*
QUESTION:
Given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

Example:
Input:
matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]
Output:
The rotated matrix is:
[
  [7, 4, 1],
  [8, 5, 2],
  [9, 6, 3]
]

APPROACH:
1. Transpose the matrix by swapping matrix[i][j] with matrix[j][i] for all valid indices i and j.
2. Reverse each row of the transposed matrix.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size(); // Size of the matrix
    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]); // Swap matrix[i][j] with matrix[j][i]
        }
    }
    // Step 2: Reverse each row of the transposed matrix
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end()); // Reverse the row
    }
}

/*
TIME COMPLEXITY: O(N^2), where N is the number of rows or columns in the matrix.
SPACE COMPLEXITY: O(1), as no extra space is used except for variables.
*/
