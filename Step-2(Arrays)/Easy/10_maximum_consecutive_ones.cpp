/*
QUESTION:
Find the maximum number of consecutive 1s in a binary array.

Example:
Input:
nums = [1, 1, 0, 1, 1, 1]
Output:
The maximum number of consecutive 1s is: 3

APPROACH:
1. Initialize two variables, cnt and maxi, to 0. The variable cnt will count the current sequence of consecutive 1s, and maxi will store the maximum count found so far.
2. Iterate through the array:
   - If the current element is 1, increment cnt.
   - If the current element is 0, reset cnt to 0.
   - Update maxi with the maximum value between maxi and cnt.
3. Return maxi, which will contain the maximum number of consecutive 1s.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum number of consecutive 1s in a binary array
int findMaxConsecutiveOnes(vector<int>& nums) {
    int cnt = 0; // Initialize count of current consecutive 1s
    int maxi = 0; // Initialize maximum count of consecutive 1s
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) { // If current element is 1
            cnt++; // Increment count of consecutive 1s
        } else { // If current element is 0
            cnt = 0; // Reset count of consecutive 1s
        }
        maxi = max(maxi, cnt); // Update maximum count if current count is greater
    }
    return maxi; // Return the maximum count of consecutive 1s
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(1), as no extra space is used.
*/
