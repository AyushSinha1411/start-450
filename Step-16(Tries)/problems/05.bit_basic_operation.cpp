/*
QUESTION:
Implement a Trie data structure to support operations for inserting integers, finding the maximum XOR value with a given integer, and getting/setting bits in binary representation.


EXAMPLE USAGE:
Solution sol;
int maxXOR = sol.XOR(5, 7);       // Finds maximum XOR value with 5 after inserting 7
int bitCheck = sol.check(2, 3);   // Checks the bit value at position 2 after inserting 3
int setBitVal = sol.setBit(3, 2); // Sets the bit at position 3 after inserting 2

CODE:
*/

// Class representing a node in the Trie
class Node {
public:
    // Each node can have links to two other nodes: one for bit 0 and one for bit 1
    Node* link[2];
    
    // Constructor to initialize the links to nullptr
    Node() {
        link[0] = link[1] = nullptr;
    }
};

// Class representing the Trie data structure
class Trie {
public:
    Node* root; // Root node of the Trie

    // Constructor to initialize the root node
    Trie() {
        root = new Node();
    }

    // Function to insert an integer into the Trie as its binary representation
    void insert(int m) {
        Node* node = root; // Start from the root node
        // Loop through each bit of the integer from the most significant bit (31) to the least significant bit (0)
        for (int i = 31; i >= 0; i--) {
            int bit = (m >> i) & 1; // Extract the i-th bit of the integer
            // If the link for this bit doesn't exist, create a new node
            if (node->link[bit] == nullptr) {
                node->link[bit] = new Node();
            }
            node = node->link[bit]; // Move to the next node in the Trie
        }
    }

    // Function to find the maximum XOR value with the given integer
    int findXOR(int n) {
        Node* node = root; // Start from the root node
        int ans = 0; // Initialize the answer to 0
        // Loop through each bit of the integer from the most significant bit (31) to the least significant bit (0)
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1; // Extract the i-th bit of the integer
            // Try to move to the opposite bit (1 - bit) if possible to maximize the XOR
            if (node->link[1 - bit] != nullptr) {
                ans |= (1 << i); // Set the i-th bit of the answer to 1
                node = node->link[1 - bit]; // Move to the next node in the Trie
            } else {
                node = node->link[bit]; // Move to the current bit node if the opposite bit doesn't exist
            }
        }
        return ans; // Return the maximum XOR value found
    }

    // Function to get the bit value at a specific position in the Trie
    int getBit(int a, int b) {
        Node* node = root; // Start from the root node
        // Loop through the bits until reaching the specified position 'a'
        for (int i = 31; i > a; i--) {
            // Move to the next node based on the available link
            if (node->link[1]) {
                node = node->link[1];
            } else {
                node = node->link[0];
            }
        }
        // Return 1 if the link for bit 1 exists, otherwise return 0
        return (node->link[1]) ? 1 : 0;
    }

    // Function to set the bit value at a specific position in the Trie
    int setBit(int a, int b) {
        Node* node = root; // Start from the root node
        // Loop through the bits until reaching the specified position 'a'
        for (int i = 31; i > a; i--) {
            // Move to the next node based on the available link
            if (node->link[1]) {
                node = node->link[1];
            } else {
                node = node->link[0];
            }
        }
        // If the link for bit 1 exists, return the original integer 'b'
        if (node->link[1]) {
            return b;
        } else {
            // Otherwise, switch the link from bit 0 to bit 1
            Node* x = node->link[0];
            node->link[0] = nullptr;
            node->link[1] = x;
            // Set the bit at position 'a' in 'b' to 1 and return the new integer
            return b | (1 << a);
        }
    }
};

// Class representing the solution using the Trie
class Solution {
public:
    Trie t; // Create an instance of the Trie

    // Function to get the maximum XOR with a given integer 'n' after inserting integer 'm' into the Trie
    int XOR(int n, int m) {
        t.insert(m); // Insert 'm' into the Trie
        return t.findXOR(n); // Find and return the maximum XOR with 'n'
    }

    // Function to check the bit at a specific position 'a' in the integer 'b' inserted into the Trie
    int check(int a, int b) {
        t.insert(b); // Insert 'b' into the Trie
        return t.getBit(a, b); // Get and return the bit value at position 'a'
    }

    // Function to set the bit at a specific position 'c' in the integer 'd' inserted into the Trie
    int setBit(int c, int d) {
        t.insert(d); // Insert 'd' into the Trie
        return t.setBit(c, d); // Set and return the new integer with the bit at position 'c' set
    }
};


/*
TIME COMPLEXITY:
- O(1) for inserting, finding XOR, getting and setting bits as they involve a fixed number of operations on 32-bit integers.

SPACE COMPLEXITY:
- O(n) for storing n integers in the Trie.

*/
