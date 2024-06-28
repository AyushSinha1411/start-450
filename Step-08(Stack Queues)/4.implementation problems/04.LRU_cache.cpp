/*
QUESTION:
Implement a Least Recently Used (LRU) cache. The cache should be able to store key-value pairs and return the value for a given key. If the key is not present, return -1. The cache should also be able to add new key-value pairs and evict the least recently used key-value pair when the cache reaches its capacity.

Example:
LRUCache cache = new LRUCache(2); // capacity 2
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);    // returns 1
cache.put(3, 3); // evicts key 2
cache.get(2);    // returns -1 (not found)
cache.get(3);    // returns 3

APPROACH:
1. Use a doubly linked list to store the key-value pairs in the order of their usage.
2. Use an unordered_map to store the address of the nodes in the doubly linked list.
3. The most recently used node is always at the front of the list, and the least recently used node is always at the back.
4. When a key is accessed, move the corresponding node to the front of the list.
5. When a new key-value pair is added, add it to the front of the list. If the cache exceeds its capacity, remove the node at the back of the list.
6. Use the unordered_map to quickly find nodes in the list.

CODE:
*/

#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int cap;
    unordered_map<int, node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node* resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value) {
        if (m.find(key_) != m.end()) {
            node* existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key_, value));
        m[key_] = head->next;
    }
};

/*
TIME COMPLEXITY: O(1) for both get and put operations.
SPACE COMPLEXITY: O(capacity), where capacity is the maximum number of key-value pairs the cache can hold.
*/
