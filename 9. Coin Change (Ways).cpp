// 9. Coin Change (Ways)
// Topic: Coin Change (Ways)
// Description: Given amount and list of coins, count ways to make amount (combinations), memoize by
// (idx, amount). Input: amount m, k (number of coins), then k coin values Output: number of ways

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Memoization starts here: vector<vector<ll>> memo
ll ways(int idx, int amount, const vector<int>& coins, vector<vector<ll>>& memo)
{
    if (amount == 0)
        return 1;
    if (amount < 0 || idx >= (int)coins.size())
        return 0;
    if (memo[idx][amount] != -1)
        return memo[idx][amount];
    ll take = ways(idx, amount - coins[idx], coins, memo);
    ll skip = ways(idx + 1, amount, coins, memo);
    memo[idx][amount] = take + skip;
    return memo[idx][amount];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int amount, k;
    if (!(cin >> amount >> k))
        return 0;
    vector<int> coins(k);
    for (int i = 0; i < k; ++i) cin >> coins[i];
    vector<vector<ll>> memo(k, vector<ll>(amount + 1, -1));
    cout << ways(0, amount, coins, memo) << '\n';
}

// Memoization process started in ways where memo table caches results for (idx,amount).
// Time Complexity: O(k*amount)
// Space Complexity: O(k*amount)
