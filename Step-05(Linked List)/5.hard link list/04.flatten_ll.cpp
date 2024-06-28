/*
QUESTION:
Given a linked list where each node has two pointers, 'next' and 'child', flatten the list such that all nodes appear in a single level with the 'child' pointers being flattened into the 'next' pointers.

Example:
Input: 
1 - 2 - 3 - 4
|   |
5   6
Output:
1 - 2 - 5 - 3 - 6 - 4

APPROACH:
1. Use a merge function to merge two lists based on their data values.
2. Recursively flatten the linked list using the merge function.
3. Handle the merging of nodes with 'child' pointers and their respective 'next' nodes.

CODE:
*/

struct Node {
    int data;
    Node* next;
    Node* child;
    Node(int x) : data(x), next(NULL), child(NULL) {}
};

// Function to merge two linked lists
Node* merge(Node* list1, Node* list2) {
    // Create a dummy node as a placeholder for the result
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    // Merge the lists based on data values
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        } else {
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL;
    }

    // Connect the remaining elements if any
    if (list1) {
        res->child = list1;
    } else {
        res->child = list2;
    }

    // Break the last node's link to prevent cycles
    if (dummyNode->child) {
        dummyNode->child->next = NULL;
    }

    return dummyNode->child;
}

// Function to flatten a linked list with child pointers
Node* flattenLinkedList(Node* head) {
    // If head is null or there is no next node, return head
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Recursively flatten the rest of the linked list
    Node* mergedHead = flattenLinkedList(head->next);
    head = merge(head, mergedHead);
    return head;
}

/*
TIME COMPLEXITY:
- O(n) for flattening the linked list since we traverse each node a constant number of times.

SPACE COMPLEXITY:
- O(1) for additional space used excluding the space for the merged nodes themselves.

EXAMPLE USAGE:
Node* head = new Node(1);
head->child = new Node(2);
head->child->child = new Node(3);
Node* flattenedList = flattenLinkedList(head);
// The flattened list should be 1 -> 2 -> 3.
*/
