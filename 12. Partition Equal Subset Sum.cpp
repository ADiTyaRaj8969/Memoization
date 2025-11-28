// 12. Partition Equal Subset Sum
// Topic: Partition Equal Subset Sum
// Description: Check if array can be partitioned into two subsets with equal sum using memoized
// subset sum. Input: n followed by n integers Output: 1 (true) or 0 (false)

#include <bits/stdc++.h>
using namespace std;

int canPartitionFrom(int idx, int sum, const vector<int>& arr, vector<vector<int>>& memo)
{
    if (sum == 0)
        return 1;
    if (idx >= (int)arr.size() || sum < 0)
        return 0;
    if (memo[idx][sum] != -1)
        return memo[idx][sum];
    int take = canPartitionFrom(idx + 1, sum - arr[idx], arr, memo);
    int skip = canPartitionFrom(idx + 1, sum, arr, memo);
    memo[idx][sum] = (take || skip);
    return memo[idx][sum];
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
        total += arr[i];
    }
    if (total % 2 == 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    int target = total / 2;
    vector<vector<int>> memo(n, vector<int>(target + 1, -1));
    cout << canPartitionFrom(0, target, arr, memo) << '\n';
}

// Memoization process started in canPartitionFrom where memo caches subproblem results.
// Time Complexity: O(n * target)
// Space Complexity: O(n * target)
