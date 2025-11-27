# Factorial with Memoization
# Topic: Factorial with Memoization
# Description: Compute factorial using recursion with memoization to cache intermediate results.
# Input: n (integer >= 0)
# Output: n! (as int)

import sys
from functools import lru_cache

# Memoization starts here: lru_cache
@lru_cache(maxsize=None)
def factorial(n: int) -> int:
    if n <= 1:
        return 1
    return n * factorial(n-1)

if __name__ == '__main__':
    data = sys.stdin.read().strip().split()
    if not data:
        sys.exit(0)
    n = int(data[0])
    print(factorial(n))

# Memoization process started at factorial decorated with lru_cache.
# Time Complexity: O(n)
# Space Complexity: O(n)