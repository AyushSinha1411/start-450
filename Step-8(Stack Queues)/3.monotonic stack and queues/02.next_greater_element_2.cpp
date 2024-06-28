/*
QUESTION:
Write a function to find the next greater element for each element in a circular array. The next greater element for an element x is the first greater element on its right side in the array. Since the array is circular, the search wraps around the end of the array.

Example:
Input: A = [1, 2, 1]
Output: [2, -1, 2]
Explanation: The next greater element for 1 is 2. The next greater element for 2 is -1. The next greater element for the second 1 is 2.

APPROACH:
1. Use a stack to keep track of the indices of elements.
2. Iterate through the array twice (to handle the circular nature).
3. For each element, pop indices from the stack where the element at the popped index is less than the current element.
4. If the stack is not empty, the next greater element for the element at the popped index is the current element.
5. Push the current index onto the stack.
6. Return the result array containing the next greater elements.

CODE:
*/

#include <vector>
using namespace std;

// Function to find the next greater element for each element in a circular array
vector<int> nextGreaterElements(vector<int>& A) {
    int n = A.size();
    vector<int> stack, res(n, -1);

    // Iterate through the array twice
    for (int i = 0; i < n * 2; ++i) {
        // Pop indices from the stack where the element at the popped index is less than the current element
        while (stack.size() && A[stack.back()] < A[i % n]) {
            res[stack.back()] = A[i % n];
            stack.pop_back();
        }
        // Push the current index onto the stack
        stack.push_back(i % n);
    }

    return res;
}

/*
TIME COMPLEXITY: O(N), where N is the length of the array. This is because each element is pushed and popped from the stack at most once.
SPACE COMPLEXITY: O(N), for the stack and the result array.
*/
