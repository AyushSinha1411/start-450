/*
QUESTION:
Given a list of email accounts, where each account is represented as a list of strings with the first element being the name and the remaining elements being email addresses, merge accounts with the same email addresses.

APPROACH:
1. Create a Disjoint Set data structure to represent connected components.
2. Iterate through each account and create a mapping of email addresses to account nodes in the disjoint set.
3. Union each account's nodes that share the same email address.
4. After processing all accounts, group the merged email addresses for each connected component.
5. Sort the groups and return the merged accounts.

CODE:
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    // Constructor to initialize Disjoint Set
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        // Initialize each node as a separate set
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Find the parent of a node with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Union by rank to merge two sets
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        // If they belong to the same set, no need to merge
        if (ulp_u == ulp_v) return;
        // Union by rank to maintain balance
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Union by size to merge two sets
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        // If they belong to the same set, no need to merge
        if (ulp_u == ulp_v) return;
        // Union by size to merge smaller set into larger set
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n = details.size();
        // Create a Disjoint Set with enough capacity to hold accounts
        DisjointSet ds(n);
        // Sort the accounts based on name for consistent processing
        sort(details.begin(), details.end());
        unordered_map<string, int> mapMailNode;
        // Process each account
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                string mail = details[i][j];
                // If the email address is not already mapped to an account, map it to the current account node
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                }
                // Otherwise, union the current account node with the node corresponding to the email address
                else {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        // Group merged email addresses for each connected component
        vector<string> mergedMail[n];
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        // Prepare merged accounts
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0) continue;
            // Sort email addresses within each account for consistency
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]); // Add the name to the account
            for (auto it : mergedMail[i]) {
                temp.push_back(it); // Add email addresses to the account
            }
            ans.push_back(temp);
        }
        // Sort merged accounts for consistent output
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
TIME COMPLEXITY:
- O(N * M * log(M)), where N is the number of accounts, and M is the average number of emails per account. Sorting the accounts and email addresses accounts for the dominant time complexity.

SPACE COMPLEXITY:
- O(N + M), where N is the number of accounts and M is the number of unique email addresses. Additional space is required for the Disjoint Set and the unordered map.

EXAMPLE USAGE:
Solution sol;
vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
vector<vector<string>> result = sol.accountsMerge(accounts);
// result will contain merged accounts.
*/
