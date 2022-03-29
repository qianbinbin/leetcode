package io.binac.leetcode;

/**
 * <p>Given an <code>m x n</code> 2D binary grid <code>grid</code> which represents a map of <code>'1'</code>s (land) and <code>'0'</code>s (water), return <em>the number of islands</em>.</p>
 *
 * <p>An <strong>island</strong> is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> grid = [
 *   ["1","1","1","1","0"],
 *   ["1","1","0","1","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","0","0","0"]
 * ]
 * <strong>Output:</strong> 1
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> grid = [
 *   ["1","1","0","0","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","1","0","0"],
 *   ["0","0","0","1","1"]
 * ]
 * <strong>Output:</strong> 3
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>m == grid.length</code></li>
 * 	<li><code>n == grid[i].length</code></li>
 * 	<li><code>1 &lt;= m, n &lt;= 300</code></li>
 * 	<li><code>grid[i][j]</code> is <code>'0'</code> or <code>'1'</code>.</li>
 * </ul>
 */
public class NumberOfIslands {
    public static class Solution1 {
        private void mark(char[][] grid, int i, int j, int m, int n) {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1')
                return;
            grid[i][j] = '2';
            mark(grid, i - 1, j, m, n);
            mark(grid, i + 1, j, m, n);
            mark(grid, i, j - 1, m, n);
            mark(grid, i, j + 1, m, n);
        }

        public int numIslands(char[][] grid) {
            final int m = grid.length, n = grid[0].length;
            int result = 0;
            for (int i = 0, j; i < m; ++i) {
                for (j = 0; j < n; ++j) {
                    if (grid[i][j] == '1') {
                        mark(grid, i, j, m, n);
                        ++result;
                    }
                }
            }
            return result;
        }
    }
}
