# 10. Coin Change (Minimum Coins)
# Topic: Coin Change (Minimum Coins)
# Description: Find the minimum number of coins required to make given amount using recursion + memoization.
# Input: amount k, n (#coins), then n coin values
# Output: minimum coins or -1 if not possible

import sys
from functools import lru_cache

if __name__ == '__main__':
    data = sys.stdin.read().strip().split()
    if not data:
        sys.exit(0)
    it = iter(data)
    amount = int(next(it))
    n = int(next(it))
    coins = [int(next(it)) for _ in range(n)]

    @lru_cache(maxsize=None)
    def min_coins(rem: int) -> int:
        if rem == 0:
            return 0
        if rem < 0:
            return 10**9
        best = 10**9
        for c in coins:
            best = min(best, 1 + min_coins(rem - c))
        return best

    ans = min_coins(amount)
    print(-1 if ans >= 10**9 else ans)

# Memoization process started at min_coins decorated with lru_cache.
# Time Complexity: O(n * amount)
# Space Complexity: O(amount)