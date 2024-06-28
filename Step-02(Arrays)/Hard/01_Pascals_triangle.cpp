/*
QUESTION:
Given an integer n, generate the first n rows of Pascal's triangle.

Example:
Input:
n = 5
Output:
The Pascal's triangle is:
[
     [1],
    [1, 1],
   [1, 2, 1],
  [1, 3, 3, 1],
 [1, 4, 6, 4, 1]
]

APPROACH:
1. Define a function generateRow to generate each row of Pascal's triangle.
2. Initialize a vector ans to store the entire Pascal's triangle.
3. Iterate through each row from 1 to n and call generateRow to generate the row.
4. Push the generated row into ans.
5. Return ans containing the entire Pascal's triangle.

CODE:
*/

#include <vector>
using namespace std;

vector<int> generateRow(int row) {
    long long ans = 1; // Initialize the answer to 1
    vector<int> ansRow;
    ansRow.push_back(1); // Insert the first element

    // Calculate the rest of the elements
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col); // Calculate numerator
        ans = ans / col; // Calculate denominator
        ansRow.push_back(ans); // Push the element into ansRow
    }
    return ansRow; // Return the generated row
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans; // Vector to store Pascal's triangle

    // Store the entire Pascal's triangle
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row)); // Generate each row and push it into ans
    }
    return ans; // Return the entire Pascal's triangle
}

/*
TIME COMPLEXITY: O(N^2), where N is the number of rows in the Pascal's triangle.
SPACE COMPLEXITY: O(N^2), as extra space is used to store the entire Pascal's triangle.
*/
