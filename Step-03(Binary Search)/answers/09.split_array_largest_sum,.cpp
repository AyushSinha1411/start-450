/*
QUESTION:
You are given an array 'a' of integers and an integer 'k'. You need to find the largest possible sum of a non-empty subarray such that the number of elements in the subarray is at most 'k'.

Example:
Input:
a = [1, 2, 3, 4], k = 3
Output:
6 // The largest possible sum of a non-empty subarray with at most 3 elements is 6, which is obtained from the subarray [1, 2, 3].

APPROACH:
1. Define a helper function 'countPartitions' to count the number of partitions required for a given maximum subarray sum.
2. Use binary search to find the maximum possible subarray sum.
3. Initialize low to the maximum element in 'a' and high to the sum of all elements in 'a'.
4. In each iteration of the binary search:
    a. Calculate the mid value.
    b. Count the number of partitions required for this mid value using the 'countPartitions' function.
    c. If the number of partitions required is greater than 'k', update low to mid + 1; otherwise, update high to mid - 1.
5. Return low, which represents the maximum possible subarray sum.

CODE:
*/

#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int countPartitions(vector<int> &a, int maxSum) {
    int n = a.size(); // Size of array
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum + a[i] <= maxSum) {
            // Insert element to current subarray
            subarraySum += a[i];
        } else {
            // Insert element to next subarray
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}

int largestSubarraySumMinimized(vector<int> &a, int k) {
    // Initialize binary search range
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    // Apply binary search
    while (low <= high) {
        int mid = (low + high) / 2; // Calculate mid value
        // Count the number of partitions required for this mid value
        int partitions = countPartitions(a, mid);
        if (partitions > k) {
            low = mid + 1; // Update low
        } else {
            high = mid - 1; // Update high
        }
    }
    return low; // Return the maximum possible subarray sum
}

/*
TIME COMPLEXITY: O(n log s), where n is the size of the 'a' array and s is the difference between the maximum and minimum possible values of the subarray sum.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
