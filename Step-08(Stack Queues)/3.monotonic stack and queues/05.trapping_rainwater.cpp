/*
QUESTION:
Write a function to calculate the maximum water that can be trapped between the bars in a histogram, given an array of heights of the bars.

Example:
Input: height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Output: 6
Explanation: The above array represents the height of bars in a histogram. The maximum water that can be trapped between the bars is 6 units.

APPROACH:
1. Use a stack to keep track of the indices of the bars.
2. Iterate through each bar in the histogram.
3. For each bar, pop bars from the stack while the current bar is taller than the bar at the index on the top of the stack.
4. Calculate the water trapped above the popped bar using the distance between the current bar and the new top of the stack, and the height difference between the current bar and the popped bar.
5. Add the calculated water to the total water trapped.
6. Push the current index onto the stack.
7. Return the total water trapped.

CODE:
*/

#include <iostream>
#include <stack>
using namespace std;

// Function to return the maximum water that can be stored
int maxWater(int height[], int n) {
    stack<int> st; // Stack to store the indices of the bars
    int ans = 0;   // Stores the final result

    // Loop through each bar
    for (int i = 0; i < n; i++) {
        // Remove bars from the stack while the current bar is taller than the bar at the index on the top of the stack
        while ((!st.empty()) && (height[st.top()] < height[i])) {
            int pop_height = height[st.top()]; // Store the height of the top and pop it
            st.pop();

            // If the stack does not have any bars or the popped bar has no left boundary
            if (st.empty())
                break;

            // Get the distance between the left and right boundary of the popped bar
            int distance = i - st.top() - 1;

            // Calculate the minimum height
            int min_height = min(height[st.top()], height[i]) - pop_height;

            ans += distance * min_height; // Add the trapped water above the popped bar to the total
        }

        // Push the current index onto the stack
        st.push(i);
    }
    return ans; // Return the total water trapped
}

/*
TIME COMPLEXITY: O(N), where N is the number of bars in the histogram. This is because each bar is pushed and popped from the stack at most once.
SPACE COMPLEXITY: O(N), for the stack.
*/
