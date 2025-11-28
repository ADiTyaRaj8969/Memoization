# 11. Subset Sum Problem
# Topic: Subset Sum Problem
# Description: Given an array of non-negative integers and a target sum, determine whether
# there exists a subset of the array that sums to the target.
# Approach: Use recursion with memoization (cache on (idx, remaining_sum)).
# Input format (stdin):
#  n
#  a1 a2 ... an
#  target
# Output: 1 if a subset exists, otherwise 0

import sys
from functools import lru_cache

def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    n = int(next(it))
    arr = [int(next(it)) for _ in range(n)]
    target = int(next(it))
    # normalize to non-negative values (problem usually assumes non-negative)
    arr[:] = [abs(x) for x in arr]
    total = sum(arr)
    if target < 0 or target > total:
        print(0)
        return
    arr_tuple = tuple(arr)  # make immutable for closure usage

    # Memoization starts here: lru_cache on solve
    @lru_cache(maxsize=None)
    def solve(idx: int, rem: int) -> int:
        if rem == 0:
            return 1
        if idx >= n or rem < 0:
            return 0
        # take current
        if solve(idx+1, rem - arr_tuple[idx]):
            return 1
        # skip current
        if solve(idx+1, rem):
            return 1
        return 0

    print(solve(0, target))

if __name__ == '__main__':
    main()

# Memoization process started at solve decorated with lru_cache where (idx,rem) states are cached.
# Time Complexity: O(n * target)
# Space Complexity: O(n * target) (cache) + O(n) recursion stack