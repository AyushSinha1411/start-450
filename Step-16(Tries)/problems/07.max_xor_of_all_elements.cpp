/*
QUESTION:
Given an array of integers and multiple queries, each containing an integer, find the maximum XOR value for each query with any element from the array.

EXAMPLE USAGE:
vector<int> arr = {3, 10, 5, 25, 2, 8};
vector<vector<int>> queries = {{2, 1}, {8, 2}, {5, 3}};
vector<int> result = maxXorQueries(arr, queries);
// result will hold the maximum XOR values for each query

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

// Node structure for the Trie
struct Node {
    // Array to hold links to child nodes (0 and 1)
    Node* links[2];
    
    // Function to check if a child node exists at a given index (0 or 1)
    bool containsKey(int ind) {
        return (links[ind] != NULL);
    }
    
    // Function to get the child node at a given index (0 or 1)
    Node* get(int ind) {
        return links[ind];
    }
    
    // Function to set the child node at a given index (0 or 1)
    void put(int ind, Node* node) {
        links[ind] = node;
    }
};

// Trie class for handling binary representations of numbers
class Trie {
private:
    Node* root;
public:
    // Constructor to initialize the Trie with an empty root node
    Trie() {
        root = new Node();
    }
    
    // Function to insert a number into the Trie
    void insert(int num) {
        Node* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
    // Function to find the maximum XOR value achievable with a given number
    int findMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(node->containsKey(!bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

// Function to perform offline maximum XOR queries
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    vector<int> ans(queries.size(), 0);
    vector<pair<int, pair<int, int>>> offlineQueries;
    sort(arr.begin(), arr.end());
    
    int index = 0;
    for(auto &it: queries) {
        offlineQueries.push_back({it[1], {it[0], index++}});
    }
    
    sort(offlineQueries.begin(), offlineQueries.end());
    
    int i = 0;
    int n = arr.size();
    Trie trie;
    
    for(auto &it : offlineQueries) {
        while(i < n && arr[i] <= it.first) {
            trie.insert(arr[i]);
            i++;
        }
        
        if(i != 0)
            ans[it.second.second] = trie.findMax(it.second.first);
        else
            ans[it.second.second] = -1;
    }
    return ans;
}

/*
TIME COMPLEXITY:
- O((n + q) * 32 + n log n + q log q) for inserting n numbers into the Trie, handling q queries, and sorting the array and queries.

SPACE COMPLEXITY:
- O(n * 32) for storing n numbers in the Trie, where each number is represented by 32 bits.
*/
