/*
QUESTION:
Given an array that represents preorder traversal of a binary search tree (BST), construct the BST from the given preorder traversal array.

EXAMPLE:
Input: preorder = [10, 5, 1, 7, 40, 50]
Output: BST constructed from the given preorder traversal.

APPROACH:
1. Initialize the current index in the preorder array to 0.
2. Use a recursive helper function to construct the BST.
3. The helper function uses the min and max constraints to ensure that the nodes are placed correctly in the BST.
4. If the current key is within the min and max range, create a new node.
5. Recursively construct the left and right subtrees with updated constraints.

CODE:
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Utility function to construct the BST from preorder traversal
TreeNode* constructTreeUtil(int pre[], int* preIndex, int key, int min, int max, int size) {
    // Base case: if the current index is out of bounds, return null
    if (*preIndex >= size) {
        return nullptr;
    }

    TreeNode* root = nullptr;

    // If the current key is within the min and max range
    if (key > min && key < max) {
        // Create a new node with the current key
        root = new TreeNode(key);
        *preIndex = *preIndex + 1;

        // Recursively construct the left subtree with updated constraints
        if (*preIndex < size) {
            root->left = constructTreeUtil(pre, preIndex, pre[*preIndex], min, key, size);
        }
        // Recursively construct the right subtree with updated constraints
        if (*preIndex < size) {
            root->right = constructTreeUtil(pre, preIndex, pre[*preIndex], key, max, size);
        }
    }

    return root;
}

// Function to construct BST from preorder traversal
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int size = preorder.size();
    if (size == 0) return nullptr;

    int preIndex = 0;
    return constructTreeUtil(preorder.data(), &preIndex, preorder[0], INT_MIN, INT_MAX, size);
}

/*
EXAMPLE USAGE:
vector<int> preorder = {10, 5, 1, 7, 40, 50};
TreeNode* root = bstFromPreorder(preorder);

// The constructed BST from the given preorder traversal
// would look like:
//        10
//       /  \
//      5    40
//     / \     \
//    1   7    50

TIME COMPLEXITY:
- O(n), where n is the number of nodes in the BST. Each node is visited once.

SPACE COMPLEXITY:
- O(n), where n is the number of nodes in the BST. This accounts for the space used by the recursion stack.
*/
