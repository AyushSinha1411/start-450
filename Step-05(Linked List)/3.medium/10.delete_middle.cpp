/*
QUESTION:
Given a singly linked list, delete the middle node of the linked list. If the list has an even number of nodes, delete the second middle node.

Example:
Input: head = [1, 2, 3, 4, 5]
Output: head = [1, 2, 4, 5]
Explanation: The middle node is 3, so we remove it.

Input: head = [1, 2, 3, 4, 5, 6]
Output: head = [1, 2, 3, 5, 6]
Explanation: The list has two middle nodes, 3 and 4, so we remove the second middle node 4.

APPROACH:
1. Check if the list is empty or has only one node. If true, return NULL.
2. Initialize slow and fast pointers, both pointing to the head.
3. Move the fast pointer twice as fast as the slow pointer to find the middle node.
4. When the fast pointer reaches the end, the slow pointer will be at the middle node.
5. Delete the middle node by skipping it.
6. Return the head of the modified list.

CODE:
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to delete the middle node of a linked list
Node* deleteMiddle(Node* head) {
    // If the list is empty or has only one node,
    // return NULL as there is no middle node to delete
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    // Initialize slow and fast pointers
    Node* slow = head;
    Node* fast = head->next->next;

    // Move 'fast' pointer twice as fast as 'slow'
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete the middle node by skipping it
    Node* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    
    return head;
}

/*

TIME COMPLEXITY: O(N), where N is the number of nodes in the linked list.
SPACE COMPLEXITY: O(1), as we are using constant extra space.
*/
