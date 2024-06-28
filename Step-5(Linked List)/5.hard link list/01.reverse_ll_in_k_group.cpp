/*
QUESTION:
Given a linked list, reverse the nodes in groups of K and return the modified list. If the number of nodes is not a multiple of K, then the remaining nodes in the end should remain as it is.

Example:
Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8, K = 3
Output: 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7 -> 8

APPROACH:
1. Traverse the linked list in groups of K nodes.
2. For each group, reverse the nodes within the group.
3. Adjust the pointers to link the reversed groups.
4. If the number of remaining nodes is less than K, leave them as is.

CODE:
*/

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to reverse a linked list
Node* reverseLinkedList(Node* head) {
    Node* temp = head;  // Initialize 'temp' at head of linked list
    Node* prev = NULL;  // Initialize pointer 'prev' to NULL, representing the previous node

    // Traverse the list, continue till 'temp' reaches the end (NULL)
    while (temp != NULL) {  
        Node* front = temp->next;  // Store the next node in 'front' to preserve the reference
        temp->next = prev;  // Reverse the direction of the current node's 'next' pointer to point to 'prev'
        prev = temp;  // Move 'prev' to the current node for the next iteration
        temp = front;  // Move 'temp' to the 'front' node advancing the traversal
    }

    return prev;  // Return the new head of the reversed linked list
}

// Function to get the Kth node from a given position in the linked list
Node* getKthNode(Node* temp, int k) {
    k -= 1;  // Decrement K as we already start from the 1st node

    // Decrement K until it reaches the desired position
    while (temp != NULL && k > 0) {
        k--;  // Decrement k as temp progresses
        temp = temp->next;  // Move to the next node
    }

    return temp;  // Return the Kth node
}

// Function to reverse nodes in groups of K
Node* kReverse(Node* head, int k) {
    Node* temp = head;  // Initialize a temporary node to traverse the list
    Node* prevLast = NULL;  // Initialize a pointer to track the last node of the previous group

    // Traverse through the linked list
    while (temp != NULL) {
        Node* kThNode = getKthNode(temp, k);  // Get the Kth node of the current group

        // If the Kth node is NULL (not a complete group)
        if (kThNode == NULL) {
            if (prevLast) {
                prevLast->next = temp;  // If there was a previous group, link the last node to the current node
            }
            break;  // Exit the loop
        }

        Node* nextNode = kThNode->next;  // Store the next node after the Kth node
        kThNode->next = NULL;  // Disconnect the Kth node to prepare for reversal
        reverseLinkedList(temp);  // Reverse the nodes from temp to the Kth node

        // Adjust the head if the reversal starts from the head
        if (temp == head) {
            head = kThNode;
        } else {
            prevLast->next = kThNode;  // Link the last node of the previous group to the reversed group
        }

        prevLast = temp;  // Update the pointer to the last node of the previous group
        temp = nextNode;  // Move to the next group
    }

    return head;  // Return the head of the modified linked list
}

/*
TIME COMPLEXITY:
- O(n) for traversing and reversing the linked list nodes.

SPACE COMPLEXITY:
- O(1) for additional space used, excluding the space for the nodes themselves.

EXAMPLE USAGE:
Node* head = new Node(1);
head->next = new Node(2);
head->next->next = new Node(3);
Node* reversedList = kReverse(head, 3);
// The modified list should be 3 -> 2 -> 1.
*/
