# 13. 0/1 Knapsack Problem
# Topic: 0/1 Knapsack
# Description: Given weights and values, pick items to maximize value without exceeding capacity using recursion + memoization.
# Input: n W followed by n pairs (weight value)
# Output: maximum achievable value

import sys
from functools import lru_cache

if __name__ == '__main__':
    data = sys.stdin.read().strip().split()
    if not data:
        sys.exit(0)
    it = iter(data)
    n = int(next(it))
    W = int(next(it))
    wt = [0]*n
    val = [0]*n
    for i in range(n):
        wt[i] = int(next(it)); val[i] = int(next(it))

    @lru_cache(maxsize=None)
    def knap(i: int, remW: int) -> int:
        if i >= n or remW <= 0:
            return 0
        res = knap(i+1, remW)
        if wt[i] <= remW:
            res = max(res, val[i] + knap(i+1, remW - wt[i]))
        return res

    print(knap(0, W))

# Memoization process started at knap decorated with lru_cache.
# Time Complexity: O(n * W)
# Space Complexity: O(n * W)