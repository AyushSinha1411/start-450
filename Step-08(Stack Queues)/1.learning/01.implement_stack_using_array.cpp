/*
QUESTION:
Implement a basic stack data structure with the following operations:
1. Push an element onto the stack.
2. Pop an element from the stack.
3. Retrieve the top element of the stack.
4. Retrieve the size of the stack.

Example:
Stack s;
s.push(10);
s.push(20);
int topElement = s.Top(); // topElement should be 20
int poppedElement = s.pop(); // poppedElement should be 20
int size = s.Size(); // size should be 1

APPROACH:
1. Use an array to store the stack elements.
2. Maintain a variable `top` to track the index of the top element.
3. Provide methods for pushing, popping, retrieving the top element, and retrieving the size of the stack.

CODE:
*/

#include <iostream>
using namespace std;

class Stack {
    int size;
    int* arr;
    int top;

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1;
        size = 1000;
        arr = new int[size];
    }

    // Function to push an element onto the stack
    void push(int x) {
        if (top < size - 1) {
            top++;
            arr[top] = x;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    // Function to pop an element from the stack
    int pop() {
        if (top >= 0) {
            int x = arr[top];
            top--;
            return x;
        } else {
            cout << "Stack underflow" << endl;
            return -1; // Indicate an error condition
        }
    }

    // Function to retrieve the top element of the stack
    int Top() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1; // Indicate an error condition
        }
    }

    // Function to retrieve the size of the stack
    int Size() {
        return top + 1;
    }

    // Destructor to clean up the allocated memory
    ~Stack() {
        delete[] arr;
    }
};

/*
TIME COMPLEXITY:
- Push: O(1)
- Pop: O(1)
- Top: O(1)
- Size: O(1)

SPACE COMPLEXITY: O(N), where N is the size of the stack.

*/

// Example usage
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    int topElement = s.Top(); // topElement should be 20
    int poppedElement = s.pop(); // poppedElement should be 20
    int size = s.Size(); // size should be 1

    cout << "Top element: " << topElement << endl; // Output: Top element: 20
    cout << "Popped element: " << poppedElement << endl; // Output: Popped element: 20
    cout << "Current size of the stack: " << size << endl; // Output: Current size of the stack: 1

    return 0;
}
