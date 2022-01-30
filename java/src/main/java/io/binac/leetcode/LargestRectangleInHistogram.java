package io.binac.leetcode;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * <p>Given an array of integers <code>heights</code> representing the histogram's bar height where the width of each bar is <code>1</code>, return <em>the area of the largest rectangle in the histogram</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg" style="width: 522px; height: 242px;">
 * <pre><strong>Input:</strong> heights = [2,1,5,6,2,3]
 * <strong>Output:</strong> 10
 * <strong>Explanation:</strong> The above is a histogram where width of each bar is 1.
 * The largest rectangle is shown in the red area, which has an area = 10 units.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/histogram-1.jpg" style="width: 202px; height: 362px;">
 * <pre><strong>Input:</strong> heights = [2,4]
 * <strong>Output:</strong> 4
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= heights.length &lt;= 10<sup>5</sup></code></li>
 * 	<li><code>0 &lt;= heights[i] &lt;= 10<sup>4</sup></code></li>
 * </ul>
 */
public class LargestRectangleInHistogram {
    public static class Solution1 {
        public int largestRectangleArea(int[] heights) {
            Deque<Integer> stack = new ArrayDeque<>();
            int result = 0;
            int left, j;
            for (int i = 0; i < heights.length; ++i) {
                while (!stack.isEmpty() && heights[i] <= heights[stack.peek()]) {
                    j = stack.pop();
                    left = stack.isEmpty() ? 0 : stack.peek() + 1;
                    result = Math.max(result, heights[j] * (i - left));
                }
                stack.push(i);
            }
            while (!stack.isEmpty()) {
                j = stack.pop();
                left = stack.isEmpty() ? 0 : stack.peek() + 1;
                result = Math.max(result, heights[j] * (heights.length - left));
            }
            return result;
        }
    }
}
