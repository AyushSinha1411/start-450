/*
QUESTION:
Given the root of a binary tree, find the maximum path sum. A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. The path does not need to pass through the root.

EXAMPLE USAGE:
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
int maxSum = maxPathSum(root);
// Output: 11 (4 -> 2 -> 1 -> 3)

APPROACH:
1. Use a recursive function `findMaxPathSum` to calculate the maximum path sum for the left and right subtrees of each node.
2. Update the overall maximum path sum `maxi` if the sum of the current node's value and the maximum path sums of its left and right subtrees is greater than the current value of `maxi`.
3. Return the maximum path sum considering only one branch (either left or right) along with the current node's value.
4. The main function `maxPathSum` initializes `maxi` to the minimum possible integer value and calls the recursive function `findMaxPathSum`.

CODE:
*/

// Node structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Recursive function to find the maximum path sum
// for a given subtree rooted at 'root'
// The variable 'maxi' is a reference parameter
// updated to store the maximum path sum encountered
int findMaxPathSum(Node* root, int &maxi) {
    // Base case: If the current node is null, return 0
    if (root == nullptr) {
        return 0;
    }

    // Calculate the maximum path sum
    // for the left and right subtrees
    int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));
    int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));

    // Update the overall maximum
    // path sum including the current node
    maxi = max(maxi, leftMaxPath + rightMaxPath + root->data);

    // Return the maximum sum considering
    // only one branch (either left or right)
    // along with the current node
    return max(leftMaxPath, rightMaxPath) + root->data;
}

// Function to find the maximum
// path sum for the entire binary tree
int maxPathSum(Node* root) {
    // Initialize maxi to the
    // minimum possible integer value
    int maxi = INT_MIN; 
    // Call the recursive function to
    // find the maximum path sum
    findMaxPathSum(root, maxi);
    // Return the final maximum path sum
    return maxi; 
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the tree. Each node is processed once.

SPACE COMPLEXITY:
- O(h), where h is the height of the tree. This is the space used by the system call stack during the recursion.
*/
