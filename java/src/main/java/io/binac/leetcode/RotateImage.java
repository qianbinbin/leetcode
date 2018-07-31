package io.binac.leetcode;

/**
 * You are given an n x n 2D matrix representing an image.
 * <p>
 * <p>Rotate the image by 90 degrees (clockwise).
 * <p>
 * <p>Note:
 * <p>
 * <p>You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Given input matrix =
 *     [
 *       [1,2,3],
 *       [4,5,6],
 *       [7,8,9]
 *     ],
 *
 *     rotate the input matrix in-place such that it becomes:
 *     [
 *       [7,4,1],
 *       [8,5,2],
 *       [9,6,3]
 *     ]
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Given input matrix =
 *     [
 *       [ 5, 1, 9,11],
 *       [ 2, 4, 8,10],
 *       [13, 3, 6, 7],
 *       [15,14,12,16]
 *     ],
 *
 *     rotate the input matrix in-place such that it becomes:
 *     [
 *       [15,13, 2, 5],
 *       [14, 3, 4, 1],
 *       [12, 6, 8, 9],
 *       [16, 7,10,11]
 *     ]
 * </blockquote></pre>
 */
public class RotateImage {
    public static class Solution1 {
        public void rotate(int[][] matrix) {
            final int n = matrix.length;
            for (int i = 0; i < n - 1; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = tmp;
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n / 2; ++j) {
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[i][n - j - 1];
                    matrix[i][n - j - 1] = tmp;
                }
            }
        }
    }
}
