/*
QUESTION:
Implement a stack data structure using a singly linked list. The stack should support the following operations:
1. Push an element onto the stack.
2. Pop an element from the stack.
3. Retrieve the top element of the stack.
4. Check if the stack is empty.
5. Retrieve the size of the stack.
6. Print the elements of the stack.

Example:
stack s;
s.stackPush(10);
s.stackPush(20);
int topElement = s.stackPeek(); // topElement should be 20
int poppedElement = s.stackPop(); // poppedElement should be 20
int size = s.stackSize(); // size should be 1
bool isEmpty = s.stackIsEmpty(); // isEmpty should be false
s.printStack(); // should print 10

APPROACH:
1. Use a singly linked list to implement the stack.
2. Maintain a pointer `top` to track the top element of the stack.
3. Provide methods for pushing, popping, retrieving the top element, checking if the stack is empty, retrieving the size of the stack, and printing the stack.

CODE:
*/

#include <iostream>
using namespace std;

struct stackNode {
    int data;
    stackNode* next;
    stackNode(int d) {
        data = d;
        next = NULL;
    }
};

struct stack {
    stackNode* top;
    int size;

    stack() {
        top = NULL;
        size = 0;
    }

    // Function to push an element onto the stack
    void stackPush(int x) {
        stackNode* element = new stackNode(x);
        element->next = top;
        top = element;
        cout << "Element pushed" << "\n";
        size++;
    }

    // Function to pop an element from the stack
    int stackPop() {
        if (top == NULL) {
            cout << "Stack is empty" << "\n";
            return -1;
        }
        int topData = top->data;
        stackNode* temp = top;
        top = top->next;
        delete temp;
        size--;
        return topData;
    }

    // Function to retrieve the size of the stack
    int stackSize() {
        return size;
    }

    // Function to check if the stack is empty
    bool stackIsEmpty() {
        return top == NULL;
    }

    // Function to retrieve the top element of the stack
    int stackPeek() {
        if (top == NULL) {
            cout << "Stack is empty" << "\n";
            return -1;
        }
        return top->data;
    }

    // Function to print the elements of the stack
    void printStack() {
        stackNode* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

/*
TIME COMPLEXITY:
- Push: O(1)
- Pop: O(1)
- Peek: O(1)
- IsEmpty: O(1)
- Size: O(1)
- Print: O(N), where N is the number of elements in the stack

SPACE COMPLEXITY: O(N), where N is the number of elements in the stack.
*/