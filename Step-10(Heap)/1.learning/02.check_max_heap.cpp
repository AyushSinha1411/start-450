/*
QUESTION:
Write a function to determine if a given array represents a max-heap. The function should return true if the array represents a max-heap, otherwise false.

Example:
Input: arr = [10, 5, 3, 2, 4]
Output: true

Input: arr = [10, 5, 6, 2, 4]
Output: false

APPROACH:
1. The function takes three parameters: an array, the index of the current node, and the total number of elements in the array.
2. If the current node is a leaf node, return true.
3. If the current node is an internal node, check if it is greater than or equal to its left and right children.
4. Recursively check the left and right subtrees.
5. If all checks pass, return true. Otherwise, return false.

CODE:
*/

bool isHeap(int arr[], int i, int n) {
    // If (2 * i) + 1 >= n, then leaf node, so return true
    if (i >= (n - 1) / 2) 
        return true; 

    // If an internal node and is greater than its children,
    // and same is recursively true for the children
    if (arr[i] >= arr[2 * i + 1] &&  
        arr[i] >= arr[2 * i + 2] 
        && isHeap(arr, 2 * i + 1, n) 
        && isHeap(arr, 2 * i + 2, n)) 
        return true; 

    return false; 
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(H), where H is the height of the heap, due to the recursive call stack.
*/
