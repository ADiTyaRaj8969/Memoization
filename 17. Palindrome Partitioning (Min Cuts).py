# 17. Palindrome Partitioning (Min Cuts)
# Topic: Palindrome Partitioning
# Description: Minimize cuts needed to partition a string into palindromic substrings using memoization.
# Input: single line string s
# Output: minimum cuts

import sys
from functools import lru_cache

def is_pal(s: str, i: int, j: int) -> bool:
    while i < j:
        if s[i] != s[j]:
            return False
        i += 1; j -= 1
    return True

if __name__ == '__main__':
    line = sys.stdin.read().splitlines()
    if not line:
        sys.exit(0)
    s = line[0].rstrip('\n')
    n = len(s)

    @lru_cache(maxsize=None)
    def min_parts(i: int) -> int:
        if i >= n:
            return 0
        best = 10**9
        for j in range(i, n):
            if is_pal(s, i, j):
                best = min(best, 1 + min_parts(j+1))
        return best

    parts = min_parts(0)
    # number of cuts = partitions - 1
    print(max(0, parts - 1))

# Memoization process started at min_parts decorated with lru_cache.
# Time Complexity: O(n^2) with palindrome precomputation; current naive check O(n^3)
# Space Complexity: O(n)