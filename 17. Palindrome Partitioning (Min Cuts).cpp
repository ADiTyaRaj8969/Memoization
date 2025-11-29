// 17. Palindrome Partitioning (Min Cuts)
// Topic: Palindrome Partitioning
// Description: Given string s, compute minimum cuts to partition into palindromic substrings using
// memoization. Input: s (one line) Output: minimum cuts

#include <bits/stdc++.h>
using namespace std;

bool isPal(const string& s, int i, int j)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

int minCuts(const string& s, int i, vector<int>& memo)
{
    int n = s.size();
    if (i >= n)
        return 0;
    if (memo[i] != -1)
        return memo[i];
    int best = INT_MAX / 2;
    for (int j = i; j < n; ++j)
    {
        if (isPal(s, i, j))
        {
            int cost = 1 + minCuts(s, j + 1, memo);
            if (cost < best)
                best = cost;
        }
    }
    memo[i] = best;
    return memo[i];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if (!getline(cin, s))
        return 0;
    int n = s.size();
    vector<int> memo(n, -1);
    int ans = minCuts(s, 0, memo);
    if (ans == INT_MAX / 2)
        cout << 0 << '\n';
    else
        cout << max(0, ans - 1) << '\n';
}

// Memoization process started in minCuts where memo[i] caches minimal partitions from i; palindrome
// checks used to prune. Time Complexity: O(n^2) average with precomputation; current naive
// palindrome check gives O(n^3) worst-case Space Complexity: O(n)
