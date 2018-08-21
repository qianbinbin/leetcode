package io.binac.leetcode;

/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * <p>
 * <p>The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * <p>
 * <p>Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * <p>
 * <p>https://leetcode.com/static/images/problemset/robot_maze.png
 * <p>
 * <p>An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * <p>
 * <p>Note: m and n will be at most 100.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input:
 *     [
 *       [0,0,0],
 *       [0,1,0],
 *       [0,0,0]
 *     ]
 *     Output: 2
 *     Explanation:
 *     There is one obstacle in the middle of the 3x3 grid above.
 *     There are two ways to reach the bottom-right corner:
 *     1. Right -> Right -> Down -> Down
 *     2. Down -> Down -> Right -> Right
 * </blockquote></pre>
 */
public class UniquePathsII {
    public static class Solution1 {
        public int uniquePathsWithObstacles(int[][] obstacleGrid) {
            final int row = obstacleGrid.length, col = obstacleGrid[0].length;
            if (col == 0)
                throw new IllegalArgumentException();
            int dp[] = new int[col];
            for (int j = 0; j < col && obstacleGrid[0][j] == 0; ++j)
                dp[j] = 1;
            for (int i = 1; i < row; ++i) {
                if (dp[0] == 1 && obstacleGrid[i][0] == 1)
                    dp[0] = 0;
                for (int j = 1; j < col; ++j) {
                    if (obstacleGrid[i][j] == 0)
                        dp[j] += dp[j - 1];
                    else
                        dp[j] = 0;
                }
            }
            return dp[col - 1];
        }
    }
}
