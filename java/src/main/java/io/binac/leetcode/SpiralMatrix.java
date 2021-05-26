package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * <p>Given an <code>m x n</code> <code>matrix</code>, return <em>all elements of the</em> <code>matrix</code> <em>in spiral order</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg" style="width: 242px; height: 242px;">
 * <pre><strong>Input:</strong> matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * <strong>Output:</strong> [1,2,3,6,9,8,7,4,5]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg" style="width: 322px; height: 242px;">
 * <pre><strong>Input:</strong> matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * <strong>Output:</strong> [1,2,3,4,8,12,11,10,9,5,6,7]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>m == matrix.length</code></li>
 * 	<li><code>n == matrix[i].length</code></li>
 * 	<li><code>1 &lt;= m, n &lt;= 10</code></li>
 * 	<li><code>-100 &lt;= matrix[i][j] &lt;= 100</code></li>
 * </ul>
 */
public class SpiralMatrix {
    public static class Solution1 {
        public List<Integer> spiralOrder(int[][] matrix) {
            final int m = matrix.length, n = matrix[0].length;
            List<Integer> result = new ArrayList<>(m * n);
            int left = 0, right = n - 1, top = 0, bottom = m - 1, i, j;
            while (true) {
                for (j = left; j <= right; ++j)
                    result.add(matrix[top][j]);
                if (++top > bottom) break;
                for (i = top; i <= bottom; ++i)
                    result.add(matrix[i][right]);
                if (left > --right) break;
                for (j = right; j >= left; --j)
                    result.add(matrix[bottom][j]);
                if (top > --bottom) break;
                for (i = bottom; i >= top; --i)
                    result.add(matrix[i][left]);
                if (++left > right) break;
            }
            return result;
        }
    }
}
