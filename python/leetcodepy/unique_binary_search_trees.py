"""
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
"""


class Solution1:
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 0:
            raise ValueError
        if n < 2:
            return 1
        dp = [0] * (n + 1)
        dp[0], dp[1] = 1, 1
        for i in range(2, n + 1):
            for j in range(n):
                dp[i] += dp[j] * dp[i - 1 - j]
        return dp[n]
