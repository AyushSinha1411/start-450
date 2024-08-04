/*
QUESTION:
Write a function to find the number of subarrays with exactly k odd numbers in the given array A.

Example:
Input: A = [1, 1, 2, 1, 1], k = 3
Output: 2
Explanation:
The subarrays with exactly 3 odd numbers are [1, 1, 2, 1] and [1, 2, 1, 1].

APPROACH:
1. Use the sliding window technique to maintain a window with exactly k odd numbers.
2. Initialize two pointers, i and j, to define the window.
3. Iterate through the array with the j pointer.
4. If the current element is odd, decrement k and reset the count of valid subarrays ending at j.
5. If k is zero, increment the i pointer until k becomes non-zero, and count the number of valid subarrays.
6. Add the count to the result.
7. Return the total count of valid subarrays.

CODE:
*/

 int numberOfSubarrays(vector<int>& nums, int goal) {
     return lessequaltok(nums, goal) - lessequaltok(nums, goal - 1);
    }
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
        sum += nums[r]%2; // Add the current element to the sum

        // While the sum exceeds the goal, move the left pointer
        while (sum > goal) {
            sum -= nums[l]%2; // Subtract the element at the left pointer from the sum
            l++; // Move the left pointer to the right
        }

        // Count the number of valid subarrays ending at the current position
        ans += (r - l + 1);
        r++; // Move the right pointer to the next element
    }

    return ans; // Return the count of subarrays with sum less than or equal to goal
}


/*
TIME COMPLEXITY: O(N), where N is the length of the array. This is because each element is visited at most twice (once by the j pointer and once by the i pointer).
SPACE COMPLEXITY: O(1), as we are using only a few extra variables for calculations.
*/
