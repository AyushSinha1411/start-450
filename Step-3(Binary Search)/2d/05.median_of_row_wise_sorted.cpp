/*
QUESTION:
Given a 2D grid of integers mat, find the median of the matrix. Each row of the matrix is sorted in non-decreasing order.

Example:
Input:
matrix = [
  [1, 3, 5],
  [2, 6, 9],
  [3, 6, 9]
]
Output:
5 // The median of the matrix is 5.

APPROACH:
1. Initialize low to INT_MAX and high to INT_MIN.
2. Adjust low and high to point to the smallest and largest elements in the matrix, respectively.
3. Calculate the required count of elements that should be less than or equal to the median.
4. Perform binary search between low and high to find the median.
5. Use the upperBound function to count the number of elements smaller than or equal to the mid value.
6. Adjust the binary search range based on the count of smaller or equal elements.
7. Return the low value, which represents the median.

CODE:
*/

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Function to find the upper bound of 'x' in the sorted array 'arr'
int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // Check if mid element is greater than 'x'
        if (arr[mid] > x) {
            ans = mid; // Potential answer
            high = mid - 1; // Look for smaller index on the left
        } else {
            low = mid + 1; // Look on the right
        }
    }
    return ans;
}

// Function to count the number of elements less than or equal to 'x' in the matrix
int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += upperBound(matrix[i], x, n);
    }
    return cnt;
}

// Function to find the median of a row-wise sorted matrix
int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;

    // Find the smallest and largest elements in the matrix
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m) / 2; // Calculate the required count of elements less than or equal to the median

    // Perform binary search between low and high to find the median
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req) {
            low = mid + 1; // Move search space to the right
        } else {
            high = mid - 1; // Move search space to the left
        }
    }
    return low; // Return the median
}

/*
TIME COMPLEXITY:
- upperBound: O(log n)
- countSmallEqual: O(m * log n)
- median: O((m + n) * log(max_element - min_element)), where 'm' is the number of rows and 'n' is the number of columns.

SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
