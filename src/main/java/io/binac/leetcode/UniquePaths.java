package io.binac.leetcode;

/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * <p>
 * <p>The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * <p>
 * <p>How many possible unique paths are there?
 * <p>
 * <p>https://leetcode.com/static/images/problemset/robot_maze.png
 * <p>Above is a 7 x 3 grid. How many possible unique paths are there?
 * <p>
 * <p>Note: m and n will be at most 100.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: m = 3, n = 2
 *     Output: 3
 *     Explanation:
 *     From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 *     1. Right -> Right -> Down
 *     2. Right -> Down -> Right
 *     3. Down -> Right -> Right
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: m = 7, n = 3
 *     Output: 28
 * </blockquote></pre>
 */
public class UniquePaths {
    public static class Solution1 {
        public int uniquePaths(int m, int n) {
            if (m < 1)
                throw new IllegalArgumentException("m must be positive");
            if (n < 1)
                throw new IllegalArgumentException("n must be positive");
            int dp[] = new int[m];
            for (int i = 0; i < m; ++i) dp[i] = 1;
            for (int i = 1; i < n; ++i) {
                for (int j = 1; j < m; ++j)
                    dp[j] += dp[j - 1];
            }
            return dp[m - 1];
        }
    }
}
