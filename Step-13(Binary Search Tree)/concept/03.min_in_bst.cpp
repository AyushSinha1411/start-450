/*
QUESTION:
Given the root of a Binary Search Tree (BST), write a function to find the minimum value in the BST. The minimum value is located at the leftmost node of the BST.

EXAMPLE:
Input: root = [10, 5, 15, 2, 7, null, null, 1]
Output: 1

Input: root = [20, 10, 30, 5, 15, null, null, 2]
Output: 2

APPROACH:
1. Check if the root is NULL. If so, return -1 indicating that the tree is empty.
2. Initialize the answer with the value of the root node.
3. Traverse to the leftmost node of the tree by iterating through the left child nodes.
4. Update the answer with the value of the current node at each step.
5. Return the answer which holds the minimum value in the BST.

CODE:
*/

int minValue(struct Node *root) {
    // If the root is NULL, return -1 indicating that the tree is empty
    if (root == NULL) {
        return -1;
    }

    // Initialize the answer with the value of the root node
    int ans = root->data;

    // Traverse to the leftmost node of the tree
    while (root != NULL) {
        // Update the answer with the value of the current node
        ans = root->data;

        // Move to the left child of the current node
        root = root->left;
    }

    // Return the minimum value found in the BST
    return ans;
}

/*
EXAMPLE USAGE:
Node* root = new Node(10);
root->left = new Node(5);
root->right = new Node(15);
root->left->left = new Node(2);
root->left->right = new Node(7);
root->left->left->left = new Node(1);

int result = minValue(root);
// Expected output: 1

TIME COMPLEXITY:
- O(h), where h is the height of the tree. In the worst case, h can be equal to the number of nodes (n) in a skewed tree.

SPACE COMPLEXITY:
- O(1), as no additional space is required beyond the input and a few variables.
*/
