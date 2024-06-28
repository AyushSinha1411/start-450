/*
QUESTION:
Implement a Priority Queue class in C++ using a vector. The Priority Queue should support operations such as enqueue (insertion), dequeue (removal of the maximum element), peek (returning the maximum element), and count (returning the number of elements in the queue).

Example:
PriorityQueue<int> pq;
pq.Enqueue(10);
pq.Enqueue(20);
pq.Enqueue(15);
int maxElement = pq.Dequeue(); // maxElement should be 20
int currentMax = pq.Peek(); // currentMax should be 15
int size = pq.Count(); // size should be 2

APPROACH:
1. Use a vector to store the elements of the priority queue.
2. Implement the Enqueue function to insert elements and maintain the max-heap property.
3. Implement the Dequeue function to remove the maximum element and maintain the max-heap property.
4. Implement the Peek function to return the maximum element.
5. Implement the Count function to return the number of elements in the queue.

CODE:
*/

#include <vector>
using namespace std;

template<typename T>
class PriorityQueue {
private:
    vector<T> data;

public:
    // Constructor to initialize the Priority Queue
    PriorityQueue() {}

    // Function to insert an element into the Priority Queue
    void Enqueue(T item) {
        data.push_back(item);
        int ci = data.size() - 1;

        // Re-structure heap (Max Heap) so that after addition max element will lie on top of pq
        while (ci > 0) {
            int pi = (ci - 1) / 2;
            if (data[ci] <= data[pi])
                break;
            swap(data[ci], data[pi]);
            ci = pi;
        }
    }

    // Function to remove the maximum element from the Priority Queue
    T Dequeue() {
        int li = data.size() - 1;
        T frontItem = data[0];
        data[0] = data[li];
        data.pop_back();

        --li;
        int pi = 0;

        // Re-structure heap (Max Heap) so that after deletion max element will lie on top of pq
        while (true) {
            int ci = pi * 2 + 1;
            if (ci > li)
                break;
            int rc = ci + 1;
            if (rc <= li && data[rc] > data[ci])
                ci = rc;
            if (data[pi] >= data[ci])
                break;
            swap(data[pi], data[ci]);
            pi = ci;
        }
        return frontItem;
    }

    // Function to return the maximum element without removing it
    T Peek() {
        return data[0];
    }

    // Function to return the number of elements in the Priority Queue
    int Count() {
        return data.size();
    }
};

/*
TIME COMPLEXITY:
- Enqueue: O(log N), where N is the number of elements in the priority queue.
- Dequeue: O(log N), where N is the number of elements in the priority queue.
- Peek: O(1), as it only returns the top element.
- Count: O(1), as it returns the size of the vector.

SPACE COMPLEXITY:
- O(N), where N is the number of elements in the priority queue.
*/
