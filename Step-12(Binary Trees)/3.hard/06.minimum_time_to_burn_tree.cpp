/*
QUESTION:
Given a binary tree and a target leaf node, find the time required to burn the entire tree starting from the target leaf. The fire spreads to adjacent nodes (parent, left child, right child) in 1 unit of time.

EXAMPLE USAGE:
Input : 
            1
       /       \
      2          3
    /  \          \
   4    5          6
      /   \         \
     7     8         9
                      \
                       10
Leaf = 8
Output : 7
Initially 8 is set to fire at 0th sec.
            1
       /       \
      2          3
    /  \          \
   4    5          6
      /   \         \
     7     F         9
                      \
                       10
After 1s: 5 is set to fire.
            1
       /       \
      2          3
    /  \          \
   4    F          6
      /   \         \
     7     F         9
                      \
                       10
After 2s: 2, 7 are set to fire.
            1
       /       \
      F          3
    /  \          \
   4    F          6
      /   \         \
     F     F         9
                      \
                       10
After 3s: 4, 1 are set to fire.
            F
       /       \
      F          3
    /  \          \
   F    F          6
      /   \         \
     F     F         9
                      \
                       10
After 4s: 3 is set to fire.
            F
       /       \
      F          F
    /  \          \
   F    F          6
      /   \         \
     F     F         9
                      \
                       10
After 5s: 6 is set to fire.
            F
       /       \
      F          F
    /  \          \
   F    F          F
      /   \         \
     F     F         9
                      \
                       10
After 6s: 9 is set to fire.
            F
       /       \
      F          F
    /  \          \
   F    F          F
      /   \         \
     F     F         F
                      \
                       10
After 7s: 10 is set to fire.
            F
       /       \
      F          F
    /  \          \
   F    F          F
      /   \         \
     F     F         F
                      \
                       F
It takes 7s to burn the complete tree.


APPROACH:
1. Use a recursive function to traverse the tree and find the height of the tree starting from the target leaf node.
2. For each node, determine if the target leaf node is in the left or right subtree.
3. Calculate the distance from the target leaf to the current node.
4. Keep track of the maximum time required to burn the tree using a global variable `res`.

CODE:
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : key(x), left(NULL), right(NULL) {}
};

// Global variable to store the result
int res = 0;

// Function to find the time for the tree to burn
int burnTime(TreeNode* root, int leaf, int& dist) {
    // Base case: If the current node is NULL, return 0
    if (root == NULL) {
        return 0;
    }

    // If the current node is the target leaf node
    if (root->key == leaf) {
        dist = 0;
        return 1;
    }

    // Variables to store the distance from the target leaf in left and right subtrees
    int ldist = -1, rdist = -1;

    // Recursively find the burn time for the left and right subtrees
    int lh = burnTime(root->left, leaf, ldist);
    int rh = burnTime(root->right, leaf, rdist);

    // If the target leaf is found in the left subtree
    if (ldist != -1) {
        dist = ldist + 1;
        res = max(res, dist + rh);
    }
    // If the target leaf is found in the right subtree
    else if (rdist != -1) {
        dist = rdist + 1;
        res = max(res, dist + lh);
    }

    // Return the height of the subtree rooted at the current node
    return max(lh, rh) + 1;
}

/*
TIME COMPLEXITY:
- O(N), where N is the number of nodes in the binary tree. This is because we may need to visit each node to calculate the burn time.

SPACE COMPLEXITY:
- O(H), where H is the height of the binary tree. This is due to the recursive call stack.
*/
