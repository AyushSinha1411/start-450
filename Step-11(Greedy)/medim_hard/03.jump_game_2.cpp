/*
QUESTION:
Given an array of non-negative integers `nums`, you are initially positioned at the first index of the array. Each element in the array represents your maximum jump length at that position. Your goal is to reach the last index in the minimum number of jumps.

Example:
Input: nums = [2, 3, 1, 1, 4]
Output: 2
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

APPROACH:
1. Initialize the current end of the range (`curEnd`) to 0 and the farthest reachable index (`curFar`) to 0.
2. Iterate through the array. For each index `i`, update the farthest reachable index.
3. If the current index reaches the current end of the range, increment the jump count (`answer`) and update the current end to the farthest reachable index.
4. Return the total number of jumps needed to reach the last index.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

int jump(vector<int>& nums) {
    // Initialize the number of jumps, the current end of the range, and the farthest reachable index.
    int answer = 0, n = int(nums.size());
    int curEnd = 0, curFar = 0;

    // Iterate through the array, excluding the last index because we do not need to jump from there.
    for (int i = 0; i < n - 1; ++i) {
        // Update the farthest reachable index of this jump.
        curFar = max(curFar, i + nums[i]);

        // If we reach the end of the current range,
        // increment the jump count and update the current end to the farthest reachable index.
        if (i == curEnd) {
            answer++;
            curEnd = curFar;
        }
    }

    // Return the total number of jumps needed to reach the last index.
    return answer;
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of elements in the `nums` array.
- The function iterates through the array once, making the time complexity linear.

SPACE COMPLEXITY:
- O(1), as we are using a constant amount of extra space.
- The only additional space used is for the `answer`, `curEnd`, and `curFar` variables.
*/
