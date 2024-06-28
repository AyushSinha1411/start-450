/*
QUESTION:
Write a function to identify the celebrity in a party. A celebrity is someone who is known by everyone but knows no one. Given a matrix M of size N x N representing people at the party, return the index of the celebrity if there is one, otherwise return -1.

Example:
Input: M = [[0, 1, 0],
            [0, 0, 0],
            [0, 1, 0]]
       n = 3
Output: 1
Explanation:
Person 1 is known by everyone else but knows no one. Hence, person 1 is the celebrity.

APPROACH:
1. Use two pointers, i and j, to find a candidate for the celebrity.
2. Initialize i to 0 and j to n-1.
3. While i is less than j:
   a. If j knows i, decrement j.
   b. Else, increment i.
4. The remaining candidate is at index i.
5. Verify if the candidate is a real celebrity by checking:
   a. The candidate is known by everyone.
   b. The candidate knows no one.
6. Return the candidate's index if they are a celebrity, otherwise return -1.

CODE:
*/

#include <vector>
using namespace std;
int N=1000;
// Function to identify the celebrity in a party
int celebrity(int M[N][N], int n) {
    int i = 0, j = n - 1;

    // Find the candidate for the celebrity
    while (i < j) {
        if (M[j][i] == 1) // j knows i, so j can't be the celebrity
            j--;
        else // j doesn't know i, so i can't be the celebrity
            i++;
    }

    // i points to our celebrity candidate
    int candidate = i;

    // Verify if the candidate is a real celebrity
    for (i = 0; i < n; i++) {
        if (i != candidate) {
            // The candidate should be known by everyone but should know no one
            if (M[i][candidate] == 0 || M[candidate][i] == 1)
                return -1;
        }
    }

    // The candidate is really a celebrity
    return candidate;
}

/*
TIME COMPLEXITY: O(N), where N is the number of people at the party. This is because we use two pointers to find the candidate and then perform a single scan to verify the candidate.
SPACE COMPLEXITY: O(1), as we are using only a few extra variables for calculations.
*/
