// 10. Coin Change (Minimum Coins)
// Topic: Coin Change (Minimum Coins)
// Description: Given coins[] and amount, return minimum number of coins required using
// recursion+memo. Input: amount k, n (#coins), then coin values Output: minimum coins or -1 if not
// possible

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Memoization starts here: vector<int> memo for amounts
int minCoins(int amount, const vector<int>& coins, vector<int>& memo)
{
    if (amount == 0)
        return 0;
    if (amount < 0)
        return INT_MAX / 2;
    if (memo[amount] != -1)
        return memo[amount];
    int res = INT_MAX / 2;
    for (int c : coins)
    {
        int sub = minCoins(amount - c, coins, memo);
        if (sub + 1 < res)
            res = sub + 1;
    }
    memo[amount] = res;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int amount, n;
    if (!(cin >> amount >> n))
        return 0;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];
    vector<int> memo(amount + 1, -1);
    int ans = minCoins(amount, coins, memo);
    if (ans >= INT_MAX / 2)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}

// Memoization process started in minCoins where memo[amount] caches the minimum coins for that
// amount. Time Complexity: O(n * amount) where n is #coins Space Complexity: O(amount)
