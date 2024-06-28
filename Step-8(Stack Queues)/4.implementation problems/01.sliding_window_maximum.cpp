/*
QUESTION:
Write a function to find the maximum value in each sliding window of size k in an array. Given an array nums and an integer k, return an array of the maximum values of each sliding window of size k.

Example:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                    Max
---------------                   -----
[1  3  -1] -3  5  3  6  7             3
 1 [3  -1  -3] 5  3  6  7             3
 1  3 [-1  -3  5] 3  6  7             5
 1  3  -1 [-3  5  3] 6  7             5
 1  3  -1  -3 [5  3  6] 7             6
 1  3  -1  -3  5 [3  6  7]            7

APPROACH:
1. Use a deque to store the indices of the elements in the current sliding window.
2. Iterate through the array nums.
3. For each element, remove indices from the front of the deque if they are out of the current sliding window.
4. Remove indices from the back of the deque while the elements at those indices are smaller than the current element.
5. Add the current index to the back of the deque.
6. If the current index is greater than or equal to k-1, add the element at the index at the front of the deque to the result array.
7. Return the result array.

CODE:
*/

#include <vector>
#include <deque>
using namespace std;

// Function to find the maximum value in each sliding window of size k
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
        // Remove indices from the front if they are out of the current sliding window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove indices from the back while elements at those indices are smaller than the current element
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Add the current index to the back of the deque
        dq.push_back(i);

        // If the current index is greater than or equal to k-1, add the element at the front of the deque to the result array
        if (i >= k - 1) {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}

/*
TIME COMPLEXITY: O(N), where N is the length of the array. This is because each element is added and removed from the deque at most once.
SPACE COMPLEXITY: O(K), for the deque used to store the indices of the elements in the current sliding window.
*/
