// 16. Matrix Chain Multiplication
// Topic: Matrix Chain Multiplication
// Description: Given dimensions array, compute minimal scalar multiplications using memoization.
// Input: n (number of matrices), followed by n+1 dimensions
// Output: minimum cost

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mcm(int i, int j, const vector<int>& dims, vector<vector<ll>>& memo)
{
    if (i == j)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];
    ll best = LLONG_MAX;
    for (int k = i; k < j; ++k)
    {
        ll left = mcm(i, k, dims, memo);
        ll right = mcm(k + 1, j, dims, memo);
        ll cost = left + right + (ll)dims[i - 1] * dims[k] * dims[j];
        best = min(best, cost);
    }
    memo[i][j] = best;
    return best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<int> dims(n + 1);
    for (int i = 0; i <= n; ++i) cin >> dims[i];
    vector<vector<ll>> memo(n + 1, vector<ll>(n + 1, -1));
    cout << mcm(1, n, dims, memo) << '\n';
}

// Memoization process started in mcm where memo[i][j] caches minimal cost for multiplying Ai..Aj.
// Time Complexity: O(n^3) due to k loop and O(n^2) states
// Space Complexity: O(n^2)
