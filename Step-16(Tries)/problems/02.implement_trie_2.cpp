/*
QUESTION:
Implement a Trie (prefix tree) with insert, countWordsEqualTo, countWordsStartingWith, and erase methods. The Trie should support counting the number of words equal to a given word, counting the number of words starting with a given prefix, and erasing words from the Trie.

Example:
Input:
Trie trie = new Trie();
trie.insert("apple");
int countEqual = trie.countWordsEqualTo("apple");   // returns 1
int countPrefix = trie.countWordsStartingWith("app"); // returns 1
trie.erase("apple");
countEqual = trie.countWordsEqualTo("apple");   // returns 0

APPROACH:
1. Create a Node structure that holds an array of pointers to other nodes, counters for the number of words that end at the node, and counters for the number of words that have the node as a prefix.
2. Create a Trie class with a root node.
3. Implement the insert method to add words to the Trie and update the counters.
4. Implement the countWordsEqualTo method to count the number of words equal to a given word.
5. Implement the countWordsStartingWith method to count the number of words starting with a given prefix.
6. Implement the erase method to remove a word from the Trie and update the counters.

CODE:
*/

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Node structure for Trie
struct Node {
    Node* links[26]; // Array to store links to child nodes
    int cntEndWith = 0; // Counter for number of words that end at this node
    int cntPrefix = 0; // Counter for number of words that have this node as a prefix

    // Function to check if the node contains a specific key
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); // Check if the link corresponding to the character exists
    }

    // Function to get the child node corresponding to a key
    Node* get(char ch) {
        return links[ch - 'a']; // Return the link corresponding to the character
    }

    // Function to insert a child node with a specific key
    void put(char ch, Node* node) {
        links[ch - 'a'] = node; // Set the link corresponding to the character to the provided node
    }

    // Function to increment the count of words that end at this node
    void increaseEnd() {
        cntEndWith++; // Increment the counter
    }

    // Function to increment the count of words that have this node as a prefix
    void increasePrefix() {
        cntPrefix++; // Increment the counter
    }

    // Function to decrement the count of words that end at this node
    void deleteEnd() {
        cntEndWith--; // Decrement the counter
    }

    // Function to decrement the count of words that have this node as a prefix
    void reducePrefix() {
        cntPrefix--; // Decrement the counter
    }
};

// Trie class
class Trie {
private:
    Node* root; // Pointer to the root node of the Trie

public:
    // Constructor to initialize the Trie with an empty root node
    Trie() {
        root = new Node(); // Create a new root node
    }

    // Function to insert a word into the Trie
    void insert(string word) {
        Node* node = root; // Start from the root node
        for (int i = 0; i < word.size(); i++) { // Iterate over each character in the word
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node()); // Create a new node for the character if not present
            }
            node = node->get(word[i]); // Move to the child node corresponding to the character
            node->increasePrefix(); // Increment the prefix count for the node
        }
        node->increaseEnd(); // Increment the end count for the last node of the word
    }

    // Function to count the number of words equal to a given word
    int countWordsEqualTo(string word) {
        Node* node = root; // Start from the root node
        for (int i = 0; i < word.size(); i++) { // Iterate over each character in the word
            if (node->containsKey(word[i])) {
                node = node->get(word[i]); // Move to the child node corresponding to the character
            } else {
                return 0; // Return 0 if the character is not found
            }
        }
        return node->cntEndWith; // Return the count of words ending at the node
    }

    // Function to count the number of words starting with a given prefix
    int countWordsStartingWith(string word) {
        Node* node = root; // Start from the root node
        for (int i = 0; i < word.size(); i++) { // Iterate over each character in the prefix
            if (node->containsKey(word[i])) {
                node = node->get(word[i]); // Move to the child node corresponding to the character
            } else {
                return 0; // Return 0 if the character is not found
            }
        }
        return node->cntPrefix; // Return the count of words with the prefix
    }

    // Function to erase a word from the Trie
    void erase(string word) {
        Node* node = root; // Start from the root node
        for (int i = 0; i < word.size(); i++) { // Iterate over each character in the word
            if (node->containsKey(word[i])) {
                node = node->get(word[i]); // Move to the child node corresponding to the character
                node->reducePrefix(); // Decrement the prefix count for the node
            } else {
                return; // Return if the character is not found
            }
        }
        node->deleteEnd(); // Decrement the end count for the last node of the word
    }
};

/*
TIME COMPLEXITY:
- Insert: O(len) where len is the length of the word.
- CountWordsEqualTo: O(len) where len is the length of the word.
- CountWordsStartingWith: O(len) where len is the length of the prefix.
- Erase: O(len) where len is the length of the word.

SPACE COMPLEXITY:
- O(N * len) where N is the number of words inserted and len is the average length of the words.

EXAMPLE USAGE:
Trie trie;
trie.insert("apple");
int countEqual = trie.countWordsEqualTo("apple");   // returns 1
int countPrefix = trie.countWordsStartingWith("app"); // returns 1
trie.erase("apple");
countEqual = trie.countWordsEqualTo("apple");   // returns 0
*/
