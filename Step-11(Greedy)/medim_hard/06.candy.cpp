/*
QUESTION:
Given an array `ratings` representing the ratings of `n` children, distribute candies such that:
1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.

Example:
Input: ratings = [1, 0, 2]
Output: 5
Explanation: You can distribute to the children with ratings [1, 0, 2] as [2, 1, 2] candies.

APPROACH:
1. Initialize a vector `candies` with the same size as `ratings`, filled with 1 (each child gets at least one candy).
2. Traverse the `ratings` from left to right, ensuring that each child with a higher rating than the previous child gets more candies.
3. Traverse the `ratings` from right to left, ensuring that each child with a higher rating than the next child gets more candies (while maintaining the left-to-right constraints).
4. Sum up all the values in the `candies` vector to get the total number of candies needed.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1); // Initialize all children with one candy

    // Traverse from left to right
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1; // Give more candies to child with higher rating
        }
    }

    // Traverse from right to left
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1); // Update candies for child with higher rating
        }
    }

    // Calculate total candies needed
    int totalCandies = 0;
    for (int candy : candies) {
        totalCandies += candy;
    }

    return totalCandies;
}

/*
TIME COMPLEXITY:
- O(n) for both traversals of the ratings array.

SPACE COMPLEXITY:
- O(n) for the auxiliary candies array.

EXAMPLE USAGE:
vector<int> ratings = {1, 0, 2};
int result = candy(ratings);
// result will be 5
*/
