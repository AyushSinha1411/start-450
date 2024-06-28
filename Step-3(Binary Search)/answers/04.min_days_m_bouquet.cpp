/*
QUESTION:
You have 'n' roses in your garden represented by an array 'arr', where arr[i] is the number of roses that will bloom on the i-th day. You want to make 'm' bouquets of roses. To make a bouquet, you need to pick 'k' roses from the garden. You can only pick roses that are blooming on the same day. Find the minimum number of days you need to wait to be able to make 'm' bouquets.

Example:
Input:
arr = [1, 2, 4, 9], k = 2, m = 2
Output:
4 // To make 2 bouquets of 2 roses each, you need to wait until the 4th day when there are at least 2 roses blooming.

APPROACH:
1. Define a function 'possible' to check if it's possible to make 'm' bouquets with 'k' roses each on a given day.
2. Iterate through the array and count the number of bouquets that can be made on that day.
3. Check if the total number of bouquets is greater than or equal to 'm'.
4. Define a function 'roseGarden' to find the minimum number of days needed to make 'm' bouquets of 'k' roses each.
5. Find the minimum and maximum blooming day in the garden.
6. Apply binary search to find the minimum number of days needed to make 'm' bouquets.
7. If it's possible to make 'm' bouquets on a given day, search for a smaller day; otherwise, search for a larger day.
8. Return the minimum number of days found.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if it's possible to make 'm' bouquets with 'k' roses each on a given day.
bool possible(vector<int> &arr, int day, int m, int k) {
    int n = arr.size(); // Size of the array
    int cnt = 0;
    int noOfB = 0;
    // Count the number of bouquets:
    for (int i = 0; i < n; i++) {
        if (arr[i] <= day) {
            cnt++;
        }
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}

// Function to find the minimum number of days needed to make 'm' bouquets of 'k' roses each.
int roseGarden(vector<int> arr, int k, int m) {
    long long val = m * 1ll * k * 1ll;
    int n = arr.size(); // Size of the array
    if (val > n) return -1; // Impossible case.
    // Find maximum and minimum blooming days:
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    // Apply binary search:
    int low = mini, high = maxi;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (possible(arr, mid, m, k)) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
}

/*
TIME COMPLEXITY: O(n log m), where n is the size of the array.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
