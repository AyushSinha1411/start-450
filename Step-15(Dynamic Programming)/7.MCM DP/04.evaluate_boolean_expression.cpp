/*
EXAMPLE:
Input: exp = "T|F&T^T"
Output: 5
Explanation: The number of ways to parenthesize the expression to get a true value is 5.

QUESTION:
Given a boolean expression string `exp` containing 'T' (true), 'F' (false), '&' (AND), '|' (OR), and '^' (XOR), find the number of ways to parenthesize the expression such that the result is true. The result should be modulo 1000000007.

APPROACH:
1. Use dynamic programming with memoization to solve the problem.
2. Define a recursive function `f` to calculate the number of ways to evaluate the expression between indices `i` and `j` to `isTrue`.
3. Base cases: 
   - If `i > j`, it's an invalid expression, return 0.
   - If `i == j`, evaluate the single character.
4. Use a DP table to store results of subproblems.
5. Iterate through the expression, partitioning it at each operator, and calculate the result based on the operator.
6. Return the result from the DP table.

CODE:
*/
//Recursive
// Define a long long type alias and the modulus constant
#define ll long long
const int mod = 1000000007;
int f(int i, int j, int isTrue, string &exp) {
    // Base case 1: If i > j, it's an invalid expression, return 0.
    if (i > j) return 0;
    
    // Base case 2: If i and j are the same, evaluate the single character.
    if (i == j) {
        if (isTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }
    
    ll ways = 0;
    
    // Iterate through the expression.
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        ll lT = f(i, ind - 1, 1, exp);  // Number of ways to make the left expression true.
        ll lF = f(i, ind - 1, 0, exp);  // Number of ways to make the left expression false.
        ll rT = f(ind + 1, j, 1, exp);  // Number of ways to make the right expression true.
        ll rF = f(ind + 1, j, 0, exp);  // Number of ways to make the right expression false.

        // Check the operator at the current index and update ways accordingly.
        if (exp[ind] == '&') {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|') {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else {  // XOR operator
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    return ways;
}

int evaluateExp(string &exp) {
    int n = exp.size();
    return f(0, n - 1, 1, exp);  // Start evaluation with isTrue set to true.
}

//Time Complexity: Exponential

// Memoization to calculate the number of ways to evaluate the expression
int f(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp) {
    if (i > j) return 0;
    if (i == j) {
        if (isTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    
    ll ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        ll lT = f(i, ind - 1, 1, exp, dp);
        ll lF = f(i, ind - 1, 0, exp, dp);
        ll rT = f(ind + 1, j, 1, exp, dp);
        ll rF = f(ind + 1, j, 0, exp, dp);

        if (exp[ind] == '&') {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|') {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}

// Function to evaluate the expression using the recursive approach
int evaluateExp(string &exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return f(0, n - 1, 1, exp, dp);
}

// Function to evaluate the expression using the tabulation approach
int evaluateExpTabulation(string &exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n - 1; j++) {
            if (i > j) continue;
            
            for (int isTrue = 0; isTrue <= 1; isTrue++) {
                if (i == j) {
                    if (isTrue == 1) dp[i][j][isTrue] = exp[i] == 'T';
                    else dp[i][j][isTrue] = exp[i] == 'F';
                    continue;
                }

                ll ways = 0;
                for (int ind = i + 1; ind <= j - 1; ind += 2) {
                    ll lT = dp[i][ind - 1][1];
                    ll lF = dp[i][ind - 1][0];
                    ll rT = dp[ind + 1][j][1];
                    ll rF = dp[ind + 1][j][0];

                    if (exp[ind] == '&') {
                        if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
                        else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
                    }
                    else if (exp[ind] == '|') {
                        if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
                        else ways = (ways + (lF * rF) % mod) % mod;
                    }
                    else {
                        if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
                        else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][n - 1][1];
}

/*
TIME COMPLEXITY:
- Both approaches: O(n^3), where n is the length of the expression, due to the nested loops and partitioning.

SPACE COMPLEXITY:
- Recursive approach with memoization: O(n^2) for the dp array.
- Tabulation approach: O(n^2) for the dp array.

EXAMPLE USAGE:
string exp = "T|F&T^T";
int resultMemoization = evaluateExp(exp); // Using memoization
int resultTabulation = evaluateExpTabulation(exp); // Using tabulation
cout << resultMemoization << endl; // Output: 5
cout << resultTabulation << endl; // Output: 5
*/
