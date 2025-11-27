# 3. Climbing Stairs
# Topic: Climbing Stairs
# Description: Count number of distinct ways to reach step n using recursion + memoization.
# Input: n (integer >= 0)
# Output: number of ways

import sys
from functools import lru_cache

@lru_cache(maxsize=None)
def ways(n: int) -> int:
    if n == 0:
        return 1
    if n < 0:
        return 0
    return ways(n-1) + ways(n-2)

if __name__ == '__main__':
    data = sys.stdin.read().strip().split()
    if not data:
        sys.exit(0)
    n = int(data[0])
    print(ways(n))

# Memoization process started at ways decorated with lru_cache.
# Time Complexity: O(n)
# Space Complexity: O(n)