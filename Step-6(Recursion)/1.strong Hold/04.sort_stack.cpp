/*
QUESTION:
Given a stack of integers, sort the stack in ascending order using only one additional stack. The sorted elements should remain in the original stack.

Example:
Input: stack = [34, 3, 31, 98, 92, 23]
Output: stack = [3, 23, 31, 34, 92, 98]
Explanation: The elements are sorted in ascending order.

APPROACH:
1. Use recursion to sort the stack.
2. Remove the top element of the stack and sort the remaining elements.
3. Use an auxiliary stack to temporarily hold elements while inserting the removed element back in the correct position.
4. Move the elements from the auxiliary stack back to the main stack.

CODE:
*/

#include <iostream>
#include <stack>
using namespace std;

// Function to sort a stack
void sortStack(stack<int> &s) {
    // If the stack is empty, return
    if (s.empty())
        return;
     
    // Remove the top element of the stack
    int x = s.top();
    s.pop();
     
    // Sort the remaining elements in the stack using recursion
    sortStack(s);
     
    // Create an auxiliary stack
    stack<int> tempStack;
     
    // Move all elements that are greater than x from the main stack to the tempStack
    while (!s.empty() && s.top() > x) {
        tempStack.push(s.top());
        s.pop();
    }
     
    // Push x back into the main stack
    s.push(x);
     
    // Move all elements from tempStack back to the main stack
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

/*
TIME COMPLEXITY: O(N^2), where N is the number of elements in the stack. This is because for each element, we might need to move elements back and forth between the two stacks.
SPACE COMPLEXITY: O(N), as we are using an auxiliary stack to hold the elements temporarily.
*/
