/*
QUESTION:
Write a function to find the number of non-empty subarrays with a sum equal to a given goal in the binary array nums.

Example:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation:
The subarrays with a sum equal to 2 are [1,0,1], [0,1,0,1], [1,0,1], and [1,0,1].

APPROACH:
1. Use a sliding window to maintain the current sum of elements in the window.
2. Initialize pointers, start and end, to define the window.
3. Iterate through the array with the end pointer, adding elements to the current sum.
4. If the current sum exceeds the goal, slide the start pointer to the right while adjusting the current sum.
5. Use a variable, prefixZeros, to count the number of leading zeros in the current window, which contribute to subarrays with the same sum.
6. Whenever the current sum matches the goal, increment the total count of subarrays by 1 plus the number of prefix zeros.
7. Return the total count of subarrays that meet the goal.

CODE:
*/

#include <vector>
using namespace std;

// Function to find the number of non-empty subarrays with sum equal to the given goal
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int start = 0;
    int prefixZeros = 0;
    int currentSum = 0;
    int totalCount = 0;

    // Loop through the array using end pointer
    for (int end = 0; end < nums.size(); ++end) {
        // Add current element to the sum
        currentSum += nums[end];

        // Slide the window while condition is met
        while (start < end && (nums[start] == 0 || currentSum > goal)) {
            if (nums[start] == 1) {
                prefixZeros = 0;
            } else {
                prefixZeros += 1;
            }

            currentSum -= nums[start];
            start += 1;
        }

        // Count subarrays when window sum matches the goal
        if (currentSum == goal) {
            totalCount += 1 + prefixZeros;
        }
    }

    return totalCount;
}

/*
TIME COMPLEXITY: O(N), where N is the length of the array. This is because each element is visited at most twice (once by the end pointer and once by the start pointer).
SPACE COMPLEXITY: O(1), as we are using only a few extra variables for calculations.
*/
