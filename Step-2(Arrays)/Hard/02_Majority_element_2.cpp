/*
QUESTION:
Given an array of integers, find all the elements that appear more than ⌊ n/3 ⌋ times, where n is the size of the array.

Example:
Input:
v = [3, 2, 3]
Output:
The majority elements in the array are: [3]

APPROACH:
1. Initialize variables cnt1 and cnt2 to store counts of elements, and el1 and el2 to store potential majority elements.
2. Apply Extended Boyer Moore's Voting Algorithm:
   a. Iterate through the array and update cnt1 and el1 if cnt1 is 0 and el2 is not equal to the current element.
   b. Update cnt2 and el2 if cnt2 is 0 and el1 is not equal to the current element.
   c. If the current element is equal to el1, increment cnt1. If it's equal to el2, increment cnt2. Otherwise, decrement cnt1 and cnt2.
3. Manually check if the stored elements in el1 and el2 are the majority elements.
4. Return a vector containing the majority elements.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

vector<int> majorityElement(vector<int> v) {
    int n = v.size(); // Size of the array

    int cnt1 = 0, cnt2 = 0; // Counts
    int el1 = INT_MIN, el2 = INT_MIN; // Potential majority elements

    // Apply Extended Boyer Moore's Voting Algorithm
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        } else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        } else if (v[i] == el1) {
            cnt1++;
        } else if (v[i] == el2) {
            cnt2++;
        } else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // List of answers

    // Manually check if the stored elements in el1 and el2 are the majority elements
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) {
            cnt1++;
        }
        if (v[i] == el2) {
            cnt2++;
        }
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) {
        ls.push_back(el1);
    }
    if (cnt2 >= mini) {
        ls.push_back(el2);
    }

    // Uncomment the following line if it is required to sort the answer array
    // sort(ls.begin(), ls.end()); // TC --> O(2*log2) ~ O(1);

    return ls; // Return the list of majority elements
}

/*
TIME COMPLEXITY: O(N), where N is the size of the array.
SPACE COMPLEXITY: O(1), as no extra space is used except for variables.
*/
