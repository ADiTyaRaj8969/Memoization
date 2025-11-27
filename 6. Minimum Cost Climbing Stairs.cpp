// 6. Minimum Cost Climbing Stairs
// Topic: Minimum Cost Climbing Stairs
// Description: Given cost[] array, can start at step 0 or 1; find min cost to reach beyond last
// step using memoization. Input: n (number of steps) followed by n costs Output: minimum cost

#include <bits/stdc++.h>
using namespace std;

// Memoization starts here: vector<int> memo
int minCost(int i, const vector<int>& cost, vector<int>& memo)
{
    int n = cost.size();
    if (i >= n)
        return 0;
    if (memo[i] != INT_MAX)
        return memo[i];
    int take1 = cost[i] + minCost(i + 1, cost, memo);
    int take2 = cost[i] + minCost(i + 2, cost, memo);
    memo[i] = min(take1, take2);
    return memo[i];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<int> cost(n);
    for (int i = 0; i < n; ++i) cin >> cost[i];
    vector<int> memo(n, INT_MAX);
    int res = min(minCost(0, cost, memo), minCost(1, cost, memo));
    cout << res << '\n';
}

// Memoization process started in minCost where memo vector is used to cache results.
// Time Complexity: O(n)
// Space Complexity: O(n)
