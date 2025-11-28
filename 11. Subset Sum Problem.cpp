// 11. Subset Sum Problem
// Topic: Subset Sum Problem
// Description: Given an array of non-negative integers and a target sum, determine whether
// there exists a subset of the array that sums to the target.
// Approach: Use recursion with memoization (DP over index and remaining sum). The memo table
// stores -1 for unknown, 0 for false, and 1 for true for state (idx, sum).
// Input format (stdin):
//  n
//  a1 a2 ... an
//  target
// Output: 1 if a subset exists, otherwise 0

#include <bits/stdc++.h>
using namespace std;

// Memoization starts here: memo[idx][sum] caches boolean result for whether a subset from idx can
// make 'sum'
int solve(int idx, int sum, const vector<int>& arr, vector<vector<int>>& memo)
{
    if (sum == 0)
        return 1;
    if (idx >= (int)arr.size() || sum < 0)
        return 0;
    int& res = memo[idx][sum];
    if (res != -1)
        return res;
    // Try taking current element
    if (solve(idx + 1, sum - arr[idx], arr, memo))
        return res = 1;
    // Try skipping current element
    if (solve(idx + 1, sum, arr, memo))
        return res = 1;
    return res = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    vector<int> arr(n);
    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        if (arr[i] < 0)
            arr[i] = abs(arr[i]);  // ensure non-negative for this implementation
        total += arr[i];
    }
    int target;
    cin >> target;
    if (target < 0 || target > total)
    {
        cout << 0 << '\n';
        return 0;
    }

    vector<vector<int>> memo(n, vector<int>(target + 1, -1));
    cout << solve(0, target, arr, memo) << '\n';
    return 0;
}

// Memoization process started at the beginning of function `solve` where `memo[idx][sum]` is
// checked and set. Time Complexity: O(n * target) — each (idx, sum) state computed once Space
// Complexity: O(n * target) for memo table plus O(n) recursion stack
