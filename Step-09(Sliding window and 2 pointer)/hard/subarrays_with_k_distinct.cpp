// Question: Given an array of integers nums and an integer k, return the number of subarrays that contain exactly k distinct integers.
// Example:
// Input: nums = [1, 2, 1, 2, 3], k = 2
// Output: 7
// Explanation: The subarrays with exactly 2 distinct integers are [1, 2], [2, 1], [1, 2], [2, 3], [1, 2, 1], [2, 1, 2], and [1, 2, 3].
// Approach:
// We use a helper function to count the number of subarrays with at most k distinct integers. 
// The main function uses this helper to find the number of subarrays with exactly k distinct integers by calculating the difference 
// between the number of subarrays with at most k distinct integers and the number of subarrays with at most k-1 distinct integers.
// Time Complexity: O(n), where n is the length of the array. Each element is visited at most twice.
// Space Complexity: O(k), for storing at most k distinct integers in the hashmap.

#include <vector>
#include <map>
using namespace std;

// Helper function to count the number of subarrays with at most k distinct integers
int helper(vector<int>& nums, int k) {
    int left = 0;  // Left pointer for the sliding window
    int right = 0; // Right pointer for the sliding window
    map<int, int> count; // Hashmap to keep track of the frequency of each integer
    int subarrayCount = 0; // Count of subarrays with at most k distinct integers

    // Iterate over the array with the right pointer
    while (right < nums.size()) {
        count[nums[right]]++; // Increment the frequency of the current integer

        // If the number of distinct integers exceeds k, move the left pointer
        while (count.size() > k) {
            count[nums[left]]--; // Decrement the frequency of the integer at the left pointer
            if (count[nums[left]] == 0) {
                count.erase(nums[left]); // Remove the integer if its frequency becomes 0
            }
            left++; // Move the left pointer to the right
        }

        // Count the number of valid subarrays ending at the current position
        subarrayCount += right - left + 1;
        right++; // Move the right pointer to the next integer
    }

    return subarrayCount; // Return the count of subarrays with at most k distinct integers
}

// Main function to count the number of subarrays with exactly k distinct integers
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return helper(nums, k) - helper(nums, k - 1);
}
