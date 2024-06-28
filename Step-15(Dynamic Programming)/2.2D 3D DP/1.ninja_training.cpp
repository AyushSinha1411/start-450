/*
EXAMPLE:
Input: n = 3, points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}}
Output: 210
Explanation: The maximum points are obtained by choosing the following activities:
- Day 1: Activity 2 (70 points)
- Day 2: Activity 3 (80 points)
- Day 3: Activity 3 (60 points)
Total points = 70 + 80 + 60 = 210

QUESTION:
Given a matrix points where points[i][j] represents the points a ninja can earn on the i-th day by performing the j-th activity, find the maximum points the ninja can earn. The ninja cannot perform the same activity on two consecutive days.

APPROACH:
1. Use dynamic programming to calculate the maximum points that can be earned.
2. Create a memoization table to store intermediate results for the recursive approach.
3. Use a space-optimized approach to reduce space complexity by only storing the current and previous day's results.

CODE:
*/

// Recursive approach with memoization
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
  // If the result for this day and last activity is already calculated, return it
  if (dp[day][last] != -1) return dp[day][last];

  // Base case: When we reach the first day (day == 0)
  if (day == 0) {
    int maxi = 0;
    // Calculate the maximum points for the first day by choosing an activity
    // different from the last one
    for (int i = 0; i <= 2; i++) {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }
    // Store the result in dp array and return it
    return dp[day][last] = maxi;
  }

  int maxi = 0;
  // Iterate through the activities for the current day
  for (int i = 0; i <= 2; i++) {
    if (i != last) {
      // Calculate the points for the current activity and add it to the
      // maximum points obtained so far (recursively calculated)
      int activity = points[day][i] + f(day - 1, i, points, dp);
      maxi = max(maxi, activity);
    }
  }

  // Store the result in dp array and return it
  return dp[day][last] = maxi;
}

// Function to find the maximum points for ninja training using recursive approach
int ninjaTrainingRecursive(int n, vector<vector<int>> &points) {
  // Create a memoization table (dp) to store intermediate results
  vector<vector<int>> dp(n, vector<int>(4, -1));
  // Start the recursive calculation from the last day with no previous activity
  return f(n - 1, 3, points, dp);
}

// Function to find the maximum points for ninja training using tabulation approach
int ninjaTrainingTabulation(int n, vector<vector<int>>& points) {
  // Create a 2D DP (Dynamic Programming) table to store the maximum points
  // dp[i][j] represents the maximum points at day i, considering the last activity as j
  vector<vector<int>> dp(n, vector<int>(4, 0));

  // Initialize the DP table for the first day (day 0)
  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  // Iterate through the days starting from day 1
  for (int day = 1; day < n; day++) {
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0;
      // Iterate through the tasks for the current day
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          // Calculate the points for the current activity and add it to the
          // maximum points obtained on the previous day (recursively calculated)
          int activity = points[day][task] + dp[day - 1][task];
          // Update the maximum points for the current day and last activity
          dp[day][last] = max(dp[day][last], activity);
        }
      }
    }
  }

  // The maximum points for the last day with any activity can be found in dp[n-1][3]
  return dp[n - 1][3];
}

// Function to find the maximum points for ninja training using space-optimized approach
int ninjaTrainingOptimized(int n, vector<vector<int>>& points) {
  // Initialize a vector to store the maximum points for the previous day's activities
  vector<int> prev(4, 0);

  // Initialize the DP table for the first day (day 0)
  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  // Iterate through the days starting from day 1
  for (int day = 1; day < n; day++) {
    // Create a temporary vector to store the maximum points for the current day's activities
    vector<int> temp(4, 0);
    for (int last = 0; last < 4; last++) {
      temp[last] = 0;
      // Iterate through the tasks for the current day
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          // Calculate the points for the current activity and add it to the
          // maximum points obtained on the previous day (stored in prev)
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }
    // Update prev with the maximum points for the current day
    prev = temp;
  }

  // The maximum points for the last day with any activity can be found in prev[3]
  return prev[3];
}

/*
TIME COMPLEXITY:
- All approaches: O(n * 3) = O(n), where n is the number of days. Each day is processed with up to 3 activities.

SPACE COMPLEXITY:
- Recursive approach with memoization: O(n * 4) for the dp array.
- Tabulation approach: O(n * 4) for the dp array.
- Space-optimized approach: O(4) for the current and previous day's results.

EXAMPLE USAGE:
vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
int n = points.size();
int resultRecursive = ninjaTrainingRecursive(n, points); // Maximum points using recursive approach
int resultTabulation = ninjaTrainingTabulation(n, points); // Maximum points using tabulation approach
int resultOptimized = ninjaTrainingOptimized(n, points); // Maximum points using space-optimized approach
*/
