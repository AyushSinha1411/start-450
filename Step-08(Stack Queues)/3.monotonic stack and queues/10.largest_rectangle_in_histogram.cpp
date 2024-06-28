/*
QUESTION:
Write a function to find the largest rectangle in a histogram. Given an array representing the heights of bars in a histogram, return the area of the largest rectangle that can be formed.

Example:
Input: histo = [2, 1, 5, 6, 2, 3]
Output: 10
Explanation: The largest rectangle can be formed with height 2 and width 5, which gives the area 10.

APPROACH:
1. Use a stack to store the indices of the histogram bars.
2. Iterate through each bar in the histogram.
3. For each bar, pop indices from the stack while the current bar is less than or equal to the bar at the index at the top of the stack.
4. Calculate the area of the rectangle with the popped bar as the smallest (or minimum height) bar.
5. Update the maximum area.
6. Push the current index onto the stack.
7. Return the maximum area.

CODE:
*/

#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Function to find the largest rectangle in a histogram
int largestRectangleArea(vector<int>& histo) {
    stack<int> st; // Stack to store the indices of the histogram bars
    int maxA = 0;  // Initialize the maximum area to 0
    int n = histo.size();

    // Iterate through each bar in the histogram
    for (int i = 0; i <= n; i++) {
        // Pop indices from the stack while the current bar is less than or equal to the bar at the index at the top of the stack
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
            int height = histo[st.top()];
            st.pop();
            int width;
            // If the stack is empty, the width is the current index
            if (st.empty())
                width = i;
            else
                // Otherwise, the width is the difference between the current index and the index at the top of the stack minus one
                width = i - st.top() - 1;
            // Calculate the area of the rectangle with the popped bar as the smallest (or minimum height) bar
            maxA = max(maxA, width * height);
        }
        // Push the current index onto the stack
        st.push(i);
    }

    return maxA; // Return the maximum area
}

/*
TIME COMPLEXITY: O(N), where N is the length of the histogram array. This is because each element is pushed and popped from the stack at most once.
SPACE COMPLEXITY: O(N), for the stack to store the indices of the histogram bars.
*/
