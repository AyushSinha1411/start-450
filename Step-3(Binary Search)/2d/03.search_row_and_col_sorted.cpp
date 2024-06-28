/*
QUESTION:
Given an 'm x n' matrix where each row and column are sorted in ascending order, write an efficient algorithm that searches for a target value in the matrix. Return true if the target exists in the matrix, otherwise return false.

Example:
Input:
matrix = [
  [1, 4, 7, 11],
  [2, 5, 8, 12],
  [3, 6, 9, 16],
  [10, 13, 14, 17]
]
target = 6
Output:
true // The target value 6 exists in the matrix.

APPROACH:
1. Start from the top-right corner of the matrix.
2. If the current element is equal to the target, return true.
3. If the current element is less than the target, move to the next row (downward).
4. If the current element is greater than the target, move to the previous column (leftward).
5. Repeat steps 2-4 until the target is found or until reaching out of bounds.

CODE:
*/

#include <vector>
using namespace std;

bool searchElement(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(); // Number of rows
    int m = matrix[0].size(); // Number of columns
    int row = 0, col = m - 1; // Start from the top-right corner

    // Traverse the matrix
    while (row < n && col >= 0) {
        if (matrix[row][col] == target)
            return true; // Target found
        else if (matrix[row][col] < target)
            row++; // Move to the next row (downward)
        else
            col--; // Move to the previous column (leftward)
    }
    return false; // Target not found
}

/*
TIME COMPLEXITY: O(n + m), where 'n' is the number of rows and 'm' is the number of columns.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
