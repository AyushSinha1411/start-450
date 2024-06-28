/*
QUESTION:
Given an array of stock prices, find the maximum profit that can be achieved by buying and selling stocks on different days.

Example:
Input:
arr = [7, 1, 5, 3, 6, 4]
Output:
The maximum profit is: 5 (buying at price 1 and selling at price 6)

APPROACH:
1. Initialize maxPro to 0 to store the maximum profit.
2. Initialize minPrice to INT_MAX to store the minimum price seen so far.
3. Iterate through the array:
   - Update minPrice with the minimum of minPrice and the current price.
   - Update maxPro with the maximum of maxPro and the difference between the current price and minPrice.
4. After the loop, maxPro will contain the maximum profit.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum profit from buying and selling stocks
int maxProfit(vector<int>& arr) {
    int maxPro = 0; // Initialize maximum profit
    int n = arr.size(); // Size of the array
    int minPrice = INT_MAX; // Initialize minimum price

    for (int i = 0; i < n; i++) {
        minPrice = min(minPrice, arr[i]); // Update minPrice
        maxPro = max(maxPro, arr[i] - minPrice); // Update maxPro
    }
    
    return maxPro; // Return the maximum profit
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(1), as no extra space is used.
*/
