/*
QUESTION:
Given a Binary Search Tree (BST) and a target value, determine if there are two nodes in the BST such that their sum is equal to the target value.

EXAMPLE:
Input: root = [5,3,6,2,4,null,7], target = 9
Output: true
Explanation: Nodes 2 and 7 sum to 9.

APPROACH:
1. Use two stacks to perform in-order and reverse in-order traversal of the BST.
2. In-order traversal will give the smallest element first, while reverse in-order traversal will give the largest element first.
3. Use two pointers technique to find the pair of nodes whose sum is equal to the target value.
4. If a pair is found, return true. Otherwise, return false.

CODE:
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to check if there exists a pair with a given target sum in the BST
bool isPairPresent(TreeNode* root, int target) {
    // Two stacks for in-order and reverse in-order traversal
    stack<TreeNode*> s1, s2;
    
    // Flags to indicate if the traversal of a subtree is done
    bool done1 = false, done2 = false;
    
    // Variables to store the values of nodes during traversal
    int val1 = 0, val2 = 0;
    
    // Pointers to traverse the tree
    TreeNode *curr1 = root, *curr2 = root;

    // Loop until the traversal is complete
    while (true) {
        // In-order traversal (smallest element first)
        while (!done1) {
            if (curr1 != nullptr) {
                s1.push(curr1);
                curr1 = curr1->left;
            } else {
                if (s1.empty()) {
                    done1 = true;
                } else {
                    curr1 = s1.top();
                    s1.pop();
                    val1 = curr1->val;
                    curr1 = curr1->right;
                    done1 = true;
                }
            }
        }

        // Reverse in-order traversal (largest element first)
        while (!done2) {
            if (curr2 != nullptr) {
                s2.push(curr2);
                curr2 = curr2->right;
            } else {
                if (s2.empty()) {
                    done2 = true;
                } else {
                    curr2 = s2.top();
                    s2.pop();
                    val2 = curr2->val;
                    curr2 = curr2->left;
                    done2 = true;
                }
            }
        }

        // Check if the sum of the two values is equal to the target
        if ((val1 != val2) && (val1 + val2) == target) {
            return true;
        } else if ((val1 + val2) < target) {
            done1 = false;
        } else if ((val1 + val2) > target) {
            done2 = false;
        }

        // If the pointers have crossed, break the loop
        if (val1 >= val2) {
            return false;
        }
    }
}

// Function to find if there exists a pair with a given target sum in the BST
bool findTarget(TreeNode* root, int k) {
    return isPairPresent(root, k);
}

/*
EXAMPLE USAGE:
TreeNode* root = new TreeNode(5);
root->left = new TreeNode(3);
root->right = new TreeNode(6);
root->left->left = new TreeNode(2);
root->left->right = new TreeNode(4);
root->right->right = new TreeNode(7);

bool result = findTarget(root, 9); // Returns true as 2 + 7 = 9

TIME COMPLEXITY:
- O(n), where n is the number of nodes in the BST. Each node is processed at most twice.

SPACE COMPLEXITY:
- O(h), where h is the height of the BST. The space is used by the stacks to store the nodes during traversal.
*/
