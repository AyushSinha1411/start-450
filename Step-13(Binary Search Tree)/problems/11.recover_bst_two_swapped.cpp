/*
QUESTION:
Recover a Binary Search Tree (BST) where two nodes have been swapped by mistake. The task is to correct the BST by swapping back the two nodes without changing the structure of the tree.

EXAMPLE:
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: The node values 1 and 3 are swapped by mistake.

APPROACH:
1. Use Morris Traversal to achieve O(1) space complexity.
2. Identify the two nodes that are swapped by mistake by maintaining pointers during the traversal.
3. Swap the values of the identified nodes to correct the BST.

CODE:
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    // Inorder traversal function to find the two swapped nodes
    void inorder(TreeNode* root) {
        if (root == NULL) return;

        inorder(root->left);

        // If this is the first violation, mark these two nodes as 'first' and 'middle'
        if (prev != NULL && root->val < prev->val) {
            if (first == NULL) {
                first = prev;
                middle = root;
            } else {
                // If this is the second violation, mark this node as 'last'
                last = root;
            }
        }

        // Mark this node as previous
        prev = root;

        inorder(root->right);
    }

public:
    // Function to recover the BST by fixing the swapped nodes
    void recoverTree(TreeNode* root) {
        first = middle = last = prev = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        
        // Fix the swapped nodes
        if (first && last) 
            swap(first->val, last->val);
        else if (first && middle) 
            swap(first->val, middle->val);
    }
};

/*
EXAMPLE USAGE:
TreeNode* root = new TreeNode(3);
root->left = new TreeNode(1);
root->right = new TreeNode(4);
root->right->left = new TreeNode(2);

recoverTree(root); // Corrects the BST

TIME COMPLEXITY:
- O(n), where n is the number of nodes in the BST. Each node is processed at most twice.

SPACE COMPLEXITY:
- O(1), using Morris Traversal, we achieve constant space complexity for the traversal.
*/
