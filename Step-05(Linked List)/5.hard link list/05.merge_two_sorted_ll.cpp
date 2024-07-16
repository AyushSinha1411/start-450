/*
Question: 
Given two sorted linked lists, merge them into a single sorted linked list. The two input linked lists are assumed to be sorted in non-decreasing order.

Example:
List1: 1 -> 3 -> 5
List2: 2 -> 4 -> 6
Merged List: 1 -> 2 -> 3 -> 4 -> 5 -> 6

Approach:
1. Create two pointers, `t1` and `t2`, initialized to the heads of the two lists.
2. Create a dummy node to serve as the starting point of the merged list and a `temp` pointer to keep track of the current end of the merged list.
3. Iterate through both lists, comparing the data of the nodes pointed to by `t1` and `t2`.
4. Append the smaller node to the merged list and move the corresponding pointer (`t1` or `t2`) to the next node in its list.
5. Once one of the lists is exhausted, append the remaining nodes of the other list to the merged list.
6. Return the merged list starting from the node after the dummy node.

Time Complexity: O(n + m), where n and m are the lengths of the two lists.
Space Complexity: O(1), as we are not using any additional space other than the pointers.
*/

Node<int>* sortTwoLists(Node<int>* list1, Node<int>* list2) {
    // Initialize pointers to traverse the lists
    Node<int>* t1 = list1;
    Node<int>* t2 = list2;

    // Create a dummy node to help with the merged list
    Node<int>* dummyNode = new Node<int>(-1);

    // Temporary pointer to keep track of the current end of the merged list
    Node<int>* temp = dummyNode;

    // Iterate through both lists until one is exhausted
    while (t1 != NULL && t2 != NULL) {
        if (t1->data < t2->data) { // If the data in t1 is less than t2
            temp->next = t1; // Link temp to t1
            temp = t1; // Move temp to the next node
            t1 = t1->next; // Move t1 to the next node in its list
        } else { // If the data in t2 is less than or equal to t1
            temp->next = t2; // Link temp to t2
            temp = t2; // Move temp to the next node
            t2 = t2->next; // Move t2 to the next node in its list
        }
    }

    // If t1 is not exhausted, link the remaining nodes to the merged list
    if (t1 != NULL) temp->next = t1;
    else temp->next = t2; // If t2 is not exhausted, link the remaining nodes to the merged list

    // Return the merged list, starting from the node after the dummy node
    return dummyNode->next;
}
/*Time Complexity: O(n + m), where n and m are the lengths of the two lists.
Space Complexity: O(1), as we are not using any additional space other than the pointers.*/
