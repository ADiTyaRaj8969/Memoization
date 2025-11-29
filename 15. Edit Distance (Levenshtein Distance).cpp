// 15. Edit Distance (Levenshtein Distance)
// Topic: Edit Distance
// Description: Compute minimal insert/delete/replace operations using recursion + memoization.
// Input: two strings a and b (each on separate lines)
// Output: minimum edit distance

#include <bits/stdc++.h>
using namespace std;

int editDist(int i, int j, const string& a, const string& b, vector<vector<int>>& memo)
{
    if (i == (int)a.size())
        return (int)b.size() - j;
    if (j == (int)b.size())
        return (int)a.size() - i;
    if (memo[i][j] != -1)
        return memo[i][j];
    if (a[i] == b[j])
        return memo[i][j] = editDist(i + 1, j + 1, a, b, memo);
    int insertOp = 1 + editDist(i, j + 1, a, b, memo);
    int deleteOp = 1 + editDist(i + 1, j, a, b, memo);
    int replaceOp = 1 + editDist(i + 1, j + 1, a, b, memo);
    return memo[i][j] = min({insertOp, deleteOp, replaceOp});
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
    cout << editDist(0, 0, a, b, memo) << '\n';
}

// Memoization process started in editDist where memo[i][j] stores minimal operations for suffixes.
// Time Complexity: O(|a| * |b|)
// Space Complexity: O(|a| * |b|)
