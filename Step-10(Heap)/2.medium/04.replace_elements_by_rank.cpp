/*
QUESTION:
Given an array of integers, replace each element with its rank in the array. The rank is determined by the sorted order of the unique elements in the array.

Example:
Input:
arr = [40, 10, 20, 30]
Output:
arr = [4, 1, 2, 3]

APPROACH:
1. Create a copy of the original array and sort it in non-decreasing order.
2. Use a map to assign ranks to each unique element in the sorted array.
3. Replace each element in the original array with its corresponding rank.

CODE:
*/

#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> replaceWithRank(vector<int> &arr, int N) {
    vector<int> sortedArr = arr; // Copy the original vector
    sort(sortedArr.begin(), sortedArr.end()); // Sort the copy in non-decreasing order

    map<int, int> rankMap;
    int rank = 1;

    // Populate the map with the rank of each element
    for (int num : sortedArr) {
        if (rankMap.find(num) == rankMap.end()) {
            rankMap[num] = rank++;
        }
    }

    // Replace each element in the original vector with its rank
    for (int &num : arr) {
        num = rankMap[num];
    }

    return arr;
}

/*
TIME COMPLEXITY:
- O(N log N), where N is the number of elements in the array.
  - Sorting the array takes O(N log N) time.
  - Populating the map and replacing elements with their ranks both take O(N) time.

SPACE COMPLEXITY:
- O(N), as we are using extra space to store the sorted array and the rank map.
*/
