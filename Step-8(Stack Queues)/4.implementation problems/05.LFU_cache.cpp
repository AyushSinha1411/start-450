/*
QUESTION:
Implement a Least Frequently Used (LFU) cache. The cache should be able to store key-value pairs and return the value for a given key. If the key is not present, return -1. The cache should also be able to add new key-value pairs and evict the least frequently used key-value pair when the cache reaches its capacity.

Example:
LFUCache cache = new LFUCache(2); // capacity 2
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);    // returns 1
cache.put(3, 3); // evicts key 2
cache.get(2);    // returns -1 (not found)
cache.get(3);    // returns 3

APPROACH:
1. Use two unordered maps and a list to store the key-value pairs and their frequencies.
2. The first map (cache) stores the frequency and an iterator to the list element for each key.
3. The second map (frequencies) stores the lists of key-value pairs that have the same frequency.
4. The list allows quick removal and insertion of elements.
5. Keep track of the minimum frequency (minf).
6. On a get operation, update the frequency of the key and move it to the corresponding list.
7. On a put operation, add the new key-value pair and update the minimum frequency.

CODE:
*/

#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
    unordered_map<int, list<pair<int, int>>> frequencies; // key: frequency, value: list of original key-value pairs with the same frequency
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache; // key: original key, value: pair of frequency and iterator in frequencies map's list
    int capacity;
    int minf;

    // Helper function to insert key-value pair with given frequency
    void insert(int key, int frequency, int value) {
        frequencies[frequency].push_back({key, value});
        cache[key] = {frequency, --frequencies[frequency].end()};
    }

public:
    LFUCache(int capacity) : capacity(capacity), minf(0) {}

    int get(int key) {
        const auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        const int f = it->second.first;
        const auto iter = it->second.second;
        const pair<int, int> kv = *iter;
        frequencies[f].erase(iter);
        if (frequencies[f].empty()){
            frequencies.erase(f);
            if(minf == f) {
                ++minf;
            }
        }
        insert(key, f + 1, kv.second);
        return kv.second;
    }

    void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }
        const auto it = cache.find(key);
        if (it != cache.end()) {
            it->second.second->second = value;
            get(key);
            return;
        }
        if (capacity == cache.size()) {
            cache.erase(frequencies[minf].front().first);
            frequencies[minf].pop_front();
            if(frequencies[minf].empty()) {
                frequencies.erase(minf);
            }
        }
        minf = 1;
        insert(key, 1, value);
    }
};

/*
TIME COMPLEXITY: O(1) for both get and put operations.
SPACE COMPLEXITY: O(capacity), where capacity is the maximum number of key-value pairs the cache can hold.
*/
