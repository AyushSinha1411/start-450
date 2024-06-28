/*
QUESTION:
Given a string `s`, count the number of distinct substrings of `s`.

Example:
Input: s = "ababa"
Output: 10
Explanation: The distinct substrings are "", "a", "b", "ab", "ba", "aba", "bab", "abab", "baba", "ababa".

APPROACH:
1. Use a Trie data structure to store all substrings.
2. Iterate through the string and insert all possible substrings into the Trie.
3. Each time a new character node is created, increment the count of distinct substrings.

CODE:
*/

#include <iostream>
#include <string>
using namespace std;

// Node structure representing each node in the trie
struct Node {
    Node* links[26];  // Array of pointers to child nodes, each corresponding to a letter of the alphabet
    bool flag = false;  // Flag indicating if the current node represents the end of a substring

    // Method to check if a specific character key exists in the children of the current node
    bool containsKey(char ch) {  
        return (links[ch - 'a'] != NULL);
    }

    // Method to get the child node corresponding to a specific character key
    Node* get(char ch) {  
        return links[ch - 'a'];
    }

    // Method to insert a new child node with a specific character key
    void put(char ch, Node* node) {  
        links[ch - 'a'] = node;
    }

    // Method to mark the current node as the end of a substring
    void setEnd() {  
        flag = true;
    }

    // Method to check if the current node marks the end of a substring
    bool isEnd() {  
        return flag;
    }
};

// Function to count the number of distinct substrings in the given string
int countDistinctSubstrings(string &s) {  
    Node* root = new Node();  // Creating the root node of the trie
    int cnt = 0;  // Counter to keep track of distinct substrings
    int n = s.size();  // Length of the input string

    // Nested loops to iterate through all possible substrings of the input string
    for (int i = 0; i < n; i++) {  
        Node* node = root;  // Start from the root for each substring
        for (int j = i; j < n; j++) {  
            // If the current character is not a child of the current node, insert it as a new child node
            if (!node->containsKey(s[j])) {
                node->put(s[j], new Node());  // Insert a new child node for character s[j]
                cnt++;  // Increment the counter since a new substring is found
            }
            node = node->get(s[j]);  // Move to the child node corresponding to character s[j]
        }
    }
    return cnt + 1;  // Return the total count of distinct substrings (+1 to account for the input string itself)
}

/*
TIME COMPLEXITY:
- O(n^2) for inserting all substrings into the trie, where n is the length of the input string.

SPACE COMPLEXITY:
- O(n^2) for the trie nodes.

EXAMPLE USAGE:
string s = "ababa";
int result = countDistinctSubstrings(s);
// Output: 10
*/
