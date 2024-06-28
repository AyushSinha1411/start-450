/*
QUESTION:
Given a matrix of integers, if any element in the matrix is 0, set its entire row and column to 0, and return the modified matrix.

Example:
Input:
matrix = [
  [1, 1, 1],
  [1, 0, 1],
  [1, 1, 1]
]
Output:
The modified matrix is:
[
  [1, 0, 1],
  [0, 0, 0],
  [1, 0, 1]
]

APPROACH:
1. Initialize a variable col0 to keep track of whether the first column should be set to 0 later.
2. Traverse the matrix and mark the first row and column accordingly if any element is 0.
3. Traverse the matrix again (excluding the first row and column) and set the element to 0 if its corresponding row or column is marked as 0.
4. Finally, set the first column to 0 if col0 is 0, and set the first row to 0 if matrix[0][0] is 0.
5. Return the modified matrix.

CODE:
*/

#include <vector>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>>& matrix, int n, int m) {
    int col0 = 1; // Variable to track whether the first column should be set to 0
    // Step 1: Traverse the matrix and mark the first row and column accordingly
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // Mark i-th row
                if (j != 0)
                    matrix[0][j] = 0; // Mark j-th column
                else
                    col0 = 0; // If j == 0, set col0 to 0
            }
        }
    }
    // Step 2: Set elements to 0 based on markings
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0; // Set element to 0 if its corresponding row or column is marked as 0
            }
        }
    }
    // Step 3: Set the first column to 0 if col0 is 0
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    // Set the first row to 0 if col0 is 0
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
    return matrix; // Return the modified matrix
}

/*
TIME COMPLEXITY: O(N * M), where N is the number of rows and M is the number of columns in the matrix.
SPACE COMPLEXITY: O(1), as no extra space is used except for variables.
*/
