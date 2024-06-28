/*
QUESTION:
Implement a stack data structure using a single queue. The stack should support the following operations:
1. Push an element onto the stack.
2. Pop an element from the stack.
3. Retrieve the top element of the stack.
4. Retrieve the size of the stack.

Example:
Stack s;
s.Push(10);
s.Push(20);
int topElement = s.Top(); // topElement should be 20
int poppedElement = s.Pop(); // poppedElement should be 20
int size = s.Size(); // size should be 1

APPROACH:
1. Use a single queue to implement the stack.
2. For the Push operation, add the new element to the queue and then rotate the elements to maintain stack order.
3. For the Pop operation, remove the front element from the queue.
4. For the Top operation, return the front element of the queue.
5. For the Size operation, return the size of the queue.

CODE:
*/

#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:
    // Function to push an element onto the stack
    void Push(int x) {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Function to pop an element from the stack
    int Pop() {
        if (q.empty()) {
            cout << "Stack is empty\nExiting..." << endl;
            exit(1); // Indicate an error condition
        }
        int n = q.front();
        q.pop();
        return n;
    }

    // Function to retrieve the top element of the stack
    int Top() {
        if (q.empty()) {
            cout << "Stack is empty\nExiting..." << endl;
            exit(1); // Indicate an error condition
        }
        return q.front();
    }

    // Function to retrieve the size of the stack
    int Size() {
        return q.size();
    }
};

/*
TIME COMPLEXITY:
- Push: O(N), where N is the number of elements in the stack.
- Pop: O(1)
- Top: O(1)
- Size: O(1)

SPACE COMPLEXITY: O(N), where N is the number of elements in the stack.
*/