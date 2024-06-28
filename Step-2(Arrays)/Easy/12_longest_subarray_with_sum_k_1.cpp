/*
QUESTION:
Find the length of the longest subarray with a sum equal to k.

Example:
Input:
a = [1, 2, 3, 4, 5], k = 9
Output:
The length of the longest subarray is: 3 (subarray [2, 3, 4])

APPROACH:
1. Initialize two pointers, left and right, to 0 to represent the current subarray.
2. Initialize sum to the first element of the array and maxLen to 0 to store the length of the longest subarray found.
3. Iterate through the array using the right pointer:
   - If the sum of the current subarray is greater than k, increment the left pointer to reduce the subarray size until the sum is less than or equal to k.
   - If the sum is equal to k, update maxLen with the maximum length between maxLen and the current subarray length (right - left + 1).
   - Move the right pointer forward and add the new element to the sum.
4. Return maxLen, which contains the length of the longest subarray with a sum equal to k.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest subarray with sum equal to k
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // Size of the array

    int left = 0, right = 0; // Initialize two pointers
    long long sum = a[0]; // Initialize the sum of the current subarray
    int maxLen = 0; // Initialize the maximum length of subarray with sum equal to k

    while (right < n) {
        // If sum is greater than k, reduce the subarray from the left
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // If sum is equal to k, update maxLen
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move the right pointer forward
        right++;
        if (right < n) sum += a[right]; // Add the new element to the sum
    }

    return maxLen; // Return the maximum length of subarray with sum equal to k
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(1), as no extra space is used.
*/
