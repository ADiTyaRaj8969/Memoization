// 19. Interleaving Strings
// Topic: Interleaving Strings
// Description: Given s1, s2, s3 check if s3 is interleaving of s1 and s2 using memoization on
// indices. Input: three strings each on separate lines Output: 1 (true) or 0 (false)

#include <bits/stdc++.h>
using namespace std;

int isInter(int i, int j, const string& s1, const string& s2, const string& s3,
            vector<vector<int>>& memo)
{
    if (i == (int)s1.size() && j == (int)s2.size())
        return 1;
    if (memo[i][j] != -1)
        return memo[i][j];
    int k = i + j;
    int ok = 0;
    if (i < (int)s1.size() && s1[i] == s3[k])
        ok = ok || isInter(i + 1, j, s1, s2, s3, memo);
    if (!ok && j < (int)s2.size() && s2[j] == s3[k])
        ok = ok || isInter(i, j + 1, s1, s2, s3, memo);
    memo[i][j] = ok;
    return ok;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2, s3;
    if (!getline(cin, s1))
        return 0;
    if (!getline(cin, s2))
        return 0;
    if (!getline(cin, s3))
        return 0;
    if (s1.size() + s2.size() != s3.size())
    {
        cout << 0 << '\n';
        return 0;
    }
    vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    cout << isInter(0, 0, s1, s2, s3, memo) << '\n';
}

// Memoization process started in isInter where memo[i][j] caches boolean result for indices (i,j).
// Time Complexity: O(|s1| * |s2|)
// Space Complexity: O(|s1| * |s2|)
