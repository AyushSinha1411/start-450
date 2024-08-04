// Question: Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. 
// If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
// Example:
// Input: g = [1, 2, 3], s = [1, 1]
// Output: 1
// Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
// And even though you have 2 cookies, since their size is 1, you could only make the child whose greed factor is 1 content.
// You need to output 1.
// Approach:
// We use the greedy algorithm to maximize the number of content children by sorting both the greed factor and the cookie size arrays. 
// We then use two pointers to iterate through both arrays, and for each cookie, we check if it can satisfy the current child's greed. 
// If it can, we move to the next child; otherwise, we move to the next cookie.
// Time Complexity: O(n log n + m log m), where n is the number of children and m is the number of cookies. Sorting both arrays dominates the time complexity.
// Space Complexity: O(1), since we are using a fixed number of extra variables.

#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& greed, vector<int>& size) {
    int n = greed.size(); // Number of children
    int m = size.size();  // Number of cookies
    int l = 0, r = 0;     // Pointers for greed and size arrays
    int cnt = 0;          // Number of content children

    // Sort the greed factor array and the cookie size array
    sort(greed.begin(), greed.end());
    sort(size.begin(), size.end());

    // Iterate through both arrays
    while (l < n && r < m) {
        // If the current cookie can satisfy the current child
        if (greed[l] <= size[r]) {
            cnt++; // Increase the number of content children
            l++;   // Move to the next child
        }
        // Move to the next cookie
        r++;
    }

    return cnt; // Return the number of content children
}
