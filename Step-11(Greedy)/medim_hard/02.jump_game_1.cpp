/*
QUESTION:
Given an array of non-negative integers `nums`, you are initially positioned at the first index of the array. Each element in the array represents your maximum jump length at that position. Determine if you are able to reach the last index.

Example:
Input: nums = [2, 3, 1, 1, 4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

APPROACH:
1. Initialize `lastPos` to the last index of the array.
2. Iterate from the last index to the first index.
3. For each index, check if the index plus the value at that index is greater than or equal to `lastPos`.
4. If true, update `lastPos` to the current index.
5. If after the loop `lastPos` is 0, return true, otherwise return false.

CODE:
*/

#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    // Initialize lastPos to the last index of the array.
    int lastPos = nums.size() - 1;

    // Iterate from the last index to the first index.
    for (int i = nums.size() - 1; i >= 0; i--) {
        // Check if the index plus the value at that index is greater than or equal to lastPos.
        if (i + nums[i] >= lastPos) {
            // If true, update lastPos to the current index.
            lastPos = i;
        }
    }

    // If after the loop lastPos is 0, return true, otherwise return false.
    return lastPos == 0;
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of elements in the `nums` array.
- The function iterates through the array once, making the time complexity linear.

SPACE COMPLEXITY:
- O(1), as we are using a constant amount of extra space.
- The only additional space used is for the `lastPos` variable.
*/
