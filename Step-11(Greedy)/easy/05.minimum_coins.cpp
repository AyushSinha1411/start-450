/*
QUESTION:
Given a value `V` and an array of `n` denominations, find the minimum number of coins/notes needed to make the change for `V`.

Example:
Input: V = 93, n = 6, denomination[] = {1, 2, 5, 10, 20, 50}
Output: 50 20 20 2 1
Explanation: 
We need 1 note of 50, 2 notes of 20, 1 coin of 2 and 1 coin of 1 to make the change for 93.

APPROACH:
1. Sort the array of denominations in ascending order.
2. Initialize an empty result vector to store the denominations used.
3. Traverse the sorted array of denominations from the highest to the lowest.
4. For each denomination, while it can be subtracted from `V`, subtract it and add it to the result.
5. Print the denominations used.

CODE:
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findMin(int V, int denomination[], int n) {
    // Sort the array of denominations in ascending order
    sort(denomination, denomination + n);

    // Initialize result vector to store the denominations used
    vector<int> ans;

    // Traverse through all denominations from highest to lowest
    for (int i = n - 1; i >= 0; i--) {
        // Find the denominations to make change for V
        while (V >= denomination[i]) {
            V -= denomination[i];
            ans.push_back(denomination[i]);
        }
    }

    // Print the result
    for (int coin : ans) {
        cout << coin << " ";
    }
    cout << endl;
}

/*
EXAMPLE USAGE:
int main() {
    int V = 93;
    int denomination[] = {1, 2, 5, 10, 20, 50};
    int n = sizeof(denomination) / sizeof(denomination[0]);
    findMin(V, denomination, n);
    return 0;
}

TIME COMPLEXITY:
- O(n log n) due to sorting the denominations.
- O(V) for the traversal of the value V.

SPACE COMPLEXITY:
- O(V) for storing the result in the worst case.
*/
