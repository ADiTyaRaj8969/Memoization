// 8. Unique Paths in a Grid
// Topic: Unique Paths
// Description: Given m x n grid, count unique paths from (0,0) to (m-1,n-1) moving only right or
// down. Input: m n Output: number of unique paths

#include <bits/stdc++.h>
using namespace std;

// Memoization starts here: vector<vector<long long>> memo
long long paths(int r, int c, vector<vector<long long>>& memo)
{
    int m = memo.size();
    int n = memo[0].size();
    if (r == m - 1 && c == n - 1)
        return 1;
    if (r >= m || c >= n)
        return 0;
    if (memo[r][c] != -1)
        return memo[r][c];
    memo[r][c] = paths(r + 1, c, memo) + paths(r, c + 1, memo);
    return memo[r][c];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    if (!(cin >> m >> n))
        return 0;
    vector<vector<long long>> memo(m, vector<long long>(n, -1));
    cout << paths(0, 0, memo) << '\n';
}

// Memoization process started in paths function where memo 2D array is used.
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
