package io.binac.leetcode;

import java.util.Stack;

/**
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 * <p>
 * <p>https://leetcode.com/static/images/problemset/histogram.png
 * <p>
 * <p>Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 * <p>
 * <p>https://leetcode.com/static/images/problemset/histogram_area.png
 * <p>
 * <p>The largest rectangle is shown in the shaded area, which has area = 10 unit.
 * <p>
 * Example:
 * <blockquote><pre>
 *     Input: [2,1,5,6,2,3]
 *     Output: 10
 * </blockquote></pre>
 */
public class LargestRectangleInHistogram {
    public static class Solution1 {
        public int largestRectangleArea(int[] heights) {
            if (heights.length == 0) return 0;
            Stack<Integer> stack = new Stack<>();
            int largest = 0;
            for (int i = 0; i < heights.length; ) {
                if (stack.empty() || heights[i] >= heights[stack.peek()]) {
                    stack.push(i++);
                } else {
                    int index = stack.pop();
                    largest = Math.max(largest, heights[index] * (stack.empty() ? i : i - stack.peek() - 1));
                }
            }
            while (!stack.empty()) {
                int index = stack.pop();
                largest = Math.max(largest, heights[index] * (stack.empty() ? heights.length : heights.length - stack.peek() - 1));
            }
            return largest;
        }
    }
}
