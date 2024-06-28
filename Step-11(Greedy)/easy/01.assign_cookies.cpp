/*
QUESTION:
Assume you are an awesome parent and want to give your children some cookies. 
But, you should give each child at most one cookie. Each child i has a greed factor g[i], 
which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. 
If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. 
Your goal is to maximize the number of your content children and output the maximum number.

Example:
Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child 
whose greed factor is 1 content.
You need to output 1.

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.

APPROACH:
1. Sort both the greed factors and the cookie sizes in ascending order.
2. Initialize two pointers, one for traversing the greed factors and one for the cookie sizes.
3. Traverse the greed factors and cookie sizes:
   a. If the current cookie size can satisfy the current greed factor, increase the count of content children.
   b. Move to the next child.
   c. Move to the next cookie.
4. Return the number of content children.

CODE:
*/

#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    // Sort the greed factors and cookie sizes in ascending order
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int contentChildren = 0;
    int cookieIndex = 0;

    // Traverse both arrays
    while (cookieIndex < s.size() && contentChildren < g.size()) {
        // If the current cookie can satisfy the current child
        if (s[cookieIndex] >= g[contentChildren]) {
            contentChildren++;
        }
        cookieIndex++;
    }
    return contentChildren;
}

/*
TIME COMPLEXITY:
- O(n log n + m log m) where n is the number of children and m is the number of cookies, 
  due to sorting both arrays.
- O(n + m) for the traversal of both arrays.

SPACE COMPLEXITY:
- O(1) for additional space usage.
*/
