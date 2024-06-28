/*
QUESTION:
Write a function to find the next greater element for each element in a circular array. The next greater element for an element x is the first greater element on its right side in the array. Since the array is circular, the search wraps around the end of the array.

Example:
Input: nums = [1, 2, 1]
Output: [2, -1, 2]
Explanation: The next greater element for 1 is 2. The next greater element for 2 is -1. The next greater element for the second 1 is 2.

APPROACH:
1. Use a stack to keep track of the elements.
2. Iterate through the array from right to left twice (to handle the circular nature).
3. For each element, pop elements from the stack that are less than or equal to the current element.
4. If the stack is not empty, the top element of the stack is the next greater element for the current element.
5. Push the current element onto the stack.
6. Return the result array containing the next greater elements.

CODE:
*/

#include <vector>
#include <stack>
using namespace std;

// Function to find the next greater element for each element in a circular array
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n, -1); // Initialize the result array with -1
    stack<int> st;

    // Iterate through the array from right to left twice
    for (int i = 2 * n - 1; i >= 0; i--) {
        // Pop elements from the stack that are less than or equal to the current element
        while (!st.empty() && st.top() <= nums[i % n]) {
            st.pop();
        }

        // If the index is within the range of the array, set the next greater element
        if (i < n) {
            if (!st.empty()) {
                nge[i] = st.top();
            }
        }

        // Push the current element onto the stack
        st.push(nums[i % n]);
    }

    return nge;
}

/*
TIME COMPLEXITY: O(N), where N is the length of the array. This is because each element is pushed and popped from the stack at most once.
SPACE COMPLEXITY: O(N), for the stack and the result array.
*/
