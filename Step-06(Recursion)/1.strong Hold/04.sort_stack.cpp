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
*/
#include <bits/stdc++.h>
using namespace std;

// Function to insert an element in a sorted way
void sortedInsert(stack<int>& s, int element) {
    // Base case: If the stack is empty or the top element is smaller than the current element
    if (s.empty() || element > s.top()) {
        s.push(element);
        return;
    }

    // Recursively pop elements until the correct position is found
    int temp = s.top();
    s.pop();
    sortedInsert(s, element);

    // Push the popped element back onto the stack
    s.push(temp);
}

// Function to sort the stack
void sortStack(stack<int>& s) {
    // Base case: If the stack is empty
    if (s.empty()) {
        return;
    }

    // Remove the top element
    int element = s.top();
    s.pop();

    // Recursively sort the remaining stack
    sortStack(s);

    // Insert the top element back in the sorted stack
    sortedInsert(s,element);}

/*
TIME COMPLEXITY: O(N^2), where N is the number of elements in the stack. This is because for each element, we might need to move elements back and forth between the two stacks.
SPACE COMPLEXITY: O(N), as we are using an auxiliary stack to hold the elements temporarily.
*/
