/*
EXAMPLE:
Input: mat = [
  [1, 0, 1, 0, 0],
  [1, 0, 1, 1, 1],
  [1, 1, 1, 1, 1],
  [1, 0, 0, 1, 0]
]
Output: 6
Explanation: The maximal rectangle of all 1's has an area of 6.

QUESTION:
Given a binary matrix `mat` of dimensions `n x m`, find the area of the largest rectangle containing only 1's and return its area.

APPROACH:
1. Iterate through each row of the matrix.
2. For each row, update the height of the histogram.
3. Use the `largestRectangleArea` function to find the maximum rectangular area in the histogram.
4. Track and return the maximum area found.

CODE:
*/

// Function to find the largest rectangular area in a histogram.
int largestRectangleArea(vector<int> &histo) {
    stack<int> st;
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}

// Function to find the maximal area of a submatrix of all 1's.
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m) {
    int maxArea = 0;
    vector<int> height(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) height[j]++;
            else height[j] = 0;
        }
        int area = largestRectangleArea(height);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

/*
TIME COMPLEXITY:
- The time complexity of `largestRectangleArea` is O(m) for each row.
- The overall time complexity for `maximalAreaOfSubMatrixOfAll1` is O(n * m).

SPACE COMPLEXITY:
- The space complexity is O(m) for the histogram heights and the stack used in `largestRectangleArea`.

EXAMPLE USAGE:
vector<vector<int>> mat = {
    {1, 0, 1, 0, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0}
};
int result = maximalAreaOfSubMatrixOfAll1(mat, 4, 5);
cout << result << endl; // Output: 6
*/
