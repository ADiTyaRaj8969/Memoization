// 1. Fibonacci Numbers
// Topic: Fibonacci Numbers
// Description: Compute the nth Fibonacci number using recursion with memoization to avoid
// exponential recomputation. Input: n (integer >= 0) Output: nth Fibonacci number

#include <bits/stdc++.h>
using namespace std;

// Memoization starts here: using vector<long long> memo
long long fib(int n, vector<long long>& memo)
{
    if (n <= 1)
        return n;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<long long> memo(n + 1, -1);
    cout << fib(n, memo) << '\n';
    return 0;
}

// Memoization process started at the fib function where memo vector is checked and written.
// Time Complexity: O(n)
// Space Complexity: O(n) (memoization array + recursion stack)
