/*
QUESTION:
Given a sorted doubly linked list, remove all duplicates such that each element appears only once.

APPROACH:
1. Initialize two pointers, left and right, both pointing to the head of the list.
2. Traverse the list with the right pointer.
3. If the right pointer points to a node with the same value as the left pointer, move the right pointer to the next node.
4. If the right pointer points to a node with a different value, update the next pointer of the left node to the right node and the previous pointer of the right node to the left node.
5. Continue until the end of the list.
6. Set the next pointer of the last unique node to NULL.

CODE:
*/

#include <iostream>
using namespace std;

// Definition for doubly-linked list.
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

// Function to remove duplicates from a sorted doubly linked list
Node* removeDuplicates(Node* head) {
    // Initialize pointers
    Node* left = head;
    Node* right = head;
    
    // Traverse the list with the right pointer
    while (right) {
        // If right node is a duplicate, move right pointer to the next node
        if (right->data == left->data) {
            right = right->next;
        } else {
            // If right node is unique, update pointers
            left->next = right;
            right->prev = left;
            left = right;
        }
    }
    
    // Set the next pointer of the last unique node to NULL
    if (left->next != NULL) {
        left->next = NULL;
    }
    
    return head;
}

/*
TIME COMPLEXITY: O(N), where N is the number of nodes in the linked list. This is because we traverse the list once with the right pointer.
SPACE COMPLEXITY: O(1), as we are using constant extra space.
*/
