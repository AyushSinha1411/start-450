/*
QUESTION:
Find the maximum sum of a subarray in an array.

Example:
Input:
arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4], n = 9
Output:
The maximum subarray sum is: 6 (subarray [4, -1, 2, 1])

APPROACH:
1. Initialize two variables, maxi (maximum sum) and sum, to track the maximum sum found so far and the current sum of the subarray respectively. Initialize maxi with LONG_MIN to handle negative numbers.
2. Initialize start, ansStart, and ansEnd to track the starting index of the current subarray and the starting and ending indices of the maximum sum subarray.
3. Iterate through the array:
   - If sum becomes 0, update start to the current index as the starting index of the new subarray.
   - Add the current element to sum.
   - If sum becomes greater than maxi, update maxi with sum and update ansStart and ansEnd with start and the current index respectively.
   - If sum becomes negative, reset sum to 0 to discard the sum calculated so far.
4. After the loop, print the subarray with the maximum sum.
5. To handle the case when all elements are negative, uncomment the check to consider the sum of the empty subarray (maxi < 0).
6. Return maxi, which contains the maximum sum of a subarray.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum of a subarray
long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // Initialize maximum sum
    long long sum = 0;

    int start = 0; // Initialize starting index
    int ansStart = -1, ansEnd = -1; // Initialize indices of the maximum sum subarray

    for (int i = 0; i < n; i++) {
        if (sum == 0) start = i; // Update start if sum becomes 0
        sum += arr[i]; // Add the current element to sum

        if (sum > maxi) { // Update maxi if sum becomes greater than maxi
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        // If sum becomes negative, reset sum to 0
        if (sum < 0) {
            sum = 0;
        }
    }

    // Print the subarray with the maximum sum
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;

    // To consider the sum of the empty subarray, uncomment the following check:
    // if (maxi < 0) maxi = 0;

    return maxi; // Return the maximum sum of a subarray
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(1), as no extra space is used.
*/
