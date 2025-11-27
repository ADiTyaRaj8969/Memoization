# 1. Fibonacci Numbers
# Topic: Fibonacci Numbers
# Description: Compute the nth Fibonacci number using recursion with memoization to avoid exponential recomputation.
# Input: n (integer >= 0)
# Output: nth Fibonacci number

import sys
from functools import lru_cache

# Memoization starts here: lru_cache on fib
@lru_cache(maxsize=None)
def fib(n: int) -> int:
    if n <= 1:
        return n
    return fib(n-1) + fib(n-2)

if __name__ == '__main__':
    data = sys.stdin.read().strip().split()
    if not data:
        sys.exit(0)
    n = int(data[0])
    print(fib(n))

# Memoization process started at fib decorated with lru_cache.
# Time Complexity: O(n)
# Space Complexity: O(n) (cache + recursion stack)
