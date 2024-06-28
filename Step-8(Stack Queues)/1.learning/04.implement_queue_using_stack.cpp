/*
QUESTION:
Implement a queue data structure using two stacks. The queue should support the following operations:
1. Push an element onto the queue.
2. Pop an element from the queue.
3. Retrieve the front element of the queue.
4. Retrieve the size of the queue.

Example:
Queue q;
q.Push(10);
q.Push(20);
int frontElement = q.Top(); // frontElement should be 10
int poppedElement = q.Pop(); // poppedElement should be 10
int size = q.size(); // size should be 1

APPROACH:
1. Use two stacks to implement the queue.
2. For the Push operation, move all elements from the input stack to the output stack, push the new element onto the input stack, and then move all elements back to the input stack.
3. For the Pop operation, pop the top element from the input stack.
4. For the Top operation, return the top element of the input stack.
5. For the size operation, return the size of the input stack.

CODE:
*/

#include <iostream>
#include <stack>
using namespace std;

struct Queue {
    stack<int> input, output;

    // Push elements into the queue
    void Push(int data) {
        // Move all elements from input stack to output stack
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        // Insert the new element into the input stack
        cout << "The element pushed is " << data << endl;
        input.push(data);
        // Move all elements back to the input stack from the output stack
        while (!output.empty()) {
            input.push(output.top());
            output.pop();
        }
    }

    // Pop the element from the queue
    int Pop() {
        if (input.empty()) {
            cout << "Queue is empty" << endl;
            exit(1); // Indicate an error condition
        }
        int val = input.top();
        input.pop();
        return val;
    }

    // Return the front element of the queue
    int Top() {
        if (input.empty()) {
            cout << "Queue is empty" << endl;
            exit(1); // Indicate an error condition
        }
        return input.top();
    }

    // Return the size of the queue
    int size() {
        return input.size();
    }
};

/*
TIME COMPLEXITY:
- Push: O(N), where N is the number of elements in the queue.
- Pop: O(1)
- Top: O(1)
- Size: O(1)

SPACE COMPLEXITY: O(N), where N is the number of elements in the queue.
*/