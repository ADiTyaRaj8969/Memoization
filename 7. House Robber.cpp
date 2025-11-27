// 7. House Robber
// Topic: House Robber
// Description: Max sum of non-adjacent elements using recursion + memoization.
// Input: n followed by n integers
// Output: maximum sum

#include <bits/stdc++.h>
using namespace std;

// Memoization starts here: vector<long long> memo
long long robFrom(int i, const vector<long long>& nums, vector<long long>& memo)
{
    int n = nums.size();
    if (i >= n)
        return 0;
    if (memo[i] != LLONG_MIN)
        return memo[i];
    long long take = nums[i] + robFrom(i + 2, nums, memo);
    long long skip = robFrom(i + 1, nums, memo);
    memo[i] = max(take, skip);
    return memo[i];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<long long> memo(n, LLONG_MIN);
    cout << robFrom(0, nums, memo) << '\n';
}

// Memoization process started in robFrom where memo vector caches computed values.
// Time Complexity: O(n)
// Space Complexity: O(n)
