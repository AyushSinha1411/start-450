/*
QUESTION:
Write a function to find the longest contiguous subarray containing only 1s that can be obtained by flipping at most k 0s in the given binary array nums.

Example:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation:
[1,1,1,0,0,1,1,1,1,1]
The longest subarray is underlined and its length is 6.

APPROACH:
1. Use the sliding window technique to maintain a window that contains at most k 0s.
2. Initialize two pointers, left and right, to define the window.
3. Iterate through the array with the right pointer.
4. If the element at the right pointer is 0, decrement k.
5. If k becomes negative (more than k 0s in the window), move the left pointer to the right until k is non-negative.
6. Update the maximum length of the window during the iteration.
7. Return the length of the longest window.

CODE:
*/

  int longestOnes(vector<int>& nums, int k) {
         int left = 0;   // Left pointer for the sliding window
    int right = 0;  // Right pointer for the sliding window
    int zeros = 0;  // Count of zeros in the current window
    int maxLen = 0; // Maximum length of the subarray with at most k zeros

    // Iterate over the array with the right pointer
    while (right < nums.size()) {
        // If the current element is zero, increment the zeros count
        if (nums[right] == 0) {
            zeros++;
        }

        // If the count of zeros exceeds k, move the left pointer to maintain the condition
        if (zeros > k) {
            if (nums[left] == 0) {
                zeros--;
            }
            left++;
        }

        // Update the maximum length of the subarray
        if(zeros<=k)
        maxLen = max(maxLen, right - left + 1);
        
        // Move the right pointer to the next element
        right++;
    }

    return maxLen;
    }

/*
TIME COMPLEXITY: O(N), where N is the length of the array. This is because each element is visited at most twice (once by the right pointer and once by the left pointer).
SPACE COMPLEXITY: O(1), as we are using only a few extra variables for calculations.
*/
