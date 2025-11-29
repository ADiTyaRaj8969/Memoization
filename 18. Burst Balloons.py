# 18. Burst Balloons
# Topic: Burst Balloons
# Description: Given array of balloon values, find max coins by bursting in optimal order using interval DP + memoization.
# Input: n followed by n integers
# Output: maximum coins

import sys
from functools import lru_cache

if __name__ == '__main__':
    data = sys.stdin.read().strip().split()
    if not data:
        sys.exit(0)
    it = iter(data)
    n = int(next(it))
    nums = [1] + [int(next(it)) for _ in range(n)] + [1]

    @lru_cache(maxsize=None)
    def solve(l: int, r: int) -> int:
        if l > r:
            return 0
        best = 0
        for i in range(l, r+1):
            val = nums[l-1] * nums[i] * nums[r+1]
            best = max(best, solve(l, i-1) + val + solve(i+1, r))
        return best

    print(solve(1, n))

# Memoization process started at solve decorated with lru_cache.
# Time Complexity: O(n^3)
# Space Complexity: O(n^2)