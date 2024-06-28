/*
QUESTION:
Given a binary tree, a target node, and an integer k, write a function to find all nodes at distance k from the target node.

EXAMPLE USAGE:
TreeNode* root = new TreeNode(3);
root->left = new TreeNode(5);
root->right = new TreeNode(1);
root->left->left = new TreeNode(6);
root->left->right = new TreeNode(2);
root->right->left = new TreeNode(0);
root->right->right = new TreeNode(8);
root->left->right->left = new TreeNode(7);
root->left->right->right = new TreeNode(4);

TreeNode* target = root->left; // target node with value 5
int k = 2;

vector<int> result = distanceK(root, target, k);
for(int val : result) {
    cout << val << " "; // Output: 7 4 1
}
cout << endl;

APPROACH:
1. Use a helper function `printkdistanceNodeDown` to find nodes at distance k below the given node.
2. Use the main function `printkdistanceNode` to find nodes at distance k from the target node. This function:
   - Checks if the current node is the target.
   - Recursively traverses the left and right subtrees to find the target node and computes the distance from the target.
   - Uses `printkdistanceNodeDown` to find nodes at the required distance in the subtree that does not contain the target.
3. Use the main function `distanceK` to initialize the result vector and call `printkdistanceNode`.

CODE:
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to find nodes at distance k in the subtree rooted at 'root'.
void printkdistanceNodeDown(TreeNode* root, int k, vector<int>& result) {
    if (root == nullptr || k < 0) return;

    if (k == 0) {
        result.push_back(root->val);
        return;
    }

    printkdistanceNodeDown(root->left, k - 1, result);
    printkdistanceNodeDown(root->right, k - 1, result);
}

// Main function to find nodes at distance k from the target node.
int printkdistanceNode(TreeNode* root, TreeNode* target, int k, vector<int>& result) {
    if (root == nullptr) return -1;

    if (root == target) {
        printkdistanceNodeDown(root, k, result);
        return 0;
    }

    int dl = printkdistanceNode(root->left, target, k, result);
    if (dl != -1) {
        if (dl + 1 == k) result.push_back(root->val);
        else printkdistanceNodeDown(root->right, k - dl - 2, result);
        return 1 + dl;
    }

    int dr = printkdistanceNode(root->right, target, k, result);
    if (dr != -1) {
        if (dr + 1 == k) result.push_back(root->val);
        else printkdistanceNodeDown(root->left, k - dr - 2, result);
        return 1 + dr;
    }

    return -1;
}

// Function to find all nodes at distance k from the target node.
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> result;
    printkdistanceNode(root, target, k, result);
    return result;
}

/*
TIME COMPLEXITY:
- O(N), where N is the number of nodes in the binary tree. This is because in the worst case, we may have to visit all nodes to find the target node and then find all nodes at distance k.

SPACE COMPLEXITY:
- O(N), due to the recursive call stack. In the worst case, the height of the tree could be N, leading to O(N) space complexity.
*/
