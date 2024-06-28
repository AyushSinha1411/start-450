/*
QUESTION:
Given the roots of two binary trees, determine if the trees are identical. Two binary trees are considered identical if they have the same structure and the nodes have the same values.

EXAMPLE USAGE:
Node* root1 = new Node(1);
root1->left = new Node(2);
root1->right = new Node(3);

Node* root2 = new Node(1);
root2->left = new Node(2);
root2->right = new Node(3);

bool result = isIdentical(root1, root2);
// Output: true

APPROACH:
1. Check if both nodes are NULL, in which case they are identical.
2. If only one of the nodes is NULL, they are not identical.
3. Check if the data values of the current nodes are the same and recursively check their left and right subtrees.

CODE:
*/

// Node structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to check if two binary trees are identical
bool isIdentical(Node* node1, Node* node2){
    // If both nodes are NULL, they are identical
    if(node1 == NULL && node2 == NULL){
        return true;
    }
    // If only one of the nodes is NULL, they are not identical
    if(node1 == NULL || node2 == NULL){
        return false;
    }
    // Check if the current nodes have the same data value
    // and recursively check their left and right subtrees
    return ((node1->data == node2->data)
        && isIdentical(node1->left, node2->left)
        && isIdentical(node1->right, node2->right));
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the smaller tree. Each node is processed once.

SPACE COMPLEXITY:
- O(h), where h is the height of the tree. This is the space used by the system call stack during the recursion.
*/
