# 15. Edit Distance (Levenshtein Distance)
# Topic: Edit Distance
# Description: Compute minimum operations (insert/delete/replace) to convert string a into b using memoization.
# Input: two lines: string a and string b
# Output: minimum edit distance

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
    def edit(i: int, j: int) -> int:
        if i == n:
            return m - j
        if j == m:
            return n - i
        if a[i] == b[j]:
            return edit(i+1, j+1)
        return 1 + min(edit(i+1, j), edit(i, j+1), edit(i+1, j+1))

    print(edit(0,0))

# Memoization process started at edit decorated with lru_cache.
# Time Complexity: O(n * m)
# Space Complexity: O(n * m)