package io.binac.leetcode;

/**
 * <p>Given a positive integer <code>n</code>, generate an <code>n x n</code> <code>matrix</code> filled with elements from <code>1</code> to <code>n<sup>2</sup></code> in spiral order.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg" style="width: 242px; height: 242px;">
 * <pre><strong>Input:</strong> n = 3
 * <strong>Output:</strong> [[1,2,3],[8,9,4],[7,6,5]]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 1
 * <strong>Output:</strong> [[1]]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= n &lt;= 20</code></li>
 * </ul>
 */
public class SpiralMatrixII {
    public static class Solution1 {
        public int[][] generateMatrix(int n) {
            int[][] result = new int[n][n];
            int value = 1;
            int left = 0, right = n - 1, top = 0, bottom = n - 1;
            int i, j;
            while (true) {
                for (j = left; j <= right; ++j)
                    result[top][j] = value++;
                ++top;
                if (top > bottom) break;
                for (i = top; i <= bottom; ++i)
                    result[i][right] = value++;
                --right;
                if (left > right) break;
                for (j = right; j >= left; --j)
                    result[bottom][j] = value++;
                --bottom;
                if (top > bottom) break;
                for (i = bottom; i >= top; --i)
                    result[i][left] = value++;
                ++left;
                if (left > right) break;
            }
            return result;
        }
    }
}
