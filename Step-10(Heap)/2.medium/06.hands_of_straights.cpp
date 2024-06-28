/*
QUESTION:
Given an array of integers hand where hand[i] represents the number of cards the player has. The player needs to rearrange the cards into groups where each group has exactly groupSize consecutive cards. Return true if the player can rearrange the cards, or false otherwise.

Example:
Input:
hand = [1, 2, 3, 6, 2, 3, 4, 7, 8], groupSize = 3
Output:
true
Explanation:
The hand can be rearranged as [1, 2, 3], [2, 3, 4], [6, 7, 8].

APPROACH:
1. If the size of the hand is not divisible by groupSize, return false.
2. Use a map to count the frequency of each card.
3. Form groups starting from the smallest card and ensure each group has consecutive cards.
4. If any group cannot be formed, return false.

CODE:
*/

#include <vector>
#include <map>
using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) {
        return false; // If the total number of cards is not divisible by groupSize, return false
    }

    map<int, int> countMap;
    for (int card : hand) {
        countMap[card]++;
    }

    while (!countMap.empty()) {
        int start = countMap.begin()->first; // Get the smallest card in the map

        // Form a group of size groupSize starting from the smallest card
        for (int i = 0; i < groupSize; ++i) {
            int currCard = start + i; // Next consecutive card

            auto it = countMap.find(currCard);
            if (it == countMap.end()) {
                return false; // If the next consecutive card is not found in the map, return false
            }

            if (--it->second == 0) {
                countMap.erase(it); // If the count of the next consecutive card becomes zero, remove it from the map
            }
        }
    }

    return true; // If all groups are formed successfully, return true
}

/*
TIME COMPLEXITY:
- O(N log N), where N is the number of cards. This complexity arises from the use of the map for counting card frequencies and checking the sequence.

SPACE COMPLEXITY:
- O(N), for storing the frequency map of the cards.
*/
