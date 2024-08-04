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

// Function to find the minimum number of jumps to reach the end of the array
int jump(vector<int>& nums) {
    int n = nums.size(); // Length of the input array
    if (n <= 1) return 0; // No jumps needed if the array has 1 or fewer elements

    int jumps = 0; // Number of jumps
    int l = 0; // Left pointer for the current range
    int r = 0; // Right pointer for the current range

    // While the right pointer has not reached the end of the array
    while (r < n - 1) {
        int farthest = 0; // Farthest point that can be reached in the current range
        // Iterate through the current range to find the farthest point
        for (int i = l; i <= r; i++) {
            farthest = max(farthest, i + nums[i]);
        }
        l = r + 1; // Move the left pointer to the right of the current range
        r = farthest; // Move the right pointer to the farthest point
        jumps++; // Increment the number of jumps
    }

    return jumps; // Return the number of jumps
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of elements in the `nums` array.
- The function iterates through the array once, making the time complexity linear.

SPACE COMPLEXITY:
- O(1), as we are using a constant amount of extra space.
- The only additional space used is for the `answer`, `curEnd`, and `curFar` variables.
*/
