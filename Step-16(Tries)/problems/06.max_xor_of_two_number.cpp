/*
QUESTION:
Implement a Trie data structure to support operations for inserting integers and finding the maximum XOR value with a given integer from two sets of numbers.

EXAMPLE USAGE:
vector<int> arr1 = {3, 10, 5, 25, 2, 8};
vector<int> arr2 = {1, 2, 3, 4, 5};
int result = maxXOR(arr1.size(), arr2.size(), arr1, arr2);
// result will hold the maximum XOR value between the two sets of numbers

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

// Node structure for the Trie
struct Node {
    // Array to store links to child nodes (0 and 1)
    Node* links[2];
    
    // Method to check if a specific bit key is present in the child nodes
    bool containsKey(int bit) {
        // Returns true if the link at index 'bit' is not NULL
        return (links[bit] != NULL);
    }
    
    // Method to get the child node corresponding to a specific bit
    Node* get(int bit) {
        // Returns the child node at index 'bit'
        return links[bit];
    }
    
    // Method to set a child node at a specific index in the links array
    void put(int bit, Node* node) {
        // Sets the child node at index 'bit' to the provided node
        links[bit] = node;
    }
};

// Trie class
class Trie {
private:
    // Root node of the Trie
    Node* root;
public:
    // Constructor to initialize the Trie with a root node
    Trie() {
        // Creates a new root node for the Trie
        root = new Node();
    }
    
    // Method to insert a number into the Trie
    void insert(int num) {
        // Start from the root node
        Node* node = root;
        // Iterate through each bit of the number (from left to right)
        for (int i = 31; i >= 0; i--) {
            // Extract the i-th bit of the number
            int bit = (num >> i) & 1;
            
            // If the current node doesn't have a child node with the current bit
            if (!node->containsKey(bit)) {
                // Create a new child node with the current bit
                node->put(bit, new Node());
            }
            
            // Move to the child node corresponding to the current bit
            node = node->get(bit);
        }
    }
    
    // Method to find the maximum XOR value for a given number
    int getMax(int num) {
        // Start from the root node
        Node* node = root;
        
        // Initialize the maximum XOR value
        int maxNum = 0;
        
        // Iterate through each bit of the number (from left to right)
        for (int i = 31; i >= 0; i--) {
            // Extract the i-th bit of the number
            int bit = (num >> i) & 1;
            
            // If the complement of the current bit exists in the Trie
            if (node->containsKey(1 - bit)) {
                // Update the maximum XOR value with the current bit
                maxNum |= (1 << i);
                
                // Move to the child node corresponding to the complement of the current bit
                node = node->get(1 - bit);
            } else {
                // Move to the child node corresponding to the current bit
                node = node->get(bit);
            }
        }
        
        // Return the maximum XOR value
        return maxNum;
    }
};

// Function to find the maximum XOR value between two sets of numbers
int maxXOR(int n, int m, vector<int>& arr1, vector<int>& arr2) {
    // Create a Trie object
    Trie trie;
    // Insert each number from the first set into the Trie
    for (auto& it : arr1) {
        trie.insert(it);
    }
    
    // Initialize the maximum XOR value
    int maxi = 0;
    
    // Iterate through each number in the second set
    for (auto& it : arr2) {
        // Update the maximum XOR value with the result from the Trie
        maxi = max(maxi, trie.getMax(it));
    }
    // Return the maximum XOR value
    return maxi;
}

/*
TIME COMPLEXITY:
- O(n + m) for inserting n numbers into the Trie and finding the maximum XOR for m numbers.

SPACE COMPLEXITY:
- O(n * 32) for storing n numbers in the Trie, where each number is represented by 32 bits.
*/
