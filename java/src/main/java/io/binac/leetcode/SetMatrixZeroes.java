package io.binac.leetcode;

/**
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input:
 *     [
 *       [1,1,1],
 *       [1,0,1],
 *       [1,1,1]
 *     ]
 *     Output:
 *     [
 *       [1,0,1],
 *       [0,0,0],
 *       [1,0,1]
 *     ]
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input:
 *     [
 *       [0,1,2,0],
 *       [3,4,5,2],
 *       [1,3,1,5]
 *     ]
 *     Output:
 *     [
 *       [0,0,0,0],
 *       [0,4,5,0],
 *       [0,3,1,0]
 *     ]
 * </blockquote></pre>
 * Follow up:
 * <p>
 * <p>A straight forward solution using O(mn) space is probably a bad idea.
 * <p>A simple improvement uses O(m + n) space, but still not the best solution.
 * <p>Could you devise a constant space solution?
 */
public class SetMatrixZeroes {
    public static class Solution1 {
        public void setZeroes(int[][] matrix) {
            final int row = matrix.length, col = matrix[0].length;
            boolean setFirstCol = false;
            for (int i = 0; i < row; ++i) {
                if (matrix[i][0] == 0) {
                    setFirstCol = true;
                    break;
                }
            }
            boolean setFirstRow = false;
            for (int j = 0; j < col; ++j) {
                if (matrix[0][j] == 0) {
                    setFirstRow = true;
                    break;
                }
            }
            for (int i = 1; i < row; ++i) {
                for (int j = 1; j < col; ++j) {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }

            for (int i = 1; i < row; ++i) {
                if (matrix[i][0] == 0)
                    for (int j = 1; j < col; ++j) matrix[i][j] = 0;
            }
            for (int j = 1; j < col; ++j) {
                if (matrix[0][j] == 0)
                    for (int i = 1; i < row; ++i) matrix[i][j] = 0;
            }
            if (setFirstCol)
                for (int i = 0; i < row; ++i) matrix[i][0] = 0;
            if (setFirstRow)
                for (int j = 0; j < col; ++j) matrix[0][j] = 0;
        }
    }
}
