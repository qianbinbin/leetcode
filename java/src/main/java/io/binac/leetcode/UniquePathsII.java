package io.binac.leetcode;

/**
 * <p>A robot is located at the top-left corner of a <code>m x n</code> grid (marked 'Start' in the diagram below).</p>
 *
 * <p>The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).</p>
 *
 * <p>Now consider if some obstacles are added to the grids. How many unique paths would there be?</p>
 *
 * <p>An obstacle and space is marked as <code>1</code> and <code>0</code> respectively in the grid.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg" style="width: 242px; height: 242px;">
 * <pre><strong>Input:</strong> obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * <strong>Output:</strong> 2
 * <strong>Explanation:</strong> There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -&gt; Right -&gt; Down -&gt; Down
 * 2. Down -&gt; Down -&gt; Right -&gt; Right
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg" style="width: 162px; height: 162px;">
 * <pre><strong>Input:</strong> obstacleGrid = [[0,1],[0,0]]
 * <strong>Output:</strong> 1
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>m ==&nbsp;obstacleGrid.length</code></li>
 * 	<li><code>n ==&nbsp;obstacleGrid[i].length</code></li>
 * 	<li><code>1 &lt;= m, n &lt;= 100</code></li>
 * 	<li><code>obstacleGrid[i][j]</code> is <code>0</code> or <code>1</code>.</li>
 * </ul>
 */
public class UniquePathsII {
    public static class Solution1 {
        public int uniquePathsWithObstacles(int[][] obstacleGrid) {
            final int m = obstacleGrid.length, n = obstacleGrid[0].length;
            int[] dp = new int[n];
            for (int j = 0; j < n && obstacleGrid[0][j] == 0; ++j)
                dp[j] = 1;
            for (int i = 1; i < m; ++i) {
                if (dp[0] == 1 && obstacleGrid[i][0] == 1)
                    dp[0] = 0;
                for (int j = 1; j < n; ++j) {
                    if (obstacleGrid[i][j] == 0)
                        dp[j] += dp[j - 1];
                    else
                        dp[j] = 0;
                }
            }
            return dp[n - 1];
        }
    }
}
