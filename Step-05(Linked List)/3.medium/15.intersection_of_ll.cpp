/*
QUESTION:
Given two singly linked lists, find if there is an intersection point between the two lists. If there is an intersection, return the intersecting node.

APPROACH:
1. Use two pointers, d1 and d2, initialized to the heads of the two lists.
2. Traverse the lists, switching pointers to the head of the other list when reaching the end.
3. The pointers will eventually meet at the intersection point if there is one, or at NULL if there is no intersection.

CODE:
*/

// Utility function to check presence of intersection
Node* intersectionPresent(Node* head1, Node* head2) {
    Node* d1 = head1;
    Node* d2 = head2;
    
    while (d1 != d2) {
        d1 = (d1 == NULL) ? head2 : d1->next;
        d2 = (d2 == NULL) ? head1 : d2->next;
    }
    
    return d1;
}

/*
TIME COMPLEXITY: O(N + M), where N and M are the lengths of the two linked lists. This is because each pointer traverses each list at most twice.
SPACE COMPLEXITY: O(1), as we are using constant extra space.
*/
