/*
QUESTION:
Given an array of k sorted linked lists, merge them into one sorted linked list.

Example:
Input: 
k = 3
arr = [
    1 -> 4 -> 5,
    1 -> 3 -> 4,
    2 -> 6
]
Output:
1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

APPROACH:
1. Use a priority queue (min-heap) to keep track of the smallest element among the heads of the k lists.
2. Push the head nodes of all the k lists into the priority queue.
3. Extract the minimum element from the priority queue and add it to the result list.
4. If the extracted element has a next node, push it into the priority queue.
5. Repeat steps 3 and 4 until the priority queue is empty.
6. The result list will be the merged sorted list.

CODE:
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Define the structure of a Node
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node(data);
    return temp;
}

// Comparator function used to build up the priority queue
struct compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

// Function to merge k sorted linked lists
Node* mergeKSortedLists(Node* arr[], int K) {
    // Priority queue 'pq' implemented as min-heap with the help of 'compare' function
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Push the head nodes of all the k lists into 'pq'
    for (int i = 0; i < K; i++) {
        if (arr[i] != NULL) {
            pq.push(arr[i]);
        }
    }

    // Handles the case when k = 0 or lists have no elements in them
    if (pq.empty()) return NULL;

    Node* dummy = newNode(0);
    Node* last = dummy;

    // Loop until 'pq' is not empty
    while (!pq.empty()) {
        // Get the top element of 'pq'
        Node* curr = pq.top();
        pq.pop();

        // Add the top element of 'pq' to the resultant merged list
        last->next = curr;
        last = last->next;

        // Check if there is a node next to the 'top' node in the list
        // of which 'top' node is a member
        if (curr->next != NULL) {
            // Push the next node of the top node into 'pq'
            pq.push(curr->next);
        }
    }

    // Address of head node of the required merged list
    return dummy->next;
}

/*
TIME COMPLEXITY:
- O(N log k), where N is the total number of nodes in all lists and k is the number of lists.
  - Pushing and popping from the priority queue (min-heap) takes O(log k) time, and we do this N times.

SPACE COMPLEXITY:
- O(k), as the priority queue stores at most k nodes at any given time.
*/
