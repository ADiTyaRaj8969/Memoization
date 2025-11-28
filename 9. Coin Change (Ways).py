# 9. Coin Change (Ways)
# Topic: Coin Change (Ways)
# Description: Count number of ways to make amount using coins (combinations), recursion + memoization.
# Input: amount k, n (#coins), then n coin values
# Output: number of ways

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
    def ways(idx: int, rem: int) -> int:
        if rem == 0:
            return 1
        if rem < 0 or idx >= n:
            return 0
        return ways(idx, rem - coins[idx]) + ways(idx+1, rem)

    print(ways(0, amount))

# Memoization process started at ways decorated with lru_cache.
# Time Complexity: O(n * amount)
# Space Complexity: O(n * amount)