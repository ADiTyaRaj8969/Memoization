# 19. Interleaving Strings
# Topic: Interleaving Strings
# Description: Check if s3 is an interleaving of s1 and s2 using memoization on indices.
# Input: three lines: s1, s2, s3
# Output: 1 (true) or 0 (false)

import sys
from functools import lru_cache

if __name__ == '__main__':
    lines = sys.stdin.read().splitlines()
    if not lines:
        sys.exit(0)
    s1 = lines[0].rstrip('\n')
    s2 = lines[1].rstrip('\n') if len(lines) > 1 else ''
    s3 = lines[2].rstrip('\n') if len(lines) > 2 else ''
    if len(s1) + len(s2) != len(s3):
        print(0); sys.exit(0)

    @lru_cache(maxsize=None)
    def inter(i: int, j: int) -> int:
        k = i + j
        if i == len(s1) and j == len(s2):
            return 1
        ans = 0
        if i < len(s1) and s1[i] == s3[k]:
            ans = ans or inter(i+1, j)
        if not ans and j < len(s2) and s2[j] == s3[k]:
            ans = ans or inter(i, j+1)
        return 1 if ans else 0

    print(inter(0,0))

# Memoization process started at inter decorated with lru_cache.
# Time Complexity: O(|s1| * |s2|)
# Space Complexity: O(|s1| * |s2|)