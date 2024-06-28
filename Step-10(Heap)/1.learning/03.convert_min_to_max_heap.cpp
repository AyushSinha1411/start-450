/*
QUESTION:
Write functions to build a max-heap from a given array. The first function, `MaxHeapify`, heapifies a subtree with the root at a given index. The second function, `convertMaxHeap`, builds the max-heap from the array.

Example:
Input: arr = [3, 5, 9, 6, 8, 20, 10, 12, 18, 9]
Output: arr = [20, 18, 10, 12, 9, 9, 3, 5, 6, 8]

APPROACH:
1. The `MaxHeapify` function ensures that the subtree with root at index i is a max-heap.
   - Compare the root with its left and right children.
   - Swap the root with the largest of its children.
   - Recursively heapify the affected subtree.
2. The `convertMaxHeap` function builds a max-heap by calling `MaxHeapify` in a bottom-up manner.
   - Start from the last non-leaf node and move up to the root, heapifying each node.

CODE:
*/

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to heapify a subtree with root at given index
void MaxHeapify(int arr[], int i, int N) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < N && arr[l] > arr[i])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        MaxHeapify(arr, largest, N);
    }
}

// This function basically builds max heap
void convertMaxHeap(int arr[], int N) {
    // Start from bottommost and rightmost internal node
    // and heapify all internal nodes in bottom-up way
    for (int i = (N - 2) / 2; i >= 0; --i)
        MaxHeapify(arr, i, N);
}

/*
TIME COMPLEXITY:
- MaxHeapify: O(log N) where N is the number of elements in the subtree.
- convertMaxHeap: O(N) where N is the number of elements in the array, since it calls MaxHeapify for each internal node.

SPACE COMPLEXITY:
- MaxHeapify: O(log N) due to the recursive call stack.
- convertMaxHeap: O(1) as it uses a constant amount of extra space.
*/
