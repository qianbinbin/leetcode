package io.binac.leetcode;

import java.util.Arrays;
import java.util.Stack;

/**
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input:
 *     [
 *       ["1","0","1","0","0"],
 *       ["1","0","1","1","1"],
 *       ["1","1","1","1","1"],
 *       ["1","0","0","1","0"]
 *     ]
 *     Output: 6
 * </blockquote></pre>
 */
public class MaximalRectangle {
    public static class Solution1 {
        public int maximalRectangle(char[][] matrix) {
            final int row = matrix.length;
            if (row == 0) return 0;
            final int col = matrix[0].length;

            int start[] = new int[col], end[] = new int[col], height[] = new int[col];
            Arrays.fill(end, col);
            int max = 0;
            for (int i = 0; i < row; ++i) {
                int s = 0;
                for (int j = 0; j < col; ++j) {
                    if (matrix[i][j] == '1') {
                        start[j] = Math.max(start[j], s);
                        ++height[j];
                    } else {
                        start[j] = 0;
                        s = j + 1;
                        height[j] = 0;
                    }
                }
                int e = col;
                for (int j = col - 1; j >= 0; --j) {
                    if (matrix[i][j] == '1') {
                        end[j] = Math.min(end[j], e);
                        max = Math.max(max, height[j] * (end[j] - start[j]));
                    } else {
                        end[j] = col;
                        e = j;
                    }
                }
            }
            return max;
        }
    }

    public static class Solution2 {
        public int maximalRectangle(char[][] matrix) {
            final int row = matrix.length;
            if (row == 0) return 0;
            final int col = matrix[0].length;

            int max = 0;
            int heights[] = new int[col];
            Stack<Integer> stack = new Stack<>();
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (matrix[i][j] == '1')
                        ++heights[j];
                    else
                        heights[j] = 0;
                    while (!stack.empty() && heights[stack.peek()] > heights[j]) {
                        int index = stack.pop();
                        max = Math.max(max, heights[index] * (stack.empty() ? j : j - stack.peek() - 1));
                    }
                    stack.push(j);
                }
                while (!stack.empty()) {
                    int index = stack.pop();
                    max = Math.max(max, heights[index] * (stack.empty() ? col : col - stack.peek() - 1));
                }
            }
            return max;
        }
    }
}
