/*
QUESTION:
Given an 'm x n' matrix where each row is sorted in ascending order and the first integer of each row is greater than the last integer of the previous row. Write an efficient algorithm that searches for a target value in the matrix. Return true if the target exists in the matrix, otherwise return false.

Example:
Input:
matrix = [
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output:
true // The target value 3 exists in the matrix.

APPROACH:
1. Initialize 'low' as 0 and 'high' as 'n x m - 1' where 'n' is the number of rows and 'm' is the number of columns.
2. Apply binary search on the flattened matrix.
3. Convert the index 'mid' to row and column indices.
4. Compare the value at the index with the target:
    - If it matches, return true.
    - If it's less than the target, search in the right half.
    - If it's greater than the target, search in the left half.
5. If the target is not found after the binary search, return false.

CODE:
*/

#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(); // Number of rows
    int m = matrix[0].size(); // Number of columns

    // Apply binary search
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2; // Mid index
        int row = mid / m; // Row index
        int col = mid % m; // Column index
        // Check if the element at mid index is equal to the target
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            low = mid + 1; // Search in the right half
        else
            high = mid - 1; // Search in the left half
    }
    return false; // Target not found
}

/*
TIME COMPLEXITY: O(log(n * m)), where 'n' is the number of rows and 'm' is the number of columns.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
