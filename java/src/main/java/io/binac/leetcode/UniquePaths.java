package io.binac.leetcode;

import java.util.Arrays;

/**
 * <p>A robot is located at the top-left corner of a <code>m x n</code> grid (marked 'Start' in the diagram below).</p>
 *
 * <p>The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).</p>
 *
 * <p>How many possible unique paths are there?</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img src="https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png" style="width: 400px; height: 183px;">
 * <pre><strong>Input:</strong> m = 3, n = 7
 * <strong>Output:</strong> 28
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> m = 3, n = 2
 * <strong>Output:</strong> 3
 * <strong>Explanation:</strong>
 * From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 * 1. Right -&gt; Down -&gt; Down
 * 2. Down -&gt; Down -&gt; Right
 * 3. Down -&gt; Right -&gt; Down
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> m = 7, n = 3
 * <strong>Output:</strong> 28
 * </pre>
 *
 * <p><strong>Example 4:</strong></p>
 *
 * <pre><strong>Input:</strong> m = 3, n = 3
 * <strong>Output:</strong> 6
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= m, n &lt;= 100</code></li>
 * 	<li>It's guaranteed that the answer will be less than or equal to <code>2 * 10<sup>9</sup></code>.</li>
 * </ul>
 */
public class UniquePaths {
    public static class Solution1 {
        public int uniquePaths(int m, int n) {
            int[] dp = new int[n];
            Arrays.fill(dp, 1);
            for (int i = 1; i < m; ++i) {
                for (int j = 1; j < n; ++j)
                    dp[j] += dp[j - 1];
            }
            return dp[n - 1];
        }
    }

    public static class Solution2 {
        private long factorial(int n, int k) {
            long result = 1;
            for (; k <= n; ++k) result *= k;
            return result;
        }

        private long combination(int m, int n) {
            n = Math.min(n, m - n);
            return factorial(m, m - n + 1) / factorial(n, 1);
        }

        public int uniquePaths(int m, int n) {
            return (int) combination(m + n - 2, m - 1);
        }
    }
}
