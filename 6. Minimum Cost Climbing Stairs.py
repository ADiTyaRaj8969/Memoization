# 6. Minimum Cost Climbing Stairs
# Topic: Minimum Cost Climbing Stairs
# Description: Given a list of costs for stairs, find the minimal cost to reach the top using recursion + memoization.
# Input: n followed by n costs
# Output: minimum total cost

import sys
from functools import lru_cache

if __name__ == '__main__':
    data = sys.stdin.read().strip().split()
    if not data:
        sys.exit(0)
    it = iter(data)
    n = int(next(it))
    cost = [int(next(it)) for _ in range(n)]

    @lru_cache(maxsize=None)
    def min_cost(i: int) -> int:
        if i >= n:
            return 0
        return cost[i] + min(min_cost(i+1), min_cost(i+2))

    print(min(min_cost(0), min_cost(1)))

# Memoization starts at min_cost decorated with lru_cache.
# Time Complexity: O(n)
# Space Complexity: O(n)