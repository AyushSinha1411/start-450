/*
QUESTION:
Implement a basic queue data structure with the following operations:
1. Push an element onto the queue.
2. Pop an element from the queue.
3. Retrieve the front element of the queue.
4. Retrieve the size of the queue.

Example:
Queue q(5);
q.push(10);
q.push(20);
int frontElement = q.top(); // frontElement should be 10
int poppedElement = q.pop(); // poppedElement should be 10
int size = q.size(); // size should be 1

APPROACH:
1. Use an array to store the queue elements.
2. Maintain variables `start` and `end` to track the indices of the front and rear elements.
3. Provide methods for pushing, popping, retrieving the front element, and retrieving the size of the queue.
4. Use modular arithmetic to handle the circular nature of the queue.

CODE:
*/

#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int start;
    int end;
    int currSize;
    int maxSize;

public:
    // Constructor to initialize the queue with default size
    Queue() {
        maxSize = 16;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    // Constructor to initialize the queue with specified size
    Queue(int maxSize) {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    // Function to push an element onto the queue
    void push(int newElement) {
        if (currSize == maxSize) {
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }
        if (end == -1) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % maxSize;
        }
        arr[end] = newElement;
        cout << "The element pushed is " << newElement << endl;
        currSize++;
    }

    // Function to pop an element from the queue
    int pop() {
        if (start == -1) {
            cout << "Queue Empty\nExiting..." << endl;
            exit(1);
        }
        int popped = arr[start];
        if (currSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % maxSize;
        }
        currSize--;
        return popped;
    }

    // Function to retrieve the front element of the queue
    int top() {
        if (start == -1) {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }

    // Function to retrieve the size of the queue
    int size() {
        return currSize;
    }

    // Destructor to clean up the allocated memory
    ~Queue() {
        delete[] arr;
    }
};

/*
TIME COMPLEXITY:
- Push: O(1)
- Pop: O(1)
- Top: O(1)
- Size: O(1)

SPACE COMPLEXITY: O(N), where N is the size of the queue.
*/

// Example usage