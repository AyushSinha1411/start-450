/*
QUESTION:
Given an integer n, calculate the nth Fibonacci number. The Fibonacci sequence is defined as:
- F(0) = 0
- F(1) = 1
- F(n) = F(n-1) + F(n-2) for n > 1

APPROACH:
1. Use memoization to store previously computed Fibonacci numbers.
2. Use an iterative approach to compute Fibonacci numbers up to n.
3. Use a space-optimized iterative approach to compute the nth Fibonacci number.

CODE:
*/

// Memoization approach to calculate the nth Fibonacci number
int f(int n, vector<int>& dp) {
    if (n <= 1) return n;

    // Check if the result is already computed
    if (dp[n] != -1) return dp[n];
    
    // Compute and store the result
    return dp[n] = f(n-1, dp) + f(n-2, dp);
}

int main() {
    int n = 5;

    // Initialize dp array for memoization approach
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    // Compute the Fibonacci number using memoization
    int fib_memo = f(n, dp);
    cout << "Fibonacci number using memoization: " << fib_memo << endl;

    // Tabulation approach to calculate the nth Fibonacci number
    vector<int> dp_tab(n + 1, -1);
    dp_tab[0] = 0;
    dp_tab[1] = 1;

    // Fill the dp array using iterative approach
    for (int i = 2; i <= n; i++) {
        dp_tab[i] = dp_tab[i - 1] + dp_tab[i - 2];
    }
    int fib_tab = dp_tab[n];
    cout << "Fibonacci number using tabulation: " << fib_tab << endl;

    // Space-optimized iterative approach to calculate the nth Fibonacci number
    int prev2 = 0;
    int prev = 1;

    // Compute the Fibonacci number using space optimization
    for (int i = 2; i <= n; i++) {
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    }
    int fib_space_opt = prev;
    cout << "Fibonacci number using space optimization: " << fib_space_opt << endl;

    return 0;
}

/*
TIME COMPLEXITY:
- Memoization: O(n), as each Fibonacci number is computed once.
- Tabulation: O(n), as it iterates from 2 to n.
- Space-optimized iterative approach: O(n), as it iterates from 2 to n.

SPACE COMPLEXITY:
- Memoization: O(n), for the dp array.
- Tabulation: O(n), for the dp array.
- Space-optimized iterative approach: O(1), as it uses only two variables.

EXAMPLE USAGE:
int n = 5;
vector<int> dp(n + 1, -1);
int fib_memo = f(n, dp); // Fibonacci number using memoization
int fib_tab = dp_tab[n]; // Fibonacci number using tabulation
int fib_space_opt = prev; // Fibonacci number using space optimization
*/
