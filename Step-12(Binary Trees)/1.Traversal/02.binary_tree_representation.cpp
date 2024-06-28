/*
QUESTION:
Define a structure for a binary tree node.

EXAMPLE USAGE:
Node* root = new Node(10);
root->left = new Node(5);
root->right = new Node(15);

APPROACH:
1. Define a struct named `Node` to represent a node in a binary tree.
2. Each node contains an integer data value, and pointers to left and right child nodes.
3. Implement a constructor to initialize the node with a given value, setting the left and right pointers to NULL.

CODE:
*/

struct Node {
    // Defining the value of the node (integer data)
    int data;        
    // Reference pointer to the left child node
    Node* left;      
    // Reference pointer to the right child node
    Node* right;      

    // Constructor to initialize the node with a value
    Node(int val) {
        // Set the value of the node to the passed integer
        data = val;   
        // Initialize left and right pointers as NULL
        left = right = NULL;  
    }
};

/*
TIME COMPLEXITY:
- O(1) for node creation.

SPACE COMPLEXITY:
- O(1) for the space required to store each node.
*/
