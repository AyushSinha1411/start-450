/*
EXAMPLE:
Input: Arr = [7, 1, 5, 3, 6, 4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

QUESTION:
Given an array Arr of integers where each element represents the price of a stock on a given day, 
write a function to calculate the maximum profit you can achieve from buying and selling one share of the stock. 
You must buy before you sell.

APPROACH:
1. Initialize variables to store the maximum profit and the minimum price encountered so far.
2. Iterate through the array from the second element to the end.
3. For each price, calculate the current profit if the stock was bought at the minimum price encountered so far and sold at the current price.
4. Update the maximum profit if the current profit is higher than the previous maximum profit.
5. Update the minimum price if the current price is lower than the previous minimum price.
6. Return the maximum profit.

CODE:
*/

int maximumProfit(vector<int> &Arr) {
    int maxProfit = 0;
    int mini = Arr[0];

    for (int i = 1; i < Arr.size(); i++) {
        int curProfit = Arr[i] - mini;
        maxProfit = max(maxProfit, curProfit);
        mini = min(mini, Arr[i]);
    }
    return maxProfit;
}

/*
TIME COMPLEXITY:
- The time complexity is O(n), where n is the number of elements in the array. This is because we only traverse the array once.

SPACE COMPLEXITY:
- The space complexity is O(1) since we are using a constant amount of extra space.

EXAMPLE USAGE:
vector<int> Arr = {7, 1, 5, 3, 6, 4};
int result = maximumProfit(Arr);
cout << "Maximum Profit: " << result << endl; // Output: 5
*/
