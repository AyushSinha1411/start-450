/*
QUESTION:
Given the preorder and inorder traversal of a binary tree, build the binary tree and return its root.

EXAMPLE:
Input:
preorder = [3, 9, 20, 15, 7]
inorder = [9, 3, 15, 20, 7]

Output:
The constructed binary tree is:
       3
      / \
     9   20
        /  \
       15   7

APPROACH:
1. Create a map to store the indices of elements in the inorder traversal for quick lookup.
2. Use a recursive function to construct the binary tree from preorder and inorder traversals.
3. The base case is when the start indices exceed the end indices.
4. The root value is taken from the preorder traversal.
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
    // Function to build a binary tree from preorder and inorder traversals
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create a map to store indices of elements in the inorder traversal
        map<int, int> inMap;
        
        // Populate the map with indices of elements in the inorder traversal
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        
        // Call the private helper function to recursively build the tree
        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        
        return root;
    }

private:
    // Recursive helper function to build the tree
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, 
            vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap) {
        // Base case: If the start indices exceed the end indices, return NULL
        if(preStart > preEnd || inStart > inEnd) {
            return NULL;
        }
        
        // Create a new TreeNode with value at the current preorder index
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        // Find the index of the current root value in the inorder traversal
        int inRoot = inMap[root->val];
        
        // Calculate the number of elements in the left subtree
        int numsLeft = inRoot - inStart;
        
        // Recursively build the left subtree
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, 
                                inorder, inStart, inRoot - 1, inMap);
        
        // Recursively build the right subtree
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, 
                                inorder, inRoot + 1, inEnd, inMap);
        
        // Return the current root node
        return root;
    }
};

/*
EXAMPLE USAGE:
int main() {
    Solution sol;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode* root = sol.buildTree(preorder, inorder);
    // Output: The constructed binary tree
    return 0;
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes. Each node is processed once.

SPACE COMPLEXITY:
- O(n), due to the map and the recursion stack.
*/
