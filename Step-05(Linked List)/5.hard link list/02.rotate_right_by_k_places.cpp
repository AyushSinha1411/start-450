/*
QUESTION:
Given a linked list, rotate the list to the right by k places, where k is non-negative. This means shifting elements from the end of the list to the front.

Example:
Input: 1 -> 2 -> 3 -> 4 -> 5, k = 2
Output: 4 -> 5 -> 1 -> 2 -> 3

APPROACH:
1. Calculate the length of the list.
2. Link the last node to the first node to form a circular list.
3. Calculate the effective number of rotations needed.
4. Traverse the list to find the new end node.
5. Break the circular link to form the new list.

CODE:
*/

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to rotate the linked list to the right by k places
Node* rotateRight(Node* head, int k) {
    // Base cases: empty list, single node list, or zero rotations
    if (head == NULL || head->next == NULL || k == 0) return head;

    // Calculate the length of the list
    Node* temp = head;
    int length = 1;
    while (temp->next != NULL) {
        ++length;
        temp = temp->next;
    }

    // Link last node to first node to form a circular list
    temp->next = head;

    // Compute the effective rotations needed
    k = k % length;
    int end = length - k;

    // Traverse to the new end of the list
    while (end--) {
        temp = temp->next;
    }

    // Break the circular link to form the new list
    head = temp->next;
    temp->next = NULL;

    return head;
}

/*
TIME COMPLEXITY:
- O(n) for calculating the length of the list and traversing to the new end node.

SPACE COMPLEXITY:
- O(1) for additional space used, excluding the space for the nodes themselves.

EXAMPLE USAGE:
Node* head = new Node(1);
head->next = new Node(2);
head->next->next = new Node(3);
head->next->next->next = new Node(4);
head->next->next->next->next = new Node(5);
Node* rotatedList = rotateRight(head, 2);
// The modified list should be 4 -> 5 -> 1 -> 2 -> 3.
*/
