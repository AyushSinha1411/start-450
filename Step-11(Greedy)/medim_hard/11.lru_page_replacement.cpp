/*
QUESTION:
Given `N` pages and a cache capacity `C`, determine the number of page faults using the Least Recently Used (LRU) page replacement policy. A page fault occurs when a page is not in the cache, and we need to load it into the cache, possibly evicting another page if the cache is full.

Example:
Input: N = 7, C = 4, pages = [1, 2, 1, 3, 4, 5, 1]
Output: 5
Explanation:
1. Page 1 causes a fault.
2. Page 2 causes a fault.
3. Page 1 is already in cache.
4. Page 3 causes a fault.
5. Page 4 causes a fault.
6. Page 5 causes a fault, evicts 2 (least recently used).
7. Page 1 is already in cache.

APPROACH:
1. Use an unordered set to store the currently loaded pages in memory.
2. Use an unordered map to store the last index of each page.
3. Iterate through the pages:
   - If the page is not in memory and there's space, add it and count a page fault.
   - If the page is not in memory and there's no space, find and remove the least recently used page, then add the new page and count a page fault.
   - If the page is in memory, just update its index.
4. Return the total number of page faults.

CODE:
*/

#include <unordered_set>
#include <unordered_map>
using namespace std;

int pageFaults(int N, int C, int pages[]) {
    unordered_set<int> s; // Set to store the currently loaded pages
    unordered_map<int, int> indexes; // Map to store the index of each page
    int page_faults = 0; // Variable to store the number of page faults

    // Loop through all the pages
    for (int i = 0; i < N; i++) {
        // Check if there is still space in memory
        if (s.size() < C) {
            // Check if the page is already in memory
            if (s.find(pages[i]) == s.end()) {
                // If not, add the page to memory and increment page_faults
                s.insert(pages[i]);
                page_faults++;
            }
            // Store the current index of the page
            indexes[pages[i]] = i;
        }
        // If memory is full
        else {
            // Check if the page is already in memory
            if (s.find(pages[i]) == s.end()) {
                // Find the least recently used (LRU) page
                int lru = INT_MAX, val;
                for (auto it = s.begin(); it != s.end(); it++) {
                    if (indexes[*it] < lru) {
                        lru = indexes[*it];
                        val = *it;
                    }
                }
                // Remove the LRU page and add the current page
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
            // Update the index of the current page
            indexes[pages[i]] = i;
        }
    }
    // Return the total number of page faults
    return page_faults;
}

/*
TIME COMPLEXITY:
- O(N * C) for iterating through the pages and potentially searching for the least recently used page.

SPACE COMPLEXITY:
- O(C) for storing the pages in the cache.
- O(C) for storing the last index of each page in the cache.

EXAMPLE USAGE:
int pages[] = {1, 2, 1, 3, 4, 5, 1};
int N = 7, C = 4;
int result = pageFaults(N, C, pages);
// result will be 5
*/
