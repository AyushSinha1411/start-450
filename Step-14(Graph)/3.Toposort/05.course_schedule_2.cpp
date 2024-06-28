/*
QUESTION:
Given the number of courses (numCourses) and a list of prerequisite pairs (prerequisites), determine the order in which courses should be taken to complete all courses. If it is not possible to complete all courses, return an empty list.

APPROACH:
1. Build the adjacency list and calculate in-degrees for each course.
2. Use a queue to store courses with in-degree 0.
3. Perform BFS to process each course, reducing the in-degree of its dependent courses.
4. Append the courses in the order they are processed to form the topological order.
5. If the number of courses processed equals numCourses, return the topological order; otherwise, return an empty list.

CODE:
*/

#include <vector>
#include <queue>
#include <map>
#include <list>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Initialize the adjacency list and in-degree vector
        map<int, list<int>> adjList;
        vector<int> indegree(numCourses, 0);
        vector<int> topologicalOrder;

        // Create the adjacency list representation of the graph
        for (int i = 0; i < prerequisites.size(); i++) {
            int dest = prerequisites[i][0];
            int src = prerequisites[i][1];
            adjList[src].push_back(dest);
            // Record in-degree of each vertex
            indegree[dest]++;
        }

        // Add all vertices with 0 in-degree to the queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process until the queue becomes empty
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topologicalOrder.push_back(node);

            // Reduce the in-degree of each neighbor by 1
            if (adjList.count(node)) {
                for (auto neighbor : adjList[node]) {
                    indegree[neighbor]--;
                    // If in-degree of a neighbor becomes 0, add it to the queue
                    if (indegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
        }

        // Check to see if topological sort is possible or not
        if (topologicalOrder.size() == numCourses) {
            return topologicalOrder;
        }

        return vector<int>();
    }
};

/*
EXAMPLE USAGE:
int numCourses = 4;
vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
Solution sol;
vector<int> courseOrder = sol.findOrder(numCourses, prerequisites);
// Output: [0, 1, 2, 3] (or any valid topological order)

TIME COMPLEXITY:
- O(V + E), where V is the number of courses and E is the number of prerequisite pairs. Each course and prerequisite pair is processed once.

SPACE COMPLEXITY:
- O(V + E), for the adjacency list and in-degree array.
*/
