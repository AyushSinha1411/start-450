/*
QUESTION:
Implement a Trie data structure to support operations for inserting integers, finding the maximum XOR value with a given integer, and getting/setting bits in binary representation.

CODE:
*/

class Node {
public:
    Node* link[2];
    
    Node() {
        link[0] = link[1] = nullptr;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    // Insert integer into Trie as a binary representation
    void insert(int m) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (m >> i) & 1;
            if (node->link[bit] == nullptr) {
                node->link[bit] = new Node();
            }
            node = node->link[bit];
        }
    }

    // Find the maximum XOR value with the given integer
    int findXOR(int n) {
        Node* node = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (node->link[1 - bit] != nullptr) {
                ans |= (1 << i);
                node = node->link[1 - bit];
            } else {
                node = node->link[bit];
            }
        }
        return ans;
    }

    // Get the bit value at a specific position
    int getBit(int a, int b) {
        Node* node = root;
        for (int i = 31; i > a; i--) {
            if (node->link[1]) {
                node = node->link[1];
            } else {
                node = node->link[0];
            }
        }
        return (node->link[1]) ? 1 : 0;
    }

    // Set the bit value at a specific position
    int setBit(int a, int b) {
        Node* node = root;
        for (int i = 31; i > a; i--) {
            if (node->link[1]) {
                node = node->link[1];
            } else {
                node = node->link[0];
            }
        }
        if (node->link[1]) {
            return b;
        } else {
            Node* x = node->link[0];
            node->link[0] = nullptr;
            node->link[1] = x;
            return b | (1 << a);
        }
    }
};

class Solution {
public:
    Trie t;

    // Function to get the maximum XOR with a given integer
    int XOR(int n, int m) {
        t.insert(m);
        return t.findXOR(n);
    }

    // Function to check bit at a specific position
    int check(int a, int b) {
        t.insert(b);
        return t.getBit(a, b);
    }

    // Function to set bit at a specific position
    int setBit(int c, int d) {
        t.insert(d);
        return t.setBit(c, d);
    }
};

/*
TIME COMPLEXITY:
- O(1) for inserting, finding XOR, getting and setting bits as they involve a fixed number of operations on 32-bit integers.

SPACE COMPLEXITY:
- O(n) for storing n integers in the Trie.

EXAMPLE USAGE:
Solution sol;
int maxXOR = sol.XOR(5, 7);       // Finds maximum XOR value with 5 after inserting 7
int bitCheck = sol.check(2, 3);   // Checks the bit value at position 2 after inserting 3
int setBitVal = sol.setBit(3, 2); // Sets the bit at position 3 after inserting 2
*/
