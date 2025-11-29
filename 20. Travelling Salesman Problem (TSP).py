# 20. Travelling Salesman Problem (TSP)
# Topic: TSP (bitmask DP)
# Description: Use bitmasking + memoization to compute the shortest Hamiltonian cycle starting at node 0.
# Input: n followed by n x n distance matrix
# Output: minimal tour cost or -1 if not possible

import sys
from functools import lru_cache

INF = 10**18

if __name__ == '__main__':
    data = sys.stdin.read().strip().split()
    if not data:
        sys.exit(0)
    it = iter(data)
    n = int(next(it))
    dist = [[int(next(it)) for _ in range(n)] for _ in range(n)]

    @lru_cache(maxsize=None)
    def tsp(pos: int, mask: int) -> int:
        if mask == (1 << n) - 1:
            return dist[pos][0] if dist[pos][0] != 0 else INF
        best = INF
        for nxt in range(n):
            if mask & (1 << nxt):
                continue
            if dist[pos][nxt] == 0:
                continue
            best = min(best, dist[pos][nxt] + tsp(nxt, mask | (1 << nxt)))
        return best

    ans = tsp(0, 1)
    print(-1 if ans >= INF else ans)

# Memoization process started at tsp decorated with lru_cache.
# Time Complexity: O(n^2 * 2^n)
# Space Complexity: O(n * 2^n)