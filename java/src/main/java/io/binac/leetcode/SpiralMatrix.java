package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input:
 *     [
 *      [ 1, 2, 3 ],
 *      [ 4, 5, 6 ],
 *      [ 7, 8, 9 ]
 *     ]
 *     Output: [1,2,3,6,9,8,7,4,5]
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input:
 *     [
 *       [1, 2, 3, 4],
 *       [5, 6, 7, 8],
 *       [9,10,11,12]
 *     ]
 *     Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * </blockquote></pre>
 */
public class SpiralMatrix {
    public static class Solution1 {
        public List<Integer> spiralOrder(int[][] matrix) {
            final int row = matrix.length;
            if (row == 0)
                return Collections.emptyList();
            final int col = matrix[0].length;
            if (col == 0)
                return Collections.emptyList();

            List<Integer> result = new ArrayList<>(row * col);
            int left = 0, right = col - 1, top = 0, bottom = row - 1;
            while (true) {
                for (int j = left; j <= right; ++j)
                    result.add(matrix[top][j]);
                if (++top > bottom) break;
                for (int i = top; i <= bottom; ++i)
                    result.add(matrix[i][right]);
                if (left > --right) break;
                for (int j = right; j >= left; --j)
                    result.add(matrix[bottom][j]);
                if (top > --bottom) break;
                for (int i = bottom; i >= top; --i)
                    result.add(matrix[i][left]);
                if (++left > right) break;
            }
            return result;
        }
    }
}
