/*
QUESTION:
Given a non-empty array of integers, return the k most frequent elements.

Example:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Input: nums = [1], k = 1
Output: [1]

APPROACH:
1. Use a hash map to count the frequency of each element in the array.
2. Use a min-heap to keep track of the top k frequent elements.
3. If the size of the min-heap exceeds k, remove the least frequent element.
4. Extract the elements from the min-heap to get the top k frequent elements in ascending order.
5. Reverse the order of elements to return them in descending order of frequency.

CODE:
*/

#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    // Create a hash map to count the frequency of each element
    unordered_map<int, int> frequencyMap;
    for (int num : nums) {
        frequencyMap[num]++;
    }
    
    // Create a min heap to store the top k frequent elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    
    // Push each element-frequency pair into the min heap
    for (auto& entry : frequencyMap) {
        minHeap.push({entry.second, entry.first});
        
        // If the size of the min heap exceeds k, pop the least frequent element
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    // Extract the top k frequent elements from the min heap
    vector<int> topKFrequentElements;
    while (!minHeap.empty()) {
        topKFrequentElements.push_back(minHeap.top().second);
        minHeap.pop();
    }
    
    // Reverse the order of elements to return them in descending order of frequency
    reverse(topKFrequentElements.begin(), topKFrequentElements.end());
    
    return topKFrequentElements;
}

/*
TIME COMPLEXITY:
- O(n log k) due to the insertion and removal of elements in the heap, where n is the number of elements in the array.
- Building the frequency map takes O(n) time.

SPACE COMPLEXITY:
- O(n) to store the frequency map.
- O(k) for the min-heap to store the top k frequent elements.
*/
