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

// Define a struct representing a
// node in the Trie data structure
struct Node {
     // Array of pointers to child nodes
     // (assuming only lowercase English letters)
    Node* links[26]; 
    // Flag indicating if this node
    // marks the end of a word
    bool flag = false;  

    // Method to check if the node
    // contains a child node
    // corresponding to a given character
    bool containsKey(char ch) {
         // Check if the link for
         // the character exists
        return (links[ch - 'a'] != nullptr); 
    }

    // Method to get the child node
    // corresponding to a given character
    Node* get(char ch) {
         // Return the corresponding child node
        return links[ch - 'a']; 
    }

    // Method to set a child node
    // for a given character
    void put(char ch, Node* node) {
        // Set the link for the
        // character to the provided node
        links[ch - 'a'] = node;  
    }

    // Method to mark the node
    // as the end of a word
    void setEnd() {
         // Set the flag to
         // indicate the end of a word
        flag = true; 
    }

    // Method to check if the
    // node marks the end of a word
    bool isEnd() {
        // Return the flag indicating
        // if it's the end of a word
        return flag;  
    }
};

// Define a class for
// implementing the Trie data structure
class Trie {
private:
    // Pointer to the root
    // node of the Trie
    Node* root;  

public:
    // Constructor to initialize
    // the Trie data structure
    Trie() {
        // Create a new root
        // node for the Trie
        root = new Node();  
    }

    // Method to insert a
    // word into the Trie
    void insert(string word) {
         // Start traversal
         // from the root node
        Node* node = root; 
        // Iterate through each
        // character of the word
        for (char ch : word) {  
             // If the character doesn't
             // exist as a child node
            if (!node->containsKey(ch)) { 
                 // Create a new node
                 // for the character
                node->put(ch, new Node()); 
            }
            // Move to the next node
            node = node->get(ch);  
        }
         // Mark the last node as
         // the end of the word
        node->setEnd(); 
    }

    // Method to check if all prefixes
    // of a given word exist in the Trie
    bool checkIfAllPrefixExists(string word) {
         // Start traversal from the root node
        Node* node = root; 
        // Iterate through each
        // character of the word
        for (char ch : word) {  
            // If the character
            // exists as a child node
            if (node->containsKey(ch)) {
                // Move to the next node
                node = node->get(ch);  
            }
            else {
                 // Return false if
                 // the prefix doesn't exist
                return false; 
            }
        }
         // Return true if
         // all prefixes exist
        return true; 
    }
};

// Function to find the longest
// complete string in a given vector of strings
string completeString(int n, vector<string>& a) {
    // Create a Trie object
    Trie* obj = new Trie();  
    // Insert each word into the Trie
    for (const auto& word : a)  
        obj->insert(word);
        
    // Initialize the variable to
    // store the longest complete string
    string longest = "";
    // Iterate through each
    // word in the vector
    for (const auto& word : a) {  
         // Check if all prefixes
         // of the word exist
        if (obj->checkIfAllPrefixExists(word)) { 
            // Update the longest string if the current word
            // is longer or lexicographically smaller
            if (word.size() > longest.size() || (word.size() == longest.size() && word < longest)) {
                 // Update the longest string
                longest = word; 
            }
        }
    }
    // Return "None" if no
    // complete string found
    if (longest.empty()) return "None"; 
    // Return the longest complete string
    return longest;  
}


/*
TIME COMPLEXITY:
- O(n * m) for inserting all strings into the trie, where n is the number of strings and m is the average length of the strings.
- O(n * m) for checking all prefixes of each string.

SPACE COMPLEXITY:
- O(26 * m * n) for the trie nodes.

*/
