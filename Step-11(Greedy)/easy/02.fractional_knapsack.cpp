/*
QUESTION:
Given weights and values of `n` items, we need to put these items in a knapsack of capacity `W` to get the maximum total value in the knapsack. 
We can break items for maximizing the total value of knapsack.

Example:
Input: W = 50, n = 3, arr[] = {{60, 10}, {100, 20}, {120, 30}}
Output: 240.00
Explanation: 
We can get the maximum value by taking all items, however the third item can be broken into 20 (60% of weight) + 10 (remaining weight).
Hence, maximum value we can obtain = 60 + 100 + (120 * (10/30)) = 240.00

APPROACH:
1. Calculate the ratio of value to weight for each item.
2. Sort items based on this ratio in descending order.
3. Initialize current weight in knapsack as 0 and total value as 0.
4. Iterate through sorted items:
   a. If the current item's weight can be fully added, add it to the knapsack.
   b. Otherwise, add the fraction of the item's value corresponding to the remaining capacity.
5. Return the total value of items in the knapsack.

CODE:
*/

#include <bits/stdc++.h>
#include<algorithm>
// Structure for an item which stores weight and value
struct Item {
    int value, weight;
};

// Comparison function to sort items based on value/weight ratio
bool static comp(Item a, Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

// Function to return the maximum value that can be put in a knapsack of capacity W
double fractionalKnapsack(int W, Item arr[], int n) {
    // Sort items based on value/weight ratio in descending order
    sort(arr, arr + n, comp);

    int curWeight = 0;  // Current weight in knapsack
    double finalvalue = 0.0;  // Result (value in knapsack)

    // Looping through all items
    for (int i = 0; i < n; i++) {
        // If adding Item won't overflow, add it completely
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        } 
        // If we can't add current Item, add fractional part of it
        else {
            int remain = W - curWeight;
            finalvalue += (arr[i].value / (double)arr[i].weight) * (double)remain;
            break;
        }
    }

    // Returning final value
    return finalvalue;
}

/*
TIME COMPLEXITY:
- O(n log n) due to sorting the items by their value/weight ratio.
- O(n) for the traversal of all items.

SPACE COMPLEXITY:
- O(1) for additional space usage.
*/
