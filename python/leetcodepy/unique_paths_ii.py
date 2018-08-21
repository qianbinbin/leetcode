"""
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

https://leetcode.com/static/images/problemset/robot_maze.png

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
"""
from typing import List


class Solution1:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        if not obstacleGrid:
            raise ValueError
        n, m = len(obstacleGrid), len(obstacleGrid[0])
        if m == 0:
            raise ValueError
        dp = [0] * m
        for j in range(m):
            if obstacleGrid[0][j] == 0:
                dp[j] = 1
            else:
                break
        for i in range(1, n):
            if dp[0] == 1 and obstacleGrid[i][0] == 1:
                dp[0] = 0
            for j in range(1, m):
                if obstacleGrid[i][j] == 0:
                    dp[j] += dp[j - 1]
                else:
                    dp[j] = 0
        return dp[m - 1]
