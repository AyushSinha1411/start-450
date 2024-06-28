/*
QUESTION:
Given an array 'v' representing the pile of bananas, where v[i] is the number of bananas in the i-th pile, and an integer 'h' representing the number of hours you have to eat all the bananas. You can only eat k bananas in an hour, where k is an integer. Find the minimum integer k such that you can eat all the bananas within 'h' hours.

Example:
Input:
v = [3, 6, 7, 11], h = 8
Output:
4 // To eat all bananas within 8 hours, you need to eat at least 4 bananas per hour.

APPROACH:
1. Define a function 'findMax' to find the maximum number of bananas in any pile.
2. Define a function 'calculateTotalHours' to calculate the total hours required to eat all bananas at a given rate.
3. Use binary search to find the minimum rate to eat bananas within 'h' hours.
4. Initialize low as 1 and high as the maximum number of bananas in any pile.
5. While low is less than or equal to high, calculate mid as (low + high) / 2.
6. Calculate the total hours required to eat all bananas at the rate of mid bananas per hour.
7. If totalH is less than or equal to h, update high = mid - 1 to search for a lower rate.
8. If totalH is greater than h, update low = mid + 1 to search for a higher rate.
9. Return low as the minimum rate to eat bananas within 'h' hours.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum number of bananas in any pile.
int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    // Find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

// Function to calculate the total hours required to eat all bananas at a given rate.
int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    // Find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

// Function to find the minimum rate to eat bananas within 'h' hours using binary search.
int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1, high = findMax(v);

    // Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

/*
TIME COMPLEXITY: O(n log m), where n is the size of the array and m is the maximum number of bananas in any pile.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
