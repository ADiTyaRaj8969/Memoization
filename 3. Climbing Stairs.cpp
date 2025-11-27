// 3. Climbing Stairs
// Topic: Climbing Stairs
// Description: Count number of distinct ways to reach step n using recursion + memoization.
// Input: n (integer >= 0)
// Output: number of ways

#include <bits/stdc++.h>
using namespace std;

// Memoization starts here: vector<int> memo
int ways(int n, vector<int>& memo)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = ways(n - 1, memo) + ways(n - 2, memo);
    return memo[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<int> memo(n + 1, -1);
    cout << ways(n, memo) << '\n';
}

// Memoization process started inside ways function where memo vector is used.
// Time Complexity: O(n)
// Space Complexity: O(n)
