# 16. Matrix Chain Multiplication
# Topic: Matrix Chain Multiplication
# Description: Given dimensions array, compute minimal scalar multiplications using memoization.
# Input: n followed by n+1 integers (dimensions)
# Output: minimum cost

import sys
from functools import lru_cache

if __name__ == '__main__':
    data = sys.stdin.read().strip().split()
    if not data:
        sys.exit(0)
    it = iter(data)
    n = int(next(it))
    dims = [int(next(it)) for _ in range(n+1)]

    @lru_cache(maxsize=None)
    def mcm(i: int, j: int) -> int:
        if i == j:
            return 0
        best = 10**30
        for k in range(i, j):
            cost = mcm(i, k) + mcm(k+1, j) + dims[i-1]*dims[k]*dims[j]
            if cost < best:
                best = cost
        return best

    print(mcm(1, n))

# Memoization process started at mcm decorated with lru_cache.
# Time Complexity: O(n^3)
# Space Complexity: O(n^2)