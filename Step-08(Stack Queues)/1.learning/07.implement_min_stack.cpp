/*
QUESTION:
Implement a stack that supports push, pop, top, and retrieving the minimum element in constant time. The stack should support the following operations:
1. push(x) -- Push element x onto stack.
2. pop() -- Removes the element on top of the stack.
3. top() -- Get the top element.
4. getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // Returns -3
minStack.pop();
minStack.top();    // Returns 0
minStack.getMin(); // Returns -2

APPROACH:
1. Use a stack to store the elements.
2. Maintain a variable `mini` to track the minimum element.
3. Use a modified value in the stack to keep track of the minimum element when a new minimum is pushed.
4. Implement the required operations using the stack and the `mini` variable.

CODE:
*/

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<long long> st;
    long long mini;

public:
    /** Initialize your data structure here. */
    MinStack() {
        while (!st.empty()) st.pop();
        mini = INT_MAX;
    }

    void push(int value) {
        long long val = value;
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val < mini) {
                st.push(2 * val - mini);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long el = st.top();
        st.pop();
        if (el < mini) {
            mini = 2 * mini - el;
        }
    }

    int top() {
        if (st.empty()) return -1;
        long long el = st.top();
        if (el < mini) return mini;
        return el;
    }

    int getMin() {
        return mini;
    }
};

/*
TIME COMPLEXITY:
- Push: O(1)
- Pop: O(1)
- Top: O(1)
- GetMin: O(1)

SPACE COMPLEXITY: O(N), where N is the number of elements in the stack.
*/
