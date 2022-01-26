package io.binac.leetcode;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

/**
 * <p>Given a <code>rows x cols</code>&nbsp;binary <code>matrix</code> filled with <code>0</code>'s and <code>1</code>'s, find the largest rectangle containing only <code>1</code>'s and return <em>its area</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/09/14/maximal.jpg" style="width: 402px; height: 322px;">
 * <pre><strong>Input:</strong> matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * <strong>Output:</strong> 6
 * <strong>Explanation:</strong> The maximal rectangle is shown in the above picture.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> matrix = [["0"]]
 * <strong>Output:</strong> 0
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> matrix = [["1"]]
 * <strong>Output:</strong> 1
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>rows == matrix.length</code></li>
 * 	<li><code>cols == matrix[i].length</code></li>
 * 	<li><code>1 &lt;= row, cols &lt;= 200</code></li>
 * 	<li><code>matrix[i][j]</code> is <code>'0'</code> or <code>'1'</code>.</li>
 * </ul>
 */
public class MaximalRectangle {
    public static class Solution1 {
        public int maximalRectangle(char[][] matrix) {
            final int n = matrix[0].length;
            int[] begin = new int[n], end = new int[n], height = new int[n];
            int b, e;
            Arrays.fill(end, n);
            int result = 0;
            for (char[] row : matrix) {
                b = 0;
                for (int j = 0; j < n; ++j) {
                    if (row[j] == '1') {
                        begin[j] = Math.max(begin[j], b);
                        ++height[j];
                    } else {
                        begin[j] = 0;
                        b = j + 1;
                        height[j] = 0;
                    }
                }
                e = n;
                for (int j = n - 1; j >= 0; --j) {
                    if (row[j] == '1') {
                        end[j] = Math.min(end[j], e);
                        result = Math.max(result, height[j] * (end[j] - begin[j]));
                    } else {
                        end[j] = n;
                        e = j;
                    }
                }
            }
            return result;
        }
    }

    public static class Solution2 {
        public int maximalRectangle(char[][] matrix) {
            final int n = matrix[0].length;
            int result = 0;
            int[] heights = new int[n];
            Deque<Integer> stack = new ArrayDeque<>();
            int j, k, left;
            for (char[] row : matrix) {
                for (j = 0; j < n; ++j) {
                    heights[j] = row[j] == '0' ? 0 : heights[j] + 1;
                    while (!stack.isEmpty() && heights[j] <= heights[stack.peek()]) {
                        k = stack.pop();
                        left = stack.isEmpty() ? 0 : stack.peek() + 1;
                        result = Math.max(result, heights[k] * (j - left));
                    }
                    stack.push(j);
                }
                while (!stack.isEmpty()) {
                    k = stack.pop();
                    left = stack.isEmpty() ? 0 : stack.peek() + 1;
                    result = Math.max(result, heights[k] * (n - left));
                }
            }
            return result;
        }
    }
}
