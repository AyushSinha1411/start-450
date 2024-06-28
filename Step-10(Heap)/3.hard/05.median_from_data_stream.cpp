/*
QUESTION:
Design a data structure that supports the following two operations:
1. addNum(int num): Add an integer number from the data stream to the data structure.
2. findMedian(): Return the median of all elements so far.

Example:
Input:
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]

Output:
[null,null,null,1.5,null,2.0]

APPROACH:
1. Use two heaps:
   - A max-heap to store the smaller half of the elements.
   - A min-heap to store the larger half of the elements.
2. Maintain the balance of the heaps such that the difference in size between the two heaps is at most 1.
3. The median is the top element of the max-heap if the total number of elements is odd.
4. If the total number of elements is even, the median is the average of the top elements of both heaps.

CODE:
*/

#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // Stores the smaller half of elements
    priority_queue<int, vector<int>, greater<int>> minHeap; // Stores the larger half of elements

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // Add the number to the appropriate heap
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        // Rebalance the heaps if necessary
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            // If the number of elements is even, return the average of the two middle elements
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            // If the number of elements is odd, return the middle element
            return maxHeap.top();
        }
    }
};

/*
TIME COMPLEXITY:
- addNum(): O(log n) due to the insertion in the heap.
- findMedian(): O(1) as it just involves accessing the top elements of the heaps.

SPACE COMPLEXITY:
- The space complexity is O(n) where n is the number of elements added, as each element is stored in one of the heaps.
*/
