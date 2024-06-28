/*
QUESTION:
Write a function to find the maximal rectangle of 1s in a 2D binary matrix filled with 0s and 1s. Given a matrix, return the area of the largest rectangle containing only 1s.

Example:
Input: matrix = [
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
Explanation: The maximal rectangle is shown in the above matrix as a rectangle of 1s in the third row.

APPROACH:
1. Use a dynamic programming (DP) approach to transform each row of the matrix into a histogram.
2. For each row, update the DP array to keep track of the height of consecutive 1s.
3. Use a stack-based approach to find the largest rectangle in the histogram for each row.
4. Keep track of the maximum area encountered during the process.
5. Return the maximum area.

CODE:
*/

#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Function to find the largest rectangle in a histogram (LeetCode 84 problem)
int leetcode84(vector<int>& heights) {
    vector<int> stack = {-1};
    int maxarea = 0;

    for (int i = 0; i < heights.size(); ++i) {
        while (stack.back() != -1 && heights[stack.back()] >= heights[i]) {
            int height = heights[stack.back()];
            stack.pop_back();
            maxarea = max(maxarea, height * (i - stack.back() - 1));
        }
        stack.push_back(i);
    }

    while (stack.back() != -1) {
        int height = heights[stack.back()];
        stack.pop_back();
        maxarea = max(maxarea, height * (static_cast<int>(heights.size()) - stack.back() - 1));
    }

    return maxarea;
}

// Function to find the maximal rectangle of 1s in a 2D binary matrix
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int maxarea = 0;
    vector<int> dp(matrix[0].size(), 0);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            // Update the state of this row's histogram using the last row's histogram
            dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
        }
        // Update maxarea with the maximum area from this row's histogram
        maxarea = max(maxarea, leetcode84(dp));
    }

    return maxarea;
}

/*
TIME COMPLEXITY: O(N * M), where N is the number of rows and M is the number of columns in the matrix. This is because we iterate through each element of the matrix and use a stack-based approach to find the largest rectangle in the histogram for each row.
SPACE COMPLEXITY: O(M), for the DP array and stack used in the histogram calculation.
*/
