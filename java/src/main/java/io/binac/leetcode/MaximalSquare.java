package io.binac.leetcode;

/**
 * <p>Given an <code>m x n</code> binary <code>matrix</code> filled with <code>0</code>'s and <code>1</code>'s, <em>find the largest square containing only</em> <code>1</code>'s <em>and return its area</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/11/26/max1grid.jpg" style="width: 400px; height: 319px;">
 * <pre><strong>Input:</strong> matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * <strong>Output:</strong> 4
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/11/26/max2grid.jpg" style="width: 165px; height: 165px;">
 * <pre><strong>Input:</strong> matrix = [["0","1"],["1","0"]]
 * <strong>Output:</strong> 1
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> matrix = [["0"]]
 * <strong>Output:</strong> 0
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>m == matrix.length</code></li>
 * 	<li><code>n == matrix[i].length</code></li>
 * 	<li><code>1 &lt;= m, n &lt;= 300</code></li>
 * 	<li><code>matrix[i][j]</code> is <code>'0'</code> or <code>'1'</code>.</li>
 * </ul>
 */
public class MaximalSquare {
    public static class Solution1 {
        public int maximalSquare(char[][] matrix) {
            final int m = matrix.length, n = matrix[0].length;
            int[][] dp = new int[m + 1][n + 1];
            int maxLen = 0;
            for (int i = 1, j; i <= m; ++i) {
                for (j = 1; j <= n; ++j) {
                    if (matrix[i - 1][j - 1] != '1')
                        continue;
                    dp[i][j] = Math.min(Math.min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
                    maxLen = Math.max(maxLen, dp[i][j]);
                }
            }
            return maxLen * maxLen;
        }
    }
}
