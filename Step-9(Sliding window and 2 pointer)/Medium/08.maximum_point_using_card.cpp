/*
QUESTION:
Write a function to find the maximum score you can obtain by choosing exactly k cards from the given array cardPoints. You can only pick cards from the beginning or the end of the array.

Example:
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation:
You can obtain a maximum score by picking the last three cards [5,6,1].

APPROACH:
1. Calculate the total score if all cards are selected.
2. Use a sliding window of size (n - k) to find the minimum subarray score.
3. The result will be the total score minus the minimum subarray score.
4. Iterate through the array to find the minimum subarray score of length (n - k).

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum score by choosing exactly k cards
int maxScore(vector<int> &cardPoints, int k) {
    int startingIndex = 0;
    int presentSubarrayScore = 0;
    int n = cardPoints.size();
    int requiredSubarrayLength = n - k;
    int minSubarrayScore;
    int totalScore = 0;

    // Total score obtained on selecting all the cards.
    for (int i : cardPoints) {
        totalScore += i;
    }
    
    minSubarrayScore = totalScore;

    if (k == n) {
        return totalScore;
    }

    for (int i = 0; i < n; i++) {
        presentSubarrayScore += cardPoints[i];
        int presentSubarrayLength = i - startingIndex + 1;
        // If a valid subarray (having size cardPoints.size() - k) is possible.
        if (presentSubarrayLength == requiredSubarrayLength) {
            minSubarrayScore = min(minSubarrayScore, presentSubarrayScore);
            presentSubarrayScore -= cardPoints[startingIndex++];
        }
    }
    return totalScore - minSubarrayScore;
}

/*
TIME COMPLEXITY: O(N), where N is the length of the cardPoints array. This is because each element is visited at most twice (once by the sliding window).
SPACE COMPLEXITY: O(1), since we are using only a few extra variables for calculations.
*/
