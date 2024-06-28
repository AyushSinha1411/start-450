/*
QUESTION:
Given a string s, sort it in decreasing order based on the frequency of characters. If two characters have the same frequency, they can appear in any order.

Example:
Input: "tree"
Output: "eert" or "eetr" (both are valid as 'e' appears twice and 'r' and 't' appear once)

APPROACH:
1. Use an unordered_map to count the frequency of each character in the string.
2. Use a priority_queue (max-heap) to store characters and their frequencies in decreasing order of frequency.
3. Populate the priority_queue with the frequency counts from the unordered_map.
4. Construct the result string by repeatedly taking the most frequent character from the priority_queue and appending it to the result string.
5. Return the result string.

CODE:
*/

#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

string frequencySort(string s) {
    // Lambda function for the comparison in priority_queue
    auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second; // Max-heap based on frequency
    };

    // Priority queue (max-heap) to store characters by frequency
    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);

    // Unordered_map to count frequency of each character
    unordered_map<char, int> hm;

    // Count frequency of each character in the string
    for (char c : s) {
        hm[c]++;
    }

    // Push each character and its frequency into the priority_queue
    for (const auto& entry : hm) {
        pq.push(make_pair(entry.first, entry.second));
    }

    // Construct the result string
    string result = "";
    while (!pq.empty()) {
        pair<char, int> p = pq.top();
        pq.pop();
        result.append(p.second, p.first); // Append character 'p.first' 'p.second' times
    }

    // Return the result string
    return result;
}

/*
TIME COMPLEXITY: O(n log k), where 'n' is the length of the string and 'k' is the number of unique characters. The priority_queue operations take log k time.
SPACE COMPLEXITY: O(n + k), where 'n' is the length of the string for the result and 'k' is the number of unique characters for the unordered_map and priority_queue.
*/
