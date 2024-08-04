// Question: Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum equal to goal.
// Example:
// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are [1,0,1], [0,1,0], [1,0,1,0], and [0,1,0].
// Approach:
// We use a helper function 'lessequaltok' to find the number of subarrays with a sum less than or equal to a given value.
// The main function uses this helper to find the number of subarrays with a sum equal to the goal by calculating the difference between the number of subarrays with sum less than or equal to goal and the number of subarrays with sum less than or equal to goal-1.
// Time Complexity: O(n), where n is the length of the array. Each element is visited at most twice.
// Space Complexity: O(1), since we are using a fixed number of extra variables.

#include <vector>
using namespace std;

// Helper function to find the number of subarrays with sum less than or equal to a given value
int lessequaltok(vector<int>& nums, int goal) {
    // If the goal is negative, there are no valid subarrays
    if (goal < 0)
        return 0;

    int l = 0;   // Left pointer for the sliding window
    int r = 0;   // Right pointer for the sliding window
    int ans = 0; // Count of subarrays with sum less than or equal to goal
    int n = nums.size(); // Length of the input array
    int sum = 0; // Current sum of the sliding window

    // Iterate over the array with the right pointer
    while (r < n) {
        sum += nums[r]; // Add the current element to the sum

        // While the sum exceeds the goal, move the left pointer
        while (sum > goal) {
            sum -= nums[l]; // Subtract the element at the left pointer from the sum
            l++; // Move the left pointer to the right
        }

        // Count the number of valid subarrays ending at the current position
        ans += (r - l + 1);
        r++; // Move the right pointer to the next element
    }

    return ans; // Return the count of subarrays with sum less than or equal to goal
}

// Main function to find the number of subarrays with sum equal to goal
int numSubarraysWithSum(vector<int>& nums, int goal) {
    return lessequaltok(nums, goal) - lessequaltok(nums, goal - 1);
}
