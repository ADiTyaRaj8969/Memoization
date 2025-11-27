# 7. House Robber
# Topic: House Robber
# Description: Maximize sum of non-adjacent houses using recursion + memoization.
# Input: n followed by n integers (house values)
# Output: maximum sum

import sys
from functools import lru_cache

if __name__ == '__main__':
    data = sys.stdin.read().strip().split()
    if not data:
        sys.exit(0)
    it = iter(data)
    n = int(next(it))
    nums = [int(next(it)) for _ in range(n)]

    @lru_cache(maxsize=None)
    def rob(i: int) -> int:
        if i >= n:
            return 0
        return max(nums[i] + rob(i+2), rob(i+1))

    print(rob(0))

# Memoization starts at rob decorated with lru_cache.
# Time Complexity: O(n)
# Space Complexity: O(n)