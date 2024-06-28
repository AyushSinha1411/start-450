/*
QUESTION:
Write a function to count the number of next greater elements (NGE) for each element in the given indices of the array. For each index in the indices vector, count how many elements to the right of the given index are greater than the element at that index.

Example:
Input: arr = [1, 3, 2, 4], indices = [0, 1, 2], n = 4, q = 3
Output: [3, 1, 1]
Explanation:
For index 0 (value 1), elements greater than 1 are [3, 2, 4] -> count is 3
For index 1 (value 3), elements greater than 3 are [4] -> count is 1
For index 2 (value 2), elements greater than 2 are [4] -> count is 1

APPROACH:
1. Iterate through the indices provided.
2. For each index, use a stack to find the next greater elements to the right of the given index.
3. Count the number of elements greater than the current element and store it in the result vector.
4. Return the result vector containing the counts of next greater elements for each index in the indices vector.

CODE:
*/

#include <vector>
#include <stack>
using namespace std;

// Function to count the number of next greater elements (NGE) for each element in the given indices of the array
vector<int> count_NGE(int n, vector<int>& arr, int q, vector<int>& indices) {
    vector<int> ans(q);
    
    for (int i = 0; i < q; i++) {
        int curr = arr[indices[i]];
        stack<int> st;
        int r = n - 1;

        // Iterate through elements to the right of the given index
        while (r > indices[i]) {
            if (arr[r] > curr) {
                st.push(arr[r]);
            }
            r--;
        }

        // Store the count of next greater elements
        ans[i] = st.size();
    }
    
    return ans;
}

/*
TIME COMPLEXITY: O(N * Q), where N is the length of the array and Q is the number of queries. This is because for each query, we iterate through the elements to the right of the given index.
SPACE COMPLEXITY: O(Q), for the result vector.
*/
