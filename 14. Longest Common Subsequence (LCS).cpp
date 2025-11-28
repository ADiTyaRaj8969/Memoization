// 14. Longest Common Subsequence (LCS)
// Topic: Longest Common Subsequence
// Description: Given strings a and b, find length of LCS using recursion + memo.
// Input: a b (two strings on separate lines or same line)
// Output: length of LCS

#include <bits/stdc++.h>
using namespace std;

int lcs(int i, int j, const string& a, const string& b, vector<vector<int>>& memo)
{
    if (i >= (int)a.size() || j >= (int)b.size())
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];
    if (a[i] == b[j])
        return memo[i][j] = 1 + lcs(i + 1, j + 1, a, b, memo);
    return memo[i][j] = max(lcs(i + 1, j, a, b, memo), lcs(i, j + 1, a, b, memo));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    if (!getline(cin, a))
        return 0;
    if (!getline(cin, b))
        return 0;
    vector<vector<int>> memo(a.size(), vector<int>(b.size(), -1));
    cout << lcs(0, 0, a, b, memo) << '\n';
}

// Memoization process started in lcs where memo[i][j] caches LCS length for suffixes starting at i
// and j. Time Complexity: O(|a| * |b|) Space Complexity: O(|a| * |b|)
