// 13. 0/1 Knapsack Problem
// Topic: 0/1 Knapsack
// Description: Given weights and values, pick items to maximize value without exceeding capacity.
// Use memoization on (idx, remainingWeight). Input: n, capacity, then n pairs weight value Output:
// maximum value

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll knap(int idx, int W, const vector<int>& wt, const vector<int>& val, vector<vector<ll>>& memo)
{
    if (idx >= (int)wt.size() || W <= 0)
        return 0;
    if (memo[idx][W] != -1)
        return memo[idx][W];
    ll skip = knap(idx + 1, W, wt, val, memo);
    ll take = 0;
    if (wt[idx] <= W)
        take = val[idx] + knap(idx + 1, W - wt[idx], wt, val, memo);
    memo[idx][W] = max(skip, take);
    return memo[idx][W];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, W;
    if (!(cin >> n >> W))
        return 0;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; ++i) cin >> wt[i] >> val[i];
    vector<vector<ll>> memo(n, vector<ll>(W + 1, -1));
    cout << knap(0, W, wt, val, memo) << '\n';
}

// Memoization process started in knap where memo[idx][W] caches optimal values for subproblems.
// Time Complexity: O(n * W)
// Space Complexity: O(n * W)
