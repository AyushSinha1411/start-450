/*
QUESTION:
Given the inorder and postorder traversal of a binary tree, build the binary tree and return its root.

EXAMPLE:
Input:
inorder = [9, 3, 15, 20, 7]
postorder = [9, 15, 7, 20, 3]

Output:
The constructed binary tree is:
       3
      / \
     9   20
        /  \
       15   7

APPROACH:
1. Create a map to store the indices of elements in the inorder traversal for quick lookup.
2. Use a recursive function to construct the binary tree from inorder and postorder traversals.
3. The base case is when the start indices exceed the end indices.
4. The root value is taken from the postorder traversal.
5. Find the index of this root value in the inorder traversal.
6. Calculate the number of elements in the left subtree.
7. Recursively build the left and right subtrees.
8. Return the constructed root node.

CODE:
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to build a binary tree from inorder and postorder traversals
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) {
            return NULL;
        }

        // Create a map to store the indices of elements in the inorder traversal
        map<int, int> hm;
        for (int i = 0; i < inorder.size(); i++) {
            hm[inorder[i]] = i;
        }

        // Call the recursive function to build the binary tree
        return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0,
            postorder.size() - 1, hm);
    }

private:
    // Recursive function to build a binary tree from inorder and postorder traversals
    TreeNode* buildTreePostIn(vector<int>& inorder, int is, int ie,
        vector<int>& postorder, int ps, int pe, map<int, int>& hm) {

        // Base case: If the subtree is empty, return NULL
        if (ps > pe || is > ie) {
            return NULL;
        }

        // Create a new TreeNode with the root value from postorder
        TreeNode* root = new TreeNode(postorder[pe]);

        // Find the index of the root value in inorder traversal
        int inRoot = hm[postorder[pe]];
        
        // Number of nodes in the left subtree
        int numsLeft = inRoot - is; 

        // Recursively build the left and right subtrees
        root->left = buildTreePostIn(inorder, is, inRoot - 1, postorder,
            ps, ps + numsLeft - 1, hm);

        root->right = buildTreePostIn(inorder, inRoot + 1, ie, postorder,
            ps + numsLeft, pe - 1, hm);

        // Return the root of the constructed subtree
        return root;
    }
};

/*
EXAMPLE USAGE:
int main() {
    Solution sol;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode* root = sol.buildTree(inorder, postorder);
    // Output: The constructed binary tree
    return 0;
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes. Each node is processed once.

SPACE COMPLEXITY:
- O(n), due to the map and the recursion stack.
*/
