/*
QUESTION:
Given a binary search tree (BST) and an integer k, write a function to find the Kth smallest and Kth largest elements in the BST.

EXAMPLE:
Input: root = [5,3,6,2,4,null,7], k = 2
Output: (3, 6)

Input: root = [5,3,6,2,4,null,7], k = 3
Output: (4, 5)

APPROACH:
1. Use inorder traversal to find the Kth smallest element since it processes nodes in ascending order.
2. Use reverse inorder traversal to find the Kth largest element since it processes nodes in descending order.
3. Maintain a counter to keep track of visited nodes and compare with k.
4. Store the Kth smallest and Kth largest values once the counter reaches k.

CODE:
*/

// Helper function to perform reverse inorder
// traversal to find Kth largest element
void reverseInorder(TreeNode* node, int& counter, int k, int& kLargest) {
    if (!node || counter >= k) return;

    // Traverse right subtree
    reverseInorder(node->right, counter, k, kLargest);

    // Increment counter after
    // visiting right subtree
    counter++;

    // Check if current node
    // is the Kth largest
    if (counter == k) {
        kLargest = node->val;
        return;
    }

    // Traverse left subtree if
    // Kth largest is not found yet
    reverseInorder(node->left, counter, k, kLargest);
}

// Helper function to perform inorder
// traversal to find Kth smallest element
void inorder(TreeNode* node, int& counter, int k, int& kSmallest) {
    if (!node || counter >= k) return;

    // Traverse left subtree
    inorder(node->left, counter, k, kSmallest);

    // Increment counter after visiting left subtree
    counter++;

    // Check if current node is the Kth smallest
    if (counter == k) {
        kSmallest = node->val;
        return;
    }

    // Traverse right subtree if
    // Kth smallest is not found yet
    inorder(node->right, counter, k, kSmallest);
}

public:
pair<int, int> findKth(TreeNode* root, int k) {
    int kSmallest = INT_MIN, kLargest = INT_MIN;
    // Counter to track visited nodes
    int counter = 0; 

    // Find Kth smallest element
    // (perform inorder traversal)
    inorder(root, counter, k, kSmallest);
    
    // Reset counter for Kth largest element
    counter = 0; 
    // Find Kth largest element
    // (perform reverse inorder traversal)
    reverseInorder(root, counter, k, kLargest);

    return make_pair(kSmallest, kLargest);
}

/*
EXAMPLE USAGE:
TreeNode* root = new TreeNode(5);
root->left = new TreeNode(3);
root->right = new TreeNode(6);
root->left->left = new TreeNode(2);
root->left->right = new TreeNode(4);
root->right->right = new TreeNode(7);

int k = 2;
pair<int, int> result = findKth(root, k);
// Expected output: (3, 6)

TIME COMPLEXITY:
- O(n), where n is the number of nodes in the BST, because in the worst case, we might visit all nodes.

SPACE COMPLEXITY:
- O(h), where h is the height of the BST, due to the recursive call stack.
*/
