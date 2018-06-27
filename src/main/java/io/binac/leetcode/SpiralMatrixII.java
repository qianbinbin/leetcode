package io.binac.leetcode;

/**
 * Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: 3
 *     Output:
 *     [
 *      [ 1, 2, 3 ],
 *      [ 8, 9, 4 ],
 *      [ 7, 6, 5 ]
 *     ]
 * </blockquote></pre>
 */
public class SpiralMatrixII {
    public static class Solution1 {
        public int[][] generateMatrix(int n) {
            if (n < 0)
                throw new IllegalArgumentException("n can't be negative");
            if (n == 0)
                return new int[0][];

            int[][] result = new int[n][n];
            int value = 1;
            int left = 0, right = n - 1, top = 0, bottom = n - 1;
            while (true) {
                for (int j = left; j <= right; ++j)
                    result[top][j] = value++;
                ++top;
                if (top > bottom) break;
                for (int i = top; i <= bottom; ++i)
                    result[i][right] = value++;
                --right;
                if (left > right) break;
                for (int j = right; j >= left; --j)
                    result[bottom][j] = value++;
                --bottom;
                if (top > bottom) break;
                for (int i = bottom; i >= top; --i)
                    result[i][left] = value++;
                ++left;
                if (left > right) break;
            }
            return result;
        }
    }
}
