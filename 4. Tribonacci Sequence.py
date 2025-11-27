# 4. Tribonacci Sequence
# Topic: Tribonacci Sequence
# Description: Each term is the sum of the previous 3 terms; compute the nth Tribonacci number using recursion + memoization.
# Input: n (integer >= 0)
# Output: nth Tribonacci number

import sys
from functools import lru_cache

@lru_cache(maxsize=None)
def trib(n: int) -> int:
    if n == 0:
        return 0
    if n == 1 or n == 2:
        return 1
    return trib(n-1) + trib(n-2) + trib(n-3)

if __name__ == '__main__':
    data = sys.stdin.read().strip().split()
    if not data:
        sys.exit(0)
    n = int(data[0])
    print(trib(n))

# Memoization process started at trib decorated with lru_cache.
# Time Complexity: O(n)
# Space Complexity: O(n)