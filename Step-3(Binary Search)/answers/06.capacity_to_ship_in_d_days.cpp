/*
QUESTION:
You are given an array 'weights' representing weights of items and an integer 'd' representing the number of days. 
The array weights[i] represents the weight of the ith item. You need to find the least weight capacity of the ship that will allow all the items to be shipped within 'd' days.

Example:
Input:
weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], d = 5
Output:
15 // The least weight capacity of the ship that will allow all the items to be shipped within 5 days is 15.

APPROACH:
1. Define a function 'findDays' to find the number of days required to ship all the items with a given weight capacity.
2. Iterate through the weights and calculate the number of days required to ship all the items.
3. Define a function 'leastWeightCapacity' to find the least weight capacity of the ship.
4. Find the maximum and summation of weights to set the search space for binary search.
5. Apply binary search to find the least weight capacity.
6. If the number of days required is less than or equal to 'd', search for a smaller weight capacity; otherwise, search for a larger weight capacity.
7. Return the least weight capacity found.

CODE:
*/

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Function to find the number of days required to ship all items with a given weight capacity
int findDays(vector<int> &weights, int cap) {
    int days = 1; // First day
    int load = 0;
    int n = weights.size(); // Size of array
    for (int i = 0; i < n; i++) {
        if (load + weights[i] > cap) {
            days += 1; // Move to next day
            load = weights[i]; // Load the weight
        }
        else {
            load += weights[i]; // Load the weight on the same day
        }
    }
    return days;
}

// Function to find the least weight capacity of the ship
int leastWeightCapacity(vector<int> &weights, int d) {
    // Find the maximum and summation of weights
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    // Apply binary search
    while (low <= high) {
        int mid = (low + high) / 2;
        int numberOfDays = findDays(weights, mid);
        // If the number of days required is less than or equal to 'd', search for a smaller weight capacity
        if (numberOfDays <= d) {
            high = mid - 1;
        }
        // If the number of days required is greater than 'd', search for a larger weight capacity
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
