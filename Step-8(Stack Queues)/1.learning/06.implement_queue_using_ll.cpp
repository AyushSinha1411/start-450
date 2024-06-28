/*
QUESTION:
Implement a queue data structure using a singly linked list. The queue should support the following operations:
1. Enqueue an element onto the queue.
2. Dequeue an element from the queue.
3. Retrieve the front element of the queue.
4. Check if the queue is empty.
5. Retrieve the size of the queue.

Example:
Queue q;
q.Enqueue(10);
q.Enqueue(20);
int frontElement = q.Peek(); // frontElement should be 10
q.Dequeue(); // removes 10 from the queue
int size = q.size; // size should be 1
bool isEmpty = q.Empty(); // isEmpty should be false

APPROACH:
1. Use a singly linked list to implement the queue.
2. Maintain pointers `Front` and `Rare` to track the front and rear elements of the queue.
3. Provide methods for enqueuing, dequeuing, retrieving the front element, checking if the queue is empty, and retrieving the size of the queue.

CODE:
*/

#include <iostream>
using namespace std;

class QueueNode {
public:
    int val;
    QueueNode* next;
    QueueNode(int data) {
        val = data;
        next = nullptr;
    }
};

QueueNode* Front = nullptr, *Rare = nullptr;

class Queue {
public:
    int size = 0;
    bool Empty();
    void Enqueue(int value);
    void Dequeue();
    int Peek();
};

// Function to check if the queue is empty
bool Queue::Empty() {
    return Front == nullptr;
}

// Function to retrieve the front element of the queue
int Queue::Peek() {
    if (Empty()) {
        cout << "Queue is Empty" << endl;
        return -1;
    } else {
        return Front->val;
    }
}

// Function to enqueue an element onto the queue
void Queue::Enqueue(int value) {
    QueueNode* Temp = new QueueNode(value);
    if (Temp == nullptr) { // When heap exhausted
        cout << "Queue is Full" << endl;
    } else {
        if (Front == nullptr) {
            Front = Temp;
            Rare = Temp;
        } else {
            Rare->next = Temp;
            Rare = Temp;
        }
        cout << value << " Inserted into Queue " << endl;
        size++;
    }
}

// Function to dequeue an element from the queue
void Queue::Dequeue() {
    if (Front == nullptr) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << Front->val << " Removed From Queue" << endl;
        QueueNode* Temp = Front;
        Front = Front->next;
        delete Temp;
        size--;
    }
}

/*
TIME COMPLEXITY:
- Enqueue: O(1)
- Dequeue: O(1)
- Peek: O(1)
- Empty: O(1)

SPACE COMPLEXITY: O(N), where N is the number of elements in the queue.
*/