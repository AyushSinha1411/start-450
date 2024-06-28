/*
QUESTION:
Write a function to calculate the sum of the ranges of all subarrays in an array. The range of a subarray is the difference between the maximum and minimum element in the subarray.

Example:
Input: nums = [1, 2, 3]
Output: 4
Explanation: The subarrays are [1], [2], [3], [1, 2], [2, 3], [1, 2, 3]. The ranges are 0, 0, 0, 1, 1, 2. The sum of these ranges is 4.

APPROACH:
1. Use two passes with a stack to calculate the sum of all subarray minimums and maximums.
2. In the first pass, use a stack to find the sum of all subarray minimums and subtract this sum from the answer.
3. In the second pass, use a stack to find the sum of all subarray maximums and add this sum to the answer.
4. The final answer will be the sum of the ranges of all subarrays.

CODE:
*/

#include <vector>
#include <stack>
using namespace std;

// Function to calculate the sum of the ranges of all subarrays
long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    long long answer = 0;
    stack<int> stk;

    // Find the sum of all the minimums
    for (int right = 0; right <= n; ++right) {
        while (!stk.empty() && (right == n || nums[stk.top()] >= nums[right])) {
            int mid = stk.top();
            stk.pop();
            int left = stk.empty() ? -1 : stk.top();
            answer -= (long long)nums[mid] * (right - mid) * (mid - left);
        }
        stk.push(right);
    }

    // Clear the stack for the next pass
    while (!stk.empty()) {
        stk.pop();
    }

    // Find the sum of all the maximums
    for (int right = 0; right <= n; ++right) {
        while (!stk.empty() && (right == n || nums[stk.top()] <= nums[right])) {
            int mid = stk.top();
            stk.pop();
            int left = stk.empty() ? -1 : stk.top();
            answer += (long long)nums[mid] * (right - mid) * (mid - left);
        }
        stk.push(right);
    }
    
    return answer;
}

/*
TIME COMPLEXITY: O(N), where N is the length of the array. This is because each element is pushed and popped from the stack at most once.
SPACE COMPLEXITY: O(N), for the stack to store indices.
*/
