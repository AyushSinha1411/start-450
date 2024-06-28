/*
QUESTION:
Given the root of a binary tree and a value 'B', find and return the path from the root to the node with value 'B'. If the node does not exist, return an empty vector.

EXAMPLE USAGE:
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);
root->left->right = new TreeNode(5);

vector<int> path = solve(root, 5);
// Output: [1, 2, 5] (Path from root to node with value 5)

APPROACH:
1. Define a helper function `getPath` to find the path from the root to a given node with value 'x'.
2. Use a vector to store the path.
3. Base case: If the current node is null, return false.
4. Add the current node's value to the path vector.
5. If the current node's value is equal to the target value 'x', return true.
6. Recursively search for the target value 'x' in the left and right subtrees.
7. If the target value 'x' is not found in the current path, backtrack by removing the current node's value from the path vector and return false.
8. Define the main function `solve` to find and return the path from the root to a given node with value 'B'.

Input :            1
                 /   \
                2     3
              /  \   /  \
            4    5  6   7
 x = 5
Output : 1->2->5
CODE:
*/

#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find the path from the root to a given node with value 'x'
bool getPath(TreeNode* root, vector<int>& arr, int x) {
    // Base case: If the current node is null, return false
    if (!root) {
        return false;
    }

    // Add the current node's value to the path vector
    arr.push_back(root->val);

    // If the current node's value is equal to the target value 'x', return true
    if (root->val == x) {
        return true;
    }

    // Recursively search for the target value 'x' in the left and right subtrees
    if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) {
        return true;
    }

    // If the target value 'x' is not found in the current path, backtrack
    arr.pop_back();
    return false;
}

// Function to find and return the path from the root to a given node with value 'B'
vector<int> solve(TreeNode* A, int B) {
    // Initialize an empty vector to store the path
    vector<int> arr;

    // If the root node is null, return the empty path vector
    if (A == NULL) {
        return arr;
    }

    // Call the getPath function to find the path to the node with value 'B'
    getPath(A, arr, B);

    // Return the path vector
    return arr;
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the binary tree. Each node is visited once.

SPACE COMPLEXITY:
- O(h), where h is the height of the binary tree. The maximum space used by the recursion stack.
*/
