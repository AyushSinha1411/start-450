/*
QUESTION:
Given the number of courses (numCourses) and a list of prerequisite pairs (prerequisites), determine if it is possible to finish all courses by checking for any cycle in the dependency graph.

APPROACH:
1. Build the adjacency list and calculate in-degrees for each course.
2. Use a queue to store courses with in-degree 0.
3. Perform BFS to process each course, reducing the in-degree of its dependent courses.
4. If the number of courses processed equals numCourses, it is possible to finish all courses; otherwise, there is a cycle.

CODE:
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to check if all courses can be finished
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Vector to store the in-degree of each course
        vector<int> indegree(numCourses, 0);
        // Adjacency list to store prerequisites
        vector<vector<int>> adj(numCourses);
        
        // Build the graph and calculate in-degrees
        for (auto& prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        // Queue to perform BFS
        queue<int> q;
        // Push all the courses with in-degree zero in the queue
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Variable to count the number of courses visited
        int nodesVisited = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            nodesVisited++;

            // Process all the neighbors of the current course
            for (auto& neighbor : adj[node]) {
                // Reduce the in-degree of the neighbor
                indegree[neighbor]--;
                // If in-degree becomes zero, add it to the queue
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If all courses have been visited, return true
        return nodesVisited == numCourses;
    }
};

/*
EXAMPLE USAGE:
int numCourses = 4;
vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
Solution sol;
bool canFinishCourses = sol.canFinish(numCourses, prerequisites);
// Output: true (since it is possible to finish all courses)

TIME COMPLEXITY:
- O(V + E), where V is the number of courses and E is the number of prerequisite pairs. Each course and prerequisite pair is processed once.

SPACE COMPLEXITY:
- O(V + E), for the adjacency list and in-degree array.
*/
