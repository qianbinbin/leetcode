"""
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
"""
from typing import List


class Solution1:
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if not triangle:
            raise ValueError
        n = len(triangle)
        dp, tmp = [0] * n, [0] * n
        dp[0] = triangle[0][0]
        for i in range(1, n):
            tmp[0] = dp[0] + triangle[i][0]
            for j in range(1, i):
                tmp[j] = min(dp[j - 1], dp[j]) + triangle[i][j]
            tmp[i] = dp[i - 1] + triangle[i][i]
            tmp, dp = dp, tmp
        return min(dp)
