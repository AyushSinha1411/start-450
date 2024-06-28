/*
QUESTION:
Given a singly linked list, delete the Nth node from the end of the list and return its head.

Example:
Input: head = [1, 2, 3, 4, 5], N = 2
Output: head = [1, 2, 3, 5]
Explanation: The second node from the end is 4, so we remove it.

APPROACH:
1. Initialize two pointers, fastp and slowp, both pointing to the head.
2. Move the fastp pointer N nodes ahead.
3. If fastp becomes NULL, it means the Nth node from the end is the head, so return head->next.
4. Move both pointers until fastp reaches the end of the list.
5. The slowp pointer will now be just before the Nth node from the end. Adjust the pointers to delete the Nth node.
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

// Function to delete the Nth node from the end of the linked list
Node* DeleteNthNodefromEnd(Node* head, int N) {
    // Create two pointers, fastp and slowp
    Node* fastp = head;
    Node* slowp = head;

    // Move the fastp pointer N nodes ahead
    for (int i = 0; i < N; i++) {
        fastp = fastp->next;
    }

    // If fastp becomes NULL,
    // the Nth node from the end is the head
    if (fastp == NULL) {
        return head->next;
    }

    // Move both pointers until fastp reaches the end
    while (fastp->next != NULL) {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    // Delete the Nth node from the end
    Node* delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
}

/*

TIME COMPLEXITY: O(L), where L is the length of the linked list.
SPACE COMPLEXITY: O(1), as we are using constant extra space.
*/
