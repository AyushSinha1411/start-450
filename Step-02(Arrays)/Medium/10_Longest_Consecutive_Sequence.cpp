/*
QUESTION:
Given an array of integers, find the length of the longest consecutive elements sequence.

Example:
Input:
a = [100, 4, 200, 1, 3, 2]
Output:
The length of the longest consecutive elements sequence is: 4 (sequence: 1, 2, 3, 4)

APPROACH:
1. If the array is empty, return 0.
2. Initialize a variable longest to 1 to store the length of the longest sequence.
3. Create an unordered set to store unique elements of the array.
4. Iterate through the array and insert all elements into the set.
5. Iterate through the set:
   - For each element 'it' in the set, if 'it - 1' is not present in the set, it means 'it' is the starting number of a sequence.
   - Find consecutive numbers starting from 'it' and calculate the length of the sequence.
   - Update longest with the maximum of longest and the length of the current sequence.
6. Return longest, which contains the length of the longest consecutive elements sequence.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest consecutive elements sequence
int longestSuccessiveElements(vector<int>& a) {
    int n = a.size(); // Size of the array
    if (n == 0) return 0; // If array is empty, return 0

    int longest = 1; // Initialize longest with 1
    unordered_set<int> st; // Set to store unique elements of the array

    // Put all the array elements into the set
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    // Find the longest sequence
    for (auto it : st) {
        // If 'it' is a starting number
        if (st.find(it - 1) == st.end()) {
            // Find consecutive numbers
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt); // Update longest
        }
    }
    return longest; // Return the length of the longest consecutive elements sequence
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(N), as extra space is used for storing unique elements in the set.
*/
