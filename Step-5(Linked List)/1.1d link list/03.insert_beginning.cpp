/*
QUESTION:
Define a singly linked list node class and implement functions to print the linked list and insert a new node at the beginning of the list.

APPROACH:
1. Define the ListNode class with a constructor to initialize the node's value and the next pointer.
2. Implement the PrintList function to traverse and print the linked list.
3. Implement the InsertatFirst function to insert a new node at the beginning of the list.

CODE:
*/

#include <iostream>
using namespace std;

// Definition of the ListNode class
class ListNode {
public:
    int val;          // Value of the node
    ListNode *next;   // Pointer to the next node

    // Constructor to initialize the node with a value and next pointer as NULL
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to print the linked list
void PrintList(ListNode *head) {
    // Initialize a pointer to traverse the list
    ListNode *curr = head;

    // Loop through the list until the end is reached
    for (; curr != NULL; curr = curr->next)
        cout << curr->val << "-->";  // Print the value of the current node

    // Print "null" to signify the end of the list
    cout << "null" << endl;
}

// Function to insert a new node at the beginning of the list
ListNode *InsertatFirst(int value, ListNode *head) {
    // Step 1: Create a new node with the given value
    ListNode *newnode = new ListNode(value);

    // Step 2: Point the next of the newly created node to the current head of the list
    newnode->next = head;

    // Step 3: Update the head to be the newly created node
    head = newnode;

    // Return the new head of the list
    return head;
}

/*
TIME COMPLEXITY:
- PrintList: O(n), where 'n' is the number of nodes in the linked list. Each node is visited once.
- InsertatFirst: O(1), since the insertion at the beginning of the list is a constant time operation.

SPACE COMPLEXITY:
- PrintList: O(1), as it uses a fixed amount of extra space for the current node pointer.
- InsertatFirst: O(1), as it uses a fixed amount of extra space for the new node pointer.
*/
