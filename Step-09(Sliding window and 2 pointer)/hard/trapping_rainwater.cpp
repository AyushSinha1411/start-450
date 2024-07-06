#include <vector>
using namespace std;

/*
 * Question:
 * Given an array of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 * 
 * Example:
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 */

/*
 * Approach:
 * 1. Use two pointers to traverse the elevation map from both ends towards the center.
 * 2. Initialize two variables, maxLeft and maxRight, to store the maximum height encountered so far from the left and right respectively.
 * 3. Compare the heights at the left and right pointers. 
 *    - If height[left] is less than or equal to height[right], process the left pointer.
 *    - Otherwise, process the right pointer.
 * 4. For the pointer being processed, update the respective maximum height variable (maxLeft or maxRight).
 * 5. Calculate the trapped water at the current pointer as the difference between the maximum height and the current height, and add it to the result.
 * 6. Move the processed pointer (left or right) towards the center.
 * 7. Repeat until the pointers meet.
 */

/*
 * Time Complexity: O(n)
 * The algorithm processes each element exactly once, resulting in a linear time complexity.
 *
 * Space Complexity: O(1)
 * The algorithm uses a constant amount of extra space.
 */

int trap(vector<int> &height) {
    int n = height.size();  // Size of the elevation map
    int left = 0, right = n - 1;  // Initialize two pointers
    int res = 0;  // Variable to store the total trapped water
    int maxLeft = 0, maxRight = 0;  // Variables to store the maximum heights encountered so far

    // Traverse the elevation map from both ends towards the center
    while (left <= right) {
        // Process the left pointer if height[left] is less than or equal to height[right]
        if (height[left] <= height[right]) {
            if (height[left] >= maxLeft) {
                maxLeft = height[left];  // Update the maximum height from the left
            } else {
                res += maxLeft - height[left];  // Calculate the trapped water at the current left pointer
            }
            left++;  // Move the left pointer towards the center
        } else {
            // Process the right pointer
            if (height[right] >= maxRight) {
                maxRight = height[right];  // Update the maximum height from the right
            } else {
                res += maxRight - height[right];  // Calculate the trapped water at the current right pointer
            }
            right--;  // Move the right pointer towards the center
        }
    }

    return res;  // Return the total trapped water
}
