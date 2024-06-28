/*
QUESTION:
Given a list of strings, find the longest string such that every prefix of the string is also a string in the list. If there are multiple such strings with the same length, return the lexicographically smallest one. If no such string exists, return "None".

Example:
Input: n = 5, a = ["a", "ap", "app", "appl", "apple"]
Output: "apple"
Explanation: "apple" is the longest string with all prefixes present in the list.

APPROACH:
1. Implement a trie to insert all the strings.
2. For each string, check if all its prefixes are present in the trie.
3. Track the longest valid string or the lexicographically smallest one if there are ties.

CODE:
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Trie node structure
struct trieNode {
    struct trieNode *child[26]; // Array to store links to child nodes
    bool isEnding; // Flag to indicate if a node marks the end of a word
};

// Function to create a new trie node
struct trieNode *newTrieNode(void) {
    struct trieNode *newNode = new trieNode;
    newNode->isEnding = false;
    for (int i = 0; i < 26; i++)
        newNode->child[i] = NULL;
    return newNode;
}

// Function to insert a word into the trie
void insert(struct trieNode *root, string str) {
    int len = str.length();
    struct trieNode *pCrawl = root;

    for (int level = 0; level < len; level++) {
        int index = str[level] - 'a';
        if (!pCrawl->child[index])
            pCrawl->child[index] = newTrieNode();
        pCrawl = pCrawl->child[index];
    }
    // Mark the end of the word in the trie
    pCrawl->isEnding = true;
}

// Function to check if all prefixes of a word are present in the trie
bool allPrefixed(struct trieNode *root, string word) {
    struct trieNode *pCrawl = root;
    for (char c : word) {
        int i = c - 'a';
        pCrawl = pCrawl->child[i];
        if (pCrawl == NULL || pCrawl->isEnding == false) {
            return false;
        }
    }
    // If all prefixes of the word are present in the trie
    return true;
}

// Function to find the complete string with all prefixes present
string completeString(int n, vector<string> &a) {
    // Initialize answer as empty string
    string ans = "";

    struct trieNode *root = newTrieNode();

    // Insert each element of the array into the trie
    for (string word : a)
        insert(root, word);

    // Traverse over strings and check which of them have all prefixes present in the array
    for (string word : a) {
        if (!allPrefixed(root, word))
            continue;
        // If the current word is longer than 'ans'
        if (ans.size() < word.size()) {
            ans = word;
        }
        // If the current word is of the same size as 'ans' but is lexicographically smaller than 'ans'
        else if (ans.size() == word.size() && word < ans) {
            ans = word;
        }
    }

    // If no valid word is present, return "None"
    if (ans.size() == 0) {
        ans = "None";
    }

    // Return the result
    return ans;
}

/*
TIME COMPLEXITY:
- O(n * m) for inserting all strings into the trie, where n is the number of strings and m is the average length of the strings.
- O(n * m) for checking all prefixes of each string.

SPACE COMPLEXITY:
- O(26 * m * n) for the trie nodes.

EXAMPLE USAGE:
int n = 5;
vector<string> a = {"a", "ap", "app", "appl", "apple"};
string result = completeString(n, a);
// Output: "apple"
*/
