package io.binac.leetcode;

/**
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * <p>
 * <p>Integers in each row are sorted from left to right.
 * <p>The first integer of each row is greater than the last integer of the previous row.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input:
 *     matrix = [
 *       [1,   3,  5,  7],
 *       [10, 11, 16, 20],
 *       [23, 30, 34, 50]
 *     ]
 *     target = 3
 *     Output: true
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input:
 *     matrix = [
 *       [1,   3,  5,  7],
 *       [10, 11, 16, 20],
 *       [23, 30, 34, 50]
 *     ]
 *     target = 13
 *     Output: false
 * </blockquote></pre>
 */
public class SearchA2DMatrix {
    public static class Solution1 {
        public boolean searchMatrix(int[][] matrix, int target) {
            final int row = matrix.length;
            if (row == 0) return false;
            final int col = matrix[0].length;

            int low = 0, high = row * col - 1;
            while (low <= high) {
                int mid = (low + high) >>> 1;
                int i = mid / col, j = mid % col;
                int val = matrix[i][j];
                if (val == target)
                    return true;
                else if (val < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            return false;
        }
    }
}
