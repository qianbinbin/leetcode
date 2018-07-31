package io.binac.leetcode;

/**
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 * <p>
 * <p>Note: You can only move either down or right at any point in time.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input:
 *     [
 *       [1,3,1],
 *       [1,5,1],
 *       [4,2,1]
 *     ]
 *     Output: 7
 *     Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * </blockquote></pre>
 */
public class MinimumPathSum {
    public static class Solution1 {
        public int minPathSum(int[][] grid) {
            final int row = grid.length, col = grid[0].length;
            if (col == 0)
                throw new IllegalArgumentException();
            int dp[] = new int[col];
            dp[0] = grid[0][0];
            for (int j = 1; j < col; ++j) dp[j] = dp[j - 1] + grid[0][j];
            for (int i = 1; i < row; ++i) {
                dp[0] += grid[i][0];
                for (int j = 1; j < col; ++j)
                    dp[j] = Math.min(dp[j - 1], dp[j]) + grid[i][j];
            }
            return dp[col - 1];
        }
    }
}
