/*
QUESTION:
Implement a Min-Heap using an array. The Min-Heap should support operations such as insert, extract min, decrease key, get min, and delete an element at a given index.

Example:
BinaryHeap heap(10);
heap.Insert(10);
heap.Insert(20);
heap.Insert(15);
int minElement = heap.ExtractMin(); // minElement should be 10
heap.Decreasekey(1, 5); // decrease the value of the element at index 1 to 5
int currentMin = heap.getMin(); // currentMin should be 5
heap.Delete(1); // delete the element at index 1
heap.print(); // should print the current heap elements

APPROACH:
1. Use an array to store the elements of the Min-Heap.
2. Implement the parent, left, and right functions to navigate the heap.
3. Implement the Insert function to add elements and maintain the heap property.
4. Implement the Heapify function to maintain the heap property after extraction.
5. Implement the ExtractMin function to remove the minimum element and maintain the heap property.
6. Implement the Decreasekey function to decrease the value of an element and maintain the heap property.
7. Implement the Delete function to remove an element at a given index.
8. Implement the getMin function to return the minimum element.

CODE:
*/

#include <iostream>
#include <climits>
using namespace std;

class BinaryHeap {
public:
    int capacity; // Maximum elements that can be stored in heap
    int size; // Current number of elements in heap
    int *arr; // Array for storing the keys

    BinaryHeap(int cap) {
        capacity = cap; // Assigning the capacity
        size = 0; // Initially size of heap is zero
        arr = new int[capacity]; // Creating an array
    }

    // Returns the parent of the ith Node
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Returns the left child of the ith Node
    int left(int i) {
        return 2 * i + 1;
    }

    // Returns the right child of the ith Node
    int right(int i) {
        return 2 * i + 2;
    }

    // Insert a new key x
    void Insert(int x) {
        if (size == capacity) {
            cout << "Binary Heap Overflow" << endl;
            return;
        }
        arr[size] = x; // Insert new element at end
        int k = size; // Store the index for checking heap property
        size++; // Increase the size

        // Fix the min heap property
        while (k != 0 && arr[parent(k)] > arr[k]) {
            swap(&arr[parent(k)], &arr[k]);
            k = parent(k);
        }
    }

    // Function to maintain the heap property
    void Heapify(int ind) {
        int ri = right(ind); // Right child
        int li = left(ind); // Left child
        int smallest = ind; // Initially assume violated value in Min value
        if (li < size && arr[li] < arr[smallest])
            smallest = li;
        if (ri < size && arr[ri] < arr[smallest])
            smallest = ri;
        // Smallest will store the minvalue index
        // If the Minimum among the three nodes is the parent itself,
        // that is Heap property satisfied so stop else call function recursively on Minvalue node
        if (smallest != ind) {
            swap(&arr[ind], &arr[smallest]);
            Heapify(smallest);
        }
    }

    // Returns the minimum element from the heap
    int getMin() {
        return arr[0];
    }

    // Extract the minimum element from the heap
    int ExtractMin() {
        if (size <= 0)
            return INT_MAX;
        if (size == 1) {
            size--;
            return arr[0];
        }
        int mini = arr[0];
        arr[0] = arr[size - 1]; // Copy last Node value to root Node value
        size--;
        Heapify(0); // Call heapify on root node
        return mini;
    }

    // Decreases the key value of a node
    void Decreasekey(int i, int val) {
        arr[i] = val; // Updating the new_val
        // Fixing the Min heap
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(&arr[parent(i)], &arr[i]);
            i = parent(i);
        }
    }

    // Deletes an element at index i
    void Delete(int i) {
        Decreasekey(i, INT_MIN);
        ExtractMin();
    }

    // Swaps two integer values
    void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    // Prints the elements of the heap
    void print() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

/*
TIME COMPLEXITY:
- Insert: O(log N), where N is the number of elements in the heap.
- ExtractMin: O(log N), where N is the number of elements in the heap.
- Decreasekey: O(log N), where N is the number of elements in the heap.
- Delete: O(log N), where N is the number of elements in the heap.
- getMin: O(1), as it only returns the top element.

SPACE COMPLEXITY:
- O(N), where N is the number of elements in the heap.
*/
