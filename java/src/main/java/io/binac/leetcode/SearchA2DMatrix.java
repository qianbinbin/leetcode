package io.binac.leetcode;

/**
 * <p>Write an efficient algorithm that searches for a value in an <code>m x n</code> matrix. This matrix has the following properties:</p>
 *
 * <ul>
 * 	<li>Integers in each row are sorted from left to right.</li>
 * 	<li>The first integer of each row is greater than the last integer of the previous row.</li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/mat.jpg" style="width: 322px; height: 242px;">
 * <pre><strong>Input:</strong> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * <strong>Output:</strong> true
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg" style="width: 322px; height: 242px;">
 * <pre><strong>Input:</strong> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * <strong>Output:</strong> false
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>m == matrix.length</code></li>
 * 	<li><code>n == matrix[i].length</code></li>
 * 	<li><code>1 &lt;= m, n &lt;= 100</code></li>
 * 	<li><code>-10<sup>4</sup> &lt;= matrix[i][j], target &lt;= 10<sup>4</sup></code></li>
 * </ul>
 */
public class SearchA2DMatrix {
    public static class Solution1 {
        public boolean searchMatrix(int[][] matrix, int target) {
            final int m = matrix.length, n = matrix[0].length;
            int low = 0, high = m * n - 1, mid;
            int i, j;
            while (low <= high) {
                mid = (low + high) >>> 1;
                i = mid / n;
                j = mid % n;
                if (matrix[i][j] < target)
                    low = mid + 1;
                else if (matrix[i][j] > target)
                    high = mid - 1;
                else
                    return true;
            }
            return false;
        }
    }
}
