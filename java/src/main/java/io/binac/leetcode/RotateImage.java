package io.binac.leetcode;

/**
 * <p>You are given an <em>n</em> x <em>n</em> 2D <code>matrix</code> representing an image, rotate the image by 90 degrees (clockwise).</p>
 *
 * <p>You have to rotate the image <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank"><strong>in-place</strong></a>, which means you have to modify the input 2D matrix directly. <strong>DO NOT</strong> allocate another 2D matrix and do the rotation.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg" style="width: 642px; height: 242px;">
 * <pre><strong>Input:</strong> matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * <strong>Output:</strong> [[7,4,1],[8,5,2],[9,6,3]]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/mat2.jpg" style="width: 800px; height: 321px;">
 * <pre><strong>Input:</strong> matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * <strong>Output:</strong> [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> matrix = [[1]]
 * <strong>Output:</strong> [[1]]
 * </pre>
 *
 * <p><strong>Example 4:</strong></p>
 *
 * <pre><strong>Input:</strong> matrix = [[1,2],[3,4]]
 * <strong>Output:</strong> [[3,1],[4,2]]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>matrix.length == n</code></li>
 * 	<li><code>matrix[i].length == n</code></li>
 * 	<li><code>1 &lt;= n &lt;= 20</code></li>
 * 	<li><code>-1000 &lt;= matrix[i][j] &lt;= 1000</code></li>
 * </ul>
 */
public class RotateImage {
    public static class Solution1 {
        public void rotate(int[][] matrix) {
            final int n = matrix.length;
            for (int i = 0, j, tmp; i < n; ++i) {
                for (j = i + 1; j < n; ++j) {
                    tmp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = tmp;
                }
            }
            for (int i = 0, j, h = n / 2, tmp; i < n; ++i) {
                for (j = 0; j < h; ++j) {
                    tmp = matrix[i][j];
                    matrix[i][j] = matrix[i][n - j - 1];
                    matrix[i][n - j - 1] = tmp;
                }
            }
        }
    }
}
