# 5. Sum of Digits using Recursion
# Topic: Sum of Digits using Recursion
# Description: Compute sum of digits for an integer; cache results for repeated numbers.
# Input: n (integer)
# Output: sum of digits

import sys
from functools import lru_cache

@lru_cache(maxsize=None)
def sum_digits(n: int) -> int:
    n = abs(n)
    if n < 10:
        return n
    return (n % 10) + sum_digits(n // 10)

if __name__ == '__main__':
    data = sys.stdin.read().strip().split()
    if not data:
        sys.exit(0)
    n = int(data[0])
    print(sum_digits(n))

# Memoization process started at sum_digits decorated with lru_cache.
# Time Complexity: O(d) where d is number of digits
# Space Complexity: O(k) where k is number of distinct cached inputs