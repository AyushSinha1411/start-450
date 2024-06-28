/*
QUESTION:
Implement a Trie (prefix tree) with insert, search, and startsWith methods.

Example:
Input:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true

APPROACH:
1. Create a Node structure that holds an array of pointers to other nodes and a flag to indicate if it marks the end of a word.
2. Create a Trie class with a root node.
3. Implement the insert method to add words to the Trie.
4. Implement the search method to check if a word exists in the Trie.
5. Implement the startsWith method to check if any word in the Trie starts with the given prefix.

CODE:
*/

// Node structure for Trie
struct Node {
    // Array to store links to child nodes, each index represents a letter
    Node* links[26];
    // Flag indicating if the node marks the end of a word
    bool flag = false;

    // Check if the node contains a specific key (letter)
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    // Insert a new node with a specific key (letter) into the Trie
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Get the node with a specific key (letter) from the Trie
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    // Set the current node as the end of a word
    void setEnd() {
        flag = true;
    }

    // Check if the current node marks the end of a word
    bool isEnd() {
        return flag;
    }
};

// Trie class
class Trie {
private:
    Node* root;

public:
    // Constructor to initialize the Trie with an empty root node
    Trie() {
        root = new Node();
    }

    // Inserts a word into the Trie
    // Time Complexity: O(len), where len is the length of the word
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                // Create a new node for the letter if not present
                node->put(word[i], new Node());
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Mark the end of the word
        node->setEnd();
    }

    // Returns if the word is in the Trie
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                // If a letter is not found, the word is not in the Trie
                return false;
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Check if the last node marks the end of a word
        return node->isEnd();
    }

    // Returns if there is any word in the Trie that starts with the given prefix
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                // If a letter is not found, there is no word with the given prefix
                return false;
            }
            // Move to the next node
            node = node->get(prefix[i]);
        }
        // The prefix is found in the Trie
        return true;
    }
};

/*
TIME COMPLEXITY:
- Insert: O(len) where len is the length of the word.
- Search: O(len) where len is the length of the word.
- StartsWith: O(len) where len is the length of the prefix.

SPACE COMPLEXITY:
- O(N * len) where N is the number of words inserted and len is the average length of the words.

EXAMPLE USAGE:
Trie trie;
trie.insert("apple");
bool result1 = trie.search("apple");   // returns true
bool result2 = trie.search("app");     // returns false
bool result3 = trie.startsWith("app"); // returns true
trie.insert("app");
bool result4 = trie.search("app");     // returns true
*/
