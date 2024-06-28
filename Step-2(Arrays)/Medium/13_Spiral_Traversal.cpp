/*
QUESTION:
Given a 2D matrix, print the elements of the matrix in spiral order.

Example:
Input:
matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]
Output:
The elements printed in spiral order are: [1, 2, 3, 6, 9, 8, 7, 4, 5]

APPROACH:
1. Initialize an empty vector ans to store the elements printed in spiral order.
2. Initialize four pointers top, bottom, left, and right to keep track of the boundaries of the matrix.
3. Loop until all elements are traversed:
   a. Traverse from left to right for the top row and add elements to ans.
   b. Increment top.
   c. Traverse from top to bottom for the rightmost column and add elements to ans.
   d. Decrement right.
   e. Traverse from right to left for the bottom row if top is less than or equal to bottom, and add elements to ans.
   f. Decrement bottom.
   g. Traverse from bottom to top for the leftmost column if left is less than or equal to right, and add elements to ans.
   h. Increment left.
4. Return ans containing elements printed in spiral order.

CODE:
*/

#include <vector>
using namespace std;

vector<int> printSpiral(vector<vector<int>> mat) {
    vector<int> ans; // Vector to store elements printed in spiral order
    int n = mat.size(); // Number of rows
    int m = mat[0].size(); // Number of columns
    int top = 0, left = 0, bottom = n - 1, right = m - 1; // Pointers for traversal

    // Loop until all elements are traversed
    while (top <= bottom && left <= right) {
        // Traverse from left to right for the top row
        for (int i = left; i <= right; i++)
            ans.push_back(mat[top][i]);
        top++;

        // Traverse from top to bottom for the rightmost column
        for (int i = top; i <= bottom; i++)
            ans.push_back(mat[i][right]);
        right--;

        // Traverse from right to left for the bottom row if top is less than or equal to bottom
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                ans.push_back(mat[bottom][i]);
            bottom--;
        }

        // Traverse from bottom to top for the leftmost column if left is less than or equal to right
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                ans.push_back(mat[i][left]);
            left++;
        }
    }
    return ans; // Return the elements printed in spiral order
}

/*
TIME COMPLEXITY: O(N * M), where N is the number of rows and M is the number of columns in the matrix.
SPACE COMPLEXITY: O(N * M), as extra space is used to store the elements printed in spiral order.
*/
