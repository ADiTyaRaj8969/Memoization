# 12. Partition Equal Subset Sum
# Topic: Partition Equal Subset Sum
# Description: Determine if the array can be partitioned into two subsets with equal sum using memoized subset-sum.
# Input: n followed by n integers
# Output: 1 (true) or 0 (false)

import sys
from functools import lru_cache

if __name__ == '__main__':
    data = sys.stdin.read().strip().split()
    if not data:
        sys.exit(0)
    it = iter(data)
    n = int(next(it))
    arr = [int(next(it)) for _ in range(n)]
    total = sum(arr)
    if total % 2 != 0:
        print(0)
        sys.exit(0)
    target = total // 2
    arr = [abs(x) for x in arr]

    @lru_cache(maxsize=None)
    def can(i: int, rem: int) -> int:
        if rem == 0:
            return 1
        if i >= n or rem < 0:
            return 0
        return 1 if (can(i+1, rem - arr[i]) or can(i+1, rem)) else 0

    print(can(0, target))

# Memoization process started at can decorated with lru_cache.
# Time Complexity: O(n * target)
# Space Complexity: O(n * target)