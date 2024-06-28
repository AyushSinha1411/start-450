/*
QUESTION:
Given the level of a complete binary tree, determine the number of nodes at that level.

EXAMPLE USAGE:
int level = 3;
int result = countNodes(level);
// result will hold the number of nodes at level 3, which is 4

APPROACH:
1. The number of nodes at level 'i' of a complete binary tree can be determined using the formula 2^(i-1).
2. Implement a function to calculate this value.

CODE:
*/

#include <cmath> // for pow function

// Function to count the number of nodes at level 'i' of a complete binary tree
int countNodes(int i) {
    // Using the formula 2^(i-1) to calculate the number of nodes at level 'i'
    return pow(2, i - 1);
}

/*
TIME COMPLEXITY:
- O(1) as the calculation involves only a single mathematical operation.

SPACE COMPLEXITY:
- O(1) as no additional space is required.
*/
