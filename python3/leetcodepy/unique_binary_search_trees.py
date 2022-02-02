"""
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.



Example 1:
https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg

Input: n = 3
Output: 5

Example 2:

Input: n = 1
Output: 1


Constraints:

1 <= n <= 19
"""
from math import factorial


class Solution1:
    def numTrees(self, n: int) -> int:
        dp = [0] * (n + 1)
        dp[0], dp[1] = 1, 1
        for i in range(2, n + 1):
            for j in range(n):
                dp[i] += dp[j] * dp[i - 1 - j]
        return dp[n]


class Solution2:
    def numTrees(self, n: int) -> int:
        return factorial(2 * n) // factorial(n) ** 2 // (n + 1)
