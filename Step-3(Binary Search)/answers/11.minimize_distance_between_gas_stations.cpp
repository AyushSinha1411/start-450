/*
QUESTION:
You are given an array 'arr' representing the positions of gas stations along a road and an integer 'k' representing the number of gas stations you can build. You need to find the minimum possible value of the maximum distance between adjacent gas stations such that you can build at most 'k' gas stations.

Example:
Input:
dist = 5, arr = [1, 3, 5, 9, 10], k = 3
Output:
2.5 // The minimum possible value of the maximum distance between adjacent gas stations such that you can build at most 3 gas stations is 2.5.

APPROACH:
1. Define a helper function 'numberOfGasStationsRequired' to count the number of gas stations required for a given maximum distance.
2. Use binary search to find the minimum possible value of the maximum distance.
3. Initialize low to 0 and high to the maximum distance between adjacent gas stations.
4. In each iteration of the binary search:
    a. Calculate the mid value.
    b. Count the number of gas stations required for this mid value using the 'numberOfGasStationsRequired' function.
    c. If the number of gas stations required is greater than 'k', update low to mid; otherwise, update high to mid.
5. Return high, which represents the minimum possible value of the maximum distance between adjacent gas stations.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // Size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // Size of the array
    long double low = 0;
    long double high = 0;

    // Find the maximum distance
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    // Apply binary search
    long double diff = 1e-6;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0); // Calculate mid value
        // Count the number of gas stations required for this mid value
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid; // Update low
        } else {
            high = mid; // Update high
        }
    }
    return high; // Return the minimum possible value of the maximum distance
}

/*
TIME COMPLEXITY: O(n log d), where n is the size of the 'arr' array and d is the maximum distance between adjacent gas stations.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
