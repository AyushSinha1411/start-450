/*
EXAMPLE:
Input: arr = {"a", "b", "ba", "bca", "bda", "bdca"}
Output: 4
Explanation: One of the longest possible word chains is ["a","ba","bda","bdca"].

QUESTION:
Given a list of words `arr`, find the length of the longest string chain. A string chain is a sequence of words such that each word is formed by inserting exactly one character into the previous word.

APPROACH:
1. Define a function `compare` to check if `s2` can be formed by removing one character from `s1`.
2. Define a function `comp` to sort strings by their lengths in ascending order.
3. Sort the array using `comp`.
4. Use dynamic programming to find the longest string chain.
5. Iterate through the sorted array and for each word, check all previous words to see if they can form a chain using the `compare` function.
6. Update the `dp` array to store the length of the longest chain ending at each word.
7. Return the maximum value in the `dp` array.

CODE:
*/

// Function to check if s2 can be formed by removing one character from s1
bool compare(string& s1, string& s2) {
    if (s1.size() != s2.size() + 1) return false;

    int first = 0;
    int second = 0;

    while (first < s1.size()) {
        if (second < s2.size() && s1[first] == s2[second]) {
            first++;
            second++;
        } else {
            first++;
        }
    }
    return first == s1.size() && second == s2.size();
}

// Comparator function to sort strings by their lengths in ascending order
bool comp(string& s1, string& s2) {
    return s1.size() < s2.size();
}

// Function to find the length of the longest string chain
int longestStrChain(vector<string>& arr) {
    int n = arr.size();

    // Sort the array
    sort(arr.begin(), arr.end(), comp);

    vector<int> dp(n, 1);
    int maxi = 1;

    for (int i = 0; i < n; i++) {
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (compare(arr[i], arr[prev_index]) && 1 + dp[prev_index] > dp[i]) {
                dp[i] = 1 + dp[prev_index];
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

/*
TIME COMPLEXITY:
- O(n^2 * l), where n is the number of words in the array and l is the average length of the words. This is because we are comparing each word with all previous words and the comparison itself takes O(l) time.

SPACE COMPLEXITY:
- O(n), for the `dp` array.

EXAMPLE USAGE:
vector<string> arr = {"a", "b", "ba", "bca", "bda", "bdca"};
int result = longestStrChain(arr);
cout << result << endl;
// Output: 4
*/
