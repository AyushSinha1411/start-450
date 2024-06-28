/*
QUESTION:
Write a function to calculate the sum of the minimum value of all subarrays in an array.

Example:
Input: A = [3, 1, 2, 4], n = 4
Output: 17
Explanation:
The subarrays are:
[3] -> minimum is 3
[1] -> minimum is 1
[2] -> minimum is 2
[4] -> minimum is 4
[3, 1] -> minimum is 1
[1, 2] -> minimum is 1
[2, 4] -> minimum is 2
[3, 1, 2] -> minimum is 1
[1, 2, 4] -> minimum is 1
[3, 1, 2, 4] -> minimum is 1
Sum of these minimums is 17.

APPROACH:
1. Use two stacks to keep track of the number of elements greater than or equal to each element on its left and right.
2. Iterate through the array to fill the left array which keeps count of elements strictly greater than the current element.
3. Iterate through the array from right to left to fill the right array which keeps count of elements greater than or equal to the current element.
4. Calculate the sum of the minimum values of all subarrays using the left and right arrays.
5. Return the result.

CODE:
*/

#include <stack>
#include <vector>
using namespace std;

// Function to return required minimum sum
int sumSubarrayMins(int A[], int n) {
    vector<int> left(n), right(n);
    stack<pair<int, int>> s1, s2;

    // Getting number of elements strictly larger than A[i] on the left
    for (int i = 0; i < n; ++i) {
        int cnt = 1;
        // Get elements from stack until element greater than A[i] is found
        while (!s1.empty() && s1.top().first > A[i]) {
            cnt += s1.top().second;
            s1.pop();
        }
        s1.push({A[i], cnt});
        left[i] = cnt;
    }

    // Getting number of elements larger than or equal to A[i] on the right
    for (int i = n - 1; i >= 0; --i) {
        int cnt = 1;
        // Get elements from stack until element greater than or equal to A[i] is found
        while (!s2.empty() && s2.top().first >= A[i]) {
            cnt += s2.top().second;
            s2.pop();
        }
        s2.push({A[i], cnt});
        right[i] = cnt;
    }

    int result = 0;
    // Calculating required result
    for (int i = 0; i < n; ++i) {
        result += A[i] * left[i] * right[i];
    }

    return result;
}

/*
TIME COMPLEXITY: O(N), where N is the length of the array. This is because we iterate through the array multiple times and each stack operation (push/pop) is O(1).
SPACE COMPLEXITY: O(N), for the stacks and the left and right arrays.
*/
