/*
Question: 
Given an array of sorted linked lists, merge them into a single sorted linked list. The array can contain multiple linked lists, and each linked list is sorted in non-decreasing order.

Example:
ListArray = [List1, List2, List3]
List1: 1 -> 4 -> 5
List2: 1 -> 3 -> 4
List3: 2 -> 6
Merged List: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

Approach:
1. Use a priority queue (min-heap) to keep track of the smallest elements of each linked list.
2. Initialize the priority queue with the first node of each list.
3. Extract the smallest element from the heap and append it to the merged list.
4. If the extracted element has a next node, insert the next node into the heap.
5. Repeat the process until the heap is empty.
6. Return the merged list starting from the node after the dummy node.

*/

Node* mergeKLists(vector<Node*> &listArray) {
    // Define a priority queue to store nodes with their values for comparison
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;

    // Initialize the priority queue with the first node of each list
    for (int i = 0; i < listArray.size(); i++) {
        if (listArray[i]) {
            pq.push({listArray[i]->data, listArray[i]});
        }
    }

    // Create a dummy node to help with the merged list
    Node* dummyNode = new Node(-1);
    // Temporary pointer to keep track of the current end of the merged list
    Node* temp = dummyNode;

    // Iterate while the priority queue is not empty
    while (!pq.empty()) {
        // Get the smallest element from the heap
        auto it = pq.top();
        pq.pop(); // Remove the smallest element from the heap

        // Link the smallest element to the merged list
        if (it.second -> next) { // If the smallest element has a next node
            pq.push({it.second -> next -> data, it.second -> next}); // Add the next node to the heap
        }
        // Move the temp pointer to the next node
        temp -> next = it.second;
        temp = temp -> next;
    }

    // Return the merged list starting from the node after the dummy node
    return dummyNode -> next;
}
/*Time Complexity: O(N log k), where N is the total number of nodes in all linked lists and k is the number of linked lists.
Space Complexity: O(k), where k is the number of linked lists (for the heap).
*/
