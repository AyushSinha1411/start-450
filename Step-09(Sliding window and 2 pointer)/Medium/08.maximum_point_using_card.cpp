// Question: You have several cards arranged in a row, and each card has an associated point value. 
// The points are represented in an array called `nums`. You can take cards from either the beginning or the end of the row. 
// You have to maximize the total points you can obtain by picking exactly `k` cards.
// Example:
// Input: nums = [1, 2, 3, 4, 5, 6, 1], k = 3
// Output: 12
// Explanation: The optimal way is to take the last 3 cards with values 5, 6, and 1, for a total of 12 points.
// Approach:
// We use a sliding window approach to find the maximum sum of `k` cards taken from either end of the array. 
// First, we calculate the sum of the first `k` cards. Then, we slide the window from the end, removing one card from the beginning 
// and adding one card from the end, keeping track of the maximum sum.
// Time Complexity: O(k), where k is the number of cards to take.
// Space Complexity: O(1), since we are using a fixed number of extra variables.

#include <vector>
#include <algorithm>
using namespace std;

int maxScore(vector<int>& nums, int k) {
    int lSum = 0; // Sum of the first `k` cards
    int nSum = 0; // Sum of the last `k` cards
    int maxSum = 0; // Maximum sum of `k` cards
    int n = nums.size();

    // Calculate the sum of the first `k` cards
    for (int i = 0; i < k; ++i) {
        lSum += nums[i];
    }

    // Initialize maxSum with the sum of the first `k` cards
    maxSum = lSum;

    // Slide the window from the end
    int nIndex = n - 1; // Index to pick cards from the end
    for (int i = k - 1; i >= 0; --i) {
        lSum -= nums[i]; // Remove one card from the beginning
        nSum += nums[nIndex]; // Add one card from the end
        nIndex--;

        // Update maxSum with the maximum value of the current window
        maxSum = max(maxSum, lSum + nSum);
    }

    return maxSum; // Return the maximum sum of `k` cards
}
