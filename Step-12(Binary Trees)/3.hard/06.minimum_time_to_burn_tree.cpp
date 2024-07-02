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


int findMaxDistance(map<BinaryTreeNode*, BinaryTreeNode*>& mpp, BinaryTreeNode* target) {
    queue<BinaryTreeNode*> q;
    q.push(target);
    map<BinaryTreeNode*, int> vis;
    vis[target] = 1;
    int maxi = 0;

    while (!q.empty()) {
        int sz = q.size();
        int fl = 0;
        for (int i = 0; i < sz; i++) {
            auto node = q.front();
            q.pop();
            if (node->left && !vis[node->left]) {
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if (node->right && !vis[node->right]) {
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            if (mpp[node] && !vis[mpp[node]]) {
                fl = 1;
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }
        if (fl) maxi++;
    }
    return maxi;
}

BinaryTreeNode* bfsToMapParents(BinaryTreeNode* root, map<BinaryTreeNode*, BinaryTreeNode*>& mpp, int start) {
    queue<BinaryTreeNode*> q;
    q.push(root);
    BinaryTreeNode* res = nullptr;
    while (!q.empty()) {
        BinaryTreeNode* node = q.front();
        q.pop();
        if (node->data == start) res = node;
        if (node->left) {
            mpp[node->left] = node;
            q.push(node->left);
        }
        if (node->right) {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

int timeToBurnTree(BinaryTreeNode* root, int start) {
    map<BinaryTreeNode*, BinaryTreeNode*> mpp;
    BinaryTreeNode* target = bfsToMapParents(root, mpp, start);
    int maxi = findMaxDistance(mpp, target);
    return maxi;
}
/*
TIME COMPLEXITY:
- O(N), where N is the number of nodes in the binary tree. This is because we may need to visit each node to calculate the burn time.

SPACE COMPLEXITY:
- O(H), where H is the height of the binary tree. This is due to the recursive call stack.
*/
