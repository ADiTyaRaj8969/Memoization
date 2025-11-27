// 5. Sum of Digits using Recursion
// Topic: Sum of Digits with Memoization
// Description: For repeated numbers, cache the digit-sum result to avoid recomputing.
// Input: n (non-negative integer)
// Output: sum of digits of n

#include <bits/stdc++.h>
using namespace std;

// Memoization starts here: unordered_map<long long,int> memo
int sumDigits(long long n, unordered_map<long long, int>& memo)
{
    if (n < 10)
        return (int)n;
    auto it = memo.find(n);
    if (it != memo.end())
        return it->second;
    int res = (int)(n % 10) + sumDigits(n / 10, memo);
    memo[n] = res;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    if (!(cin >> n))
        return 0;
    unordered_map<long long, int> memo;
    cout << sumDigits(n, memo) << '\n';
}

// Memoization process started in sumDigits where memo map is checked and updated.
// Time Complexity: O(d) where d is number of digits (with memo it's O(1) amortized per repeated
// number) Space Complexity: O(k) where k is distinct numbers cached
