/*
QUESTION:
Given an array 'skill' representing the skills of players in a team, find the number of teams where each team has players with skills in strictly increasing order.

Example:
Input:
skill = [3, 1, 5, 2, 4], n = 5
Output:
3 // Teams: [1, 2], [1, 2, 3], [1, 2, 3, 4, 5]

APPROACH:
1. Use merge sort to count the number of pairs where the skill of one player is more than twice the skill of another player.
2. In the countPairs function, while merging the sorted halves, count the number of pairs satisfying the condition arr[i] > 2 * arr[right].
3. Sum up the counts from each merge operation to get the total number of pairs.
4. This count represents the number of teams where one player has double the skill of another player.
5. Return this count as the result.

CODE:
*/

#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // if elements on the right half are still left
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transferring all elements from temporary to arr
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += countPairs(arr, low, mid, high); // counting pairs while merging sorted halves
    merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int team(vector <int> & skill, int n)
{
    return mergeSort(skill, 0, n - 1); // returns the count of teams
}

/*
TIME COMPLEXITY: O(n log n), where n is the size of the skill array, due to the merge sort algorithm.
SPACE COMPLEXITY: O(n), where n is the size of the skill array, for storing the temporary array during merge operation.
*/
