/*
QUESTION:
Write a function to find the number of subarrays with exactly k distinct integers in the given array nums.

Example:
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation:
The subarrays with exactly 2 distinct integers are:
[1,2], [2,1], [1,2], [2,1,2], [1,2,3], [2,1,2,3], [1,2]

APPROACH:
1. Use a sliding window technique to maintain a window with at most k distinct integers.
2. Initialize two pointers, i and j, to define the window.
3. Use a map to keep track of the frequency of each integer in the current window.
4. Iterate through the array with the j pointer.
5. Add the current element to the frequency map and update the count of distinct integers.
6. If the count of distinct integers exceeds k, move the i pointer to the right until the count of distinct integers is at most k.
7. Use a variable, prefixSum, to count the number of valid subarrays ending at j.
8. Whenever the count of distinct integers is exactly k, add the prefixSum to the result.
9. Return the total count of valid subarrays.

CODE:
*/

#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the number of subarrays with exactly k distinct integers
int subarraysWithKDistinct(vector<int>& nums, int k) {
    int n = nums.size();
    int i = 0, j = 0;
    unordered_map<int, int> counter;
    int distinctCount = 0;
    int ans = 0;
    int prefixSum = 0;

    for (int j = 0; j < n; j++) {
        if (counter[nums[j]] == 0) {
            distinctCount++;
        }
        counter[nums[j]]++;

        // If the count of distinct integers exceeds k, move the i pointer to the right
        while (distinctCount > k) {
            counter[nums[i]]--;
            if (counter[nums[i]] == 0) {
                distinctCount--;
            }
            i++;
            prefixSum = 0;
        }

        // Move the i pointer to the right while there are duplicate integers
        while (counter[nums[i]] > 1) {
            counter[nums[i]]--;
            i++;
            prefixSum++;
        }

        // If the count of distinct integers is exactly k, add the prefixSum to the result
        if (distinctCount == k) {
            ans += prefixSum + 1;
        }
    }

    return ans;
}

/*
TIME COMPLEXITY: O(N), where N is the length of the array. This is because each element is visited at most twice (once by the j pointer and once by the i pointer).
SPACE COMPLEXITY: O(K), since the map can hold at most k distinct integers.
*/
