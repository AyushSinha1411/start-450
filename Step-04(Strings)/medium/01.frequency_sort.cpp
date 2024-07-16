/*
Question:
Given a string `s`, sort it in decreasing order based on the frequency of characters. If two characters have the same frequency, they can appear in any order.

Example:
Input: "tree"
Output: "eert" or "eetr"

Approach:
1. Use a hash map to count the frequency of each character in the string.
2. Use a max heap (priority queue) to store the characters based on their frequency.
3. Build the resulting string by repeatedly extracting the character with the highest frequency from the heap.

Time Complexity: O(n log k), where n is the length of the string and k is the number of unique characters.
Space Complexity: O(k), where k is the number of unique characters.

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

string frequencySort(string s) {
    // Step 1: Count the frequency of each character
    unordered_map<char, int> frequencyMap;
    for (char c : s) {
        frequencyMap[c]++;
    }

    // Step 2: Use a max heap to store characters by frequency
    priority_queue<pair<int, char>> maxHeap;
    for (const auto &entry : frequencyMap) {
        maxHeap.push({entry.second, entry.first});
    }

    // Step 3: Build the resulting string
    string result;
    while (!maxHeap.empty()) {
        auto [freq, ch] = maxHeap.top();
        maxHeap.pop();
        result.append(freq, ch); // Append the character 'freq' times
    }

    return result;
}

/*
TIME COMPLEXITY: O(n log k), where 'n' is the length of the string and 'k' is the number of unique characters. The priority_queue operations take log k time.
SPACE COMPLEXITY: O(n + k), where 'n' is the length of the string for the result and 'k' is the number of unique characters for the unordered_map and priority_queue.
*/
