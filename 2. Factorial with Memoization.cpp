// 2. Factorial with Memoization
// Topic: Factorial with Memoization
// Description: Compute factorial using recursion with memoization to cache intermediate results.
// Input: n (integer >= 0)
// Output: n! (as unsigned long long for moderate n)

#include <bits/stdc++.h>
using namespace std;

// Memoization starts here: using unordered_map<int, unsigned long long> memo
unsigned long long factorial(int n, unordered_map<int, unsigned long long>& memo)
{
    if (n <= 1)
        return 1ULL;
    auto it = memo.find(n);
    if (it != memo.end())
        return it->second;
    unsigned long long res = (unsigned long long)n * factorial(n - 1, memo);
    memo[n] = res;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    unordered_map<int, unsigned long long> memo;
    cout << factorial(n, memo) << '\n';
    return 0;
}

// Memoization process started in factorial function where memo map is checked and updated.
// Time Complexity: O(n)
// Space Complexity: O(n) (memoization map + recursion stack)
// Factorial with Memoization
// Topic: Factorial with Memoization
// Description: Compute factorial using recursion with memoization to cache intermediate results.
// Input: n (integer >= 0)
// Output: n! (as unsigned long long for moderate n)

#include <bits/stdc++.h>
using namespace std;

// Memoization starts here: using unordered_map<int, unsigned long long> memo
unsigned long long factorial(int n, unordered_map<int, unsigned long long>& memo)
{
    if (n <= 1)
        return 1ULL;
    auto it = memo.find(n);
    if (it != memo.end())
        return it->second;
    unsigned long long res = (unsigned long long)n * factorial(n - 1, memo);
    memo[n] = res;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    unordered_map<int, unsigned long long> memo;
    cout << factorial(n, memo) << '\n';
    return 0;
}

// Memoization process started in factorial function where memo map is checked and updated.
// Time Complexity: O(n)
// Space Complexity: O(n) (memoization map + recursion stack)