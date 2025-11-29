// 18. Burst Balloons
// Topic: Burst Balloons
// Description: Given nums[], burst balloons for max coins; use DP/memoization on intervals.
// Input: n followed by n integers
// Output: maximum coins

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(int l, int r, const vector<int>& a, vector<vector<ll>>& memo)
{
    if (l > r)
        return 0;
    if (memo[l][r] != -1)
        return memo[l][r];
    ll best = 0;
    for (int i = l; i <= r; ++i)
    {
        ll left = solve(l, i - 1, a, memo);
        ll right = solve(i + 1, r, a, memo);
        ll val = (ll)a[l - 1] * a[i] * a[r + 1];
        best = max(best, left + val + right);
    }
    memo[l][r] = best;
    return best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<int> nums(n + 2);
    for (int i = 1; i <= n; ++i) cin >> nums[i];
    nums[0] = 1;
    nums[n + 1] = 1;
    vector<vector<ll>> memo(n + 2, vector<ll>(n + 2, -1));
    cout << solve(1, n, nums, memo) << '\n';
}

// Memoization process started in solve where memo[l][r] caches best coins for interval [l,r].
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)
