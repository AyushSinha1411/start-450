/*
QUESTION:
Write a function to find the next smaller element for each element in an array. The next smaller element for an element x is the first smaller element on its right side in the array.

Example:
Input: arr = [4, 5, 2, 10, 8]
Output: [2, 2, -1, 8, -1]
Explanation: The next smaller element for 4 is 2, for 5 is 2, for 2 there isn't any smaller element on right side, for 10 is 8 and for 8 there isn't any smaller element on right side.

APPROACH:
1. Use a stack to keep track of indices of elements.
2. Iterate through the array.
3. For each element, pop indices from the stack while the element at the current index is smaller than the element at the index at the top of the stack.
4. If the stack is not empty, the next smaller element for the element at the popped index is the current element.
5. Push the current index onto the stack.
6. Return the result array containing the next smaller elements.

CODE:
*/

#include <vector>
#include <stack>
using namespace std;

// Function to find the next smaller element for each element in an array
vector<int> findNextSmallerElement(const vector<int>& arr) {
    vector<int> result(arr.size(), -1);  // Result vector initialized with -1
    stack<int> st;  // Stack to keep track of indices

    // Iterate through the array
    for (int i = 0; i < arr.size(); ++i) {
        // Check for the next smaller element
        while (!st.empty() && arr[i] < arr[st.top()]) {
            result[st.top()] = arr[i];  // Set the next smaller element
            st.pop();  // Pop the index from the stack
        }
        st.push(i);  // Push the current index onto the stack
    }

    return result;  // Return the result array
}

/*
TIME COMPLEXITY: O(N), where N is the length of the array. This is because each element is pushed and popped from the stack at most once.
SPACE COMPLEXITY: O(N), for the stack and the result array.
*/
