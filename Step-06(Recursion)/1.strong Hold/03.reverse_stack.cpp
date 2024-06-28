/*
QUESTION:
Write a function to reverse a stack using recursion. You can only use the provided stack operations: push, pop, top, and empty.

Example:
Input: stack = [1, 2, 3, 4, 5]
Output: stack = [5, 4, 3, 2, 1]
Explanation: The stack is reversed using recursion.

APPROACH:
1. Use a recursive function `insert_at_bottom` to insert an element at the bottom of the stack.
2. Use a recursive function `reverse` to reverse the stack by holding all items in the function call stack until the end is reached, and then inserting each item at the bottom.

CODE:
*/

#include <iostream>
#include <stack>
using namespace std;

// Recursive function to insert an element at the bottom of a stack
void insert_at_bottom(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
    } else {
        // Hold all items in the function call stack until we reach the end of the stack
        int a = st.top();
        st.pop();
        insert_at_bottom(st, x);

        // Push all the items held in the function call stack once the item is inserted at the bottom
        st.push(a);
    }
}

// Function to reverse the given stack using insert_at_bottom()
void reverse(stack<int>& st) {
    if (!st.empty()) {
        // Hold all items in the function call stack until we reach the end of the stack
        int x = st.top();
        st.pop();
        reverse(st);

        // Insert all the items held in the function call stack one by one from the bottom to top
        insert_at_bottom(st, x);
    }
}

/*
TIME COMPLEXITY: O(N^2), where N is the number of elements in the stack. This is because for each element, we might need to insert it at the bottom, which takes O(N) time.
SPACE COMPLEXITY: O(N), due to the recursion stack for processing each element.
*/
