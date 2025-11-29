// 20. Travelling Salesman Problem (TSP)
// Topic: TSP (bitmask DP)
// Description: Given n and distance matrix dist, compute minimal Hamiltonian cycle cost starting at
// 0. Input: n followed by n x n matrix Output: minimal tour cost

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL << 60);

ll tsp(int pos, int mask, const vector<vector<ll>>& dist, vector<vector<ll>>& memo)
{
    int n = dist.size();
    if (mask == (1 << n) - 1)
        return dist[pos][0] ? dist[pos][0] : INF;  // return to start
    if (memo[pos][mask] != -1)
        return memo[pos][mask];
    ll best = INF;
    for (int nxt = 0; nxt < n; ++nxt)
    {
        if (mask & (1 << nxt))
            continue;
        if (dist[pos][nxt] == 0)
            continue;  // assume 0 means no edge
        best = min(best, dist[pos][nxt] + tsp(nxt, mask | (1 << nxt), dist, memo));
    }
    memo[pos][mask] = best;
    return best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<vector<ll>> dist(n, vector<ll>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> dist[i][j];
    vector<vector<ll>> memo(n, vector<ll>(1 << n, -1));
    ll ans = tsp(0, 1 << 0, dist, memo);
    if (ans >= INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}

// Memoization process started in tsp where memo[pos][mask] caches best cost from state (pos,mask).
// Time Complexity: O(n^2 * 2^n)
// Space Complexity: O(n * 2^n)
