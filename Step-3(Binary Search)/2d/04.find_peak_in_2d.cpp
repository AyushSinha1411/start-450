/*
QUESTION:
Given a 2D grid of integers mat, find a peak element and return its coordinates. The peak element is the element that is greater than or equal to all of its adjacent neighbors.

Example:
Input:
mat = [
  [1, 3, 2],
  [4, 5, 6],
  [7, 8, 9]
]
Output:
{2, 2} // The peak element is 9 at coordinates (2, 2).

APPROACH:
1. Initialize the search space to cover the entire matrix.
2. Perform binary search on each column to find the row index of the peak element within that column.
3. Check if the element in the mid column is a peak element by comparing it with its adjacent neighbors.
4. If it's a peak, return its coordinates.
5. Otherwise, adjust the search space by moving towards the direction of the greater neighbor.
6. Repeat until a peak element is found.

CODE:
*/

#include <vector>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int stcol = 0, endcol = mat[0].size() - 1; // Initialize search space

    while (stcol <= endcol) { // Binary search within columns
        int midcol = stcol + (endcol - stcol) / 2;
        int ansrow = 0; // Row index of potential peak in the column

        // Find row index of potential peak in the mid column
        for (int r = 0; r < mat.size(); r++) {
            ansrow = mat[r][midcol] >= mat[ansrow][midcol] ? r : ansrow;
        }

        // Check if potential peak in the mid column is an actual peak
        bool valid_left = midcol - 1 >= stcol && mat[ansrow][midcol - 1] > mat[ansrow][midcol];
        bool valid_right = midcol + 1 <= endcol && mat[ansrow][midcol + 1] > mat[ansrow][midcol];

        // If it's a peak, return its coordinates
        if (!valid_left && !valid_right) {
            return {ansrow, midcol};
        } else if (valid_right)
            stcol = midcol + 1; // Move search space to the right
        else
            endcol = midcol - 1; // Move search space to the left
    }

    return {-1, -1}; // Peak not found
}

/*
TIME COMPLEXITY: O(m * log(n)), where 'm' is the number of rows and 'n' is the number of columns.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
