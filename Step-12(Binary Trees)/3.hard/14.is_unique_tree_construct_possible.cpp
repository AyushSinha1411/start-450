/*
QUESTION:
Given two traversal representations of a binary tree where each traversal is represented with an integer (preorder - 1, inorder - 2, postorder - 3), determine if it is possible to have a valid binary tree from these traversals.

The valid combinations are:
- Preorder (1) and Inorder (2)
- Preorder (1) and Postorder (3)
- Inorder (2) and Postorder (3)

EXAMPLE USAGE:
bool result1 = isPossible(1, 2); // true, Preorder and Inorder
bool result2 = isPossible(1, 3); // true, Preorder and Postorder
bool result3 = isPossible(2, 3); // true, Inorder and Postorder
bool result4 = isPossible(1, 1); // false, both are Preorder
bool result5 = isPossible(2, 2); // false, both are Inorder

APPROACH:
1. The function takes two integers representing two traversal methods.
2. Check if the sum of the two integers is either 3 or 5, indicating a valid combination.
3. Return true if it's a valid combination, otherwise return false.

CODE:
*/

bool isPossible(int a, int b) {
    // Check if the sum of the two integers is 3 or 5
    return (a + b == 3) || (a + b == 5);
}

/*
EXAMPLE USAGE:
int main() {
    cout << boolalpha; // to print boolean values as true/false
    cout << "1 and 2: " << isPossible(1, 2) << endl; // Output: true
    cout << "1 and 3: " << isPossible(1, 3) << endl; // Output: true
    cout << "2 and 3: " << isPossible(2, 3) << endl; // Output: true
    cout << "1 and 1: " << isPossible(1, 1) << endl; // Output: false
    cout << "2 and 2: " << isPossible(2, 2) << endl; // Output: false
    return 0;
}

/*
TIME COMPLEXITY:
- O(1), constant time complexity as the function performs a simple arithmetic check.

SPACE COMPLEXITY:
- O(1), constant space complexity as no additional space is used.
*/
