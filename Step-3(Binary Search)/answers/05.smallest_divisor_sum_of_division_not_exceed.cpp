/*
QUESTION:
You are given an array 'arr' of integers and an integer 'limit'. You need to find the smallest divisor such that the sum of division values of the array elements by that divisor does not exceed the given 'limit'. 

Example:
Input:
arr = [1, 2, 5], limit = 3
Output:
2 // Smallest divisor such that the sum of division values of [1, 2, 5] does not exceed 3 is 2.

APPROACH:
1. Define a function 'sumByD' to find the summation of division values of array elements by a divisor.
2. Iterate through the array and calculate the sum of division values.
3. Define a function 'smallestDivisor' to find the smallest divisor such that the sum of division values does not exceed the limit.
4. Find the maximum element in the array to set the upper limit for binary search.
5. Apply binary search to find the smallest divisor.
6. If the sum of division values is less than or equal to the limit, search for a smaller divisor; otherwise, search for a larger divisor.
7. Return the smallest divisor found.

CODE:
*/

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to find the summation of division values
int sumByD(vector<int> &arr, int div) {
    int n = arr.size(); // Size of array
    int sum = 0;
    // Calculate the summation of division values
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}

// Function to find the smallest divisor
int smallestDivisor(vector<int>& arr, int limit) {
    int n = arr.size();
    if (n > limit) return -1;
    // Set the search space for binary search
    int low = 1, high = *max_element(arr.begin(), arr.end());

    // Apply binary search
    while (low <= high) {
        int mid = (low + high) / 2;
        // If the sum of division values does not exceed the limit, search for a smaller divisor
        if (sumByD(arr, mid) <= limit) {
            high = mid - 1;
        }
        // If the sum of division values exceeds the limit, search for a larger divisor
        else {
            low = mid + 1;
        }
    }
    return low;
}

/*
TIME COMPLEXITY: O(n log m), where n is the size of the array and m is the maximum element in the array.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
