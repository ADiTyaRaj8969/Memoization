# 14. Longest Common Subsequence (LCS)
# Topic: Longest Common Subsequence
# Description: Given strings a and b, find length of LCS using recursion + memoization.
# Input: two lines: string a and string b
# Output: length of LCS

import sys
from functools import lru_cache

if __name__ == '__main__':
    lines = sys.stdin.read().splitlines()
    if not lines:
        sys.exit(0)
    a = lines[0].rstrip('\n')
    b = lines[1].rstrip('\n') if len(lines) > 1 else ''
    n, m = len(a), len(b)

    @lru_cache(maxsize=None)
    def lcs(i: int, j: int) -> int:
        if i == n or j == m:
            return 0
        if a[i] == b[j]:
            return 1 + lcs(i+1, j+1)
        return max(lcs(i+1, j), lcs(i, j+1))

    print(lcs(0,0))

# Memoization process started at lcs decorated with lru_cache.
# Time Complexity: O(n * m)
# Space Complexity: O(n * m)