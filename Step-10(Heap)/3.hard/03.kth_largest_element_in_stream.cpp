/*
QUESTION:
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element. Implement the KthLargest class:
- KthLargest(int k, vector<int>& nums) Initializes the object with the integer k and the stream of integers nums.
- int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

Example:
Input:
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // returns 4
kthLargest.add(5); // returns 5
kthLargest.add(10); // returns 5
kthLargest.add(9); // returns 8
kthLargest.add(4); // returns 8

APPROACH:
1. Use a min-heap to store the k largest elements seen so far.
2. In the constructor, initialize the heap with the first k elements. If there are more than k elements, remove the smallest elements.
3. In the add function, add the new element to the heap. If the size of the heap exceeds k, remove the smallest element. The top of the heap is the kth largest element.

CODE:
*/

#include <vector>
#include <queue>

using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> heap;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        
        for (int num : nums) {
            heap.push(num);
            if (heap.size() > k) {
                heap.pop();
            }
        }
    }
    
    int add(int val) {
        heap.push(val);
        if (heap.size() > k) {
            heap.pop();
        }

        return heap.top();
    }
};

/*
TIME COMPLEXITY:
- The time complexity for the constructor is O(n log k), where n is the number of elements in nums. This is because we insert each element into the heap, and the heap size is maintained at most k.
- The time complexity for the add function is O(log k), because we insert the new element into the heap and maintain the heap size.

SPACE COMPLEXITY:
- The space complexity is O(k), because the heap will contain at most k elements.
*/
