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
    if (n == 0) return 0;

    int sum = 1; // Initialize sum with 1 candy for the first child
    int i = 1; // Start from the second child

    // Traverse through the ratings array
    while (i < n) {
        // If the current rating is equal to the previous rating, give 1 candy
        if (ratings[i] == ratings[i - 1]) {
            sum += 1;
            i++;
            continue;
        }

        int peak = 1; // Initialize peak to 1

        // Traverse up slope (increasing ratings)
        while (i < n && ratings[i] > ratings[i - 1]) {
            peak++;
            sum += peak;
            i++;
        }

        // Traverse down slope (decreasing ratings)
        int down = 0; // Initialize down to 0 because we already counted the peak
        while (i < n && ratings[i] < ratings[i - 1]) {
            down++;
            sum += down;
            i++;
        }

        // Adjust the sum if the down slope length is greater than or equal to the peak
        if (down >= peak) {
            sum += down - peak + 1;
        }
    }

    return sum; // Return the total number of candies
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
