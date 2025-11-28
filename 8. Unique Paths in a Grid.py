# 8. Unique Paths in a Grid
# Topic: Unique Paths
# Description: Count unique paths from top-left to bottom-right in an m x n grid moving only right or down.
# Input: m n
# Output: number of unique paths

import sys
from functools import lru_cache

@lru_cache(maxsize=None)
def paths(r: int, c: int, m: int, n: int) -> int:
    if r == m-1 and c == n-1:
        return 1
    if r >= m or c >= n:
        return 0
    return paths(r+1, c, m, n) + paths(r, c+1, m, n)

if __name__ == '__main__':
    data = sys.stdin.read().strip().split()
    if not data:
        sys.exit(0)
    m, n = map(int, data[:2])
    print(paths(0,0,m,n))

# Memoization process started at paths decorated with lru_cache.
# Time Complexity: O(m*n)
# Space Complexity: O(m*n)