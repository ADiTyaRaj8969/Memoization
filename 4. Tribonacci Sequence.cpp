// 4. Tribonacci Sequence
// Topic: Tribonacci
// Description: Compute nth Tribonacci number using recursion + memoization.
// Input: n (integer >= 0)
// Output: nth Tribonacci number

#include <bits/stdc++.h>
using namespace std;

// Memoization starts here: vector<long long> memo
long long trib(int n, vector<long long>& memo)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = trib(n - 1, memo) + trib(n - 2, memo) + trib(n - 3, memo);
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
    cout << trib(n, memo) << '\n';
}

// Memoization process started in trib function where memo vector is accessed.
// Time Complexity: O(n)
// Space Complexity: O(n)
