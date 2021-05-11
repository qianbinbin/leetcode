package io.binac.leetcode;

/**
 * <p>Given <code>n</code> non-negative integers representing an elevation map where the width of each bar is <code>1</code>, compute how much water it can trap after raining.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img src="https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png" style="width: 412px; height: 161px;">
 * <pre><strong>Input:</strong> height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * <strong>Output:</strong> 6
 * <strong>Explanation:</strong> The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> height = [4,2,0,3,2,5]
 * <strong>Output:</strong> 9
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>n == height.length</code></li>
 * 	<li><code>0 &lt;= n &lt;= 3 * 10<sup>4</sup></code></li>
 * 	<li><code>0 &lt;= height[i] &lt;= 10<sup>5</sup></code></li>
 * </ul>
 */
public class TrappingRainWater {
    public static class Solution1 {
        public int trap(int[] height) {
            if (height.length < 3) return 0;

            int result = 0;
            int[] leftMax = new int[height.length];
            int[] rightMax = new int[height.length];
            for (int i = 1; i < height.length; ++i)
                leftMax[i] = Math.max(leftMax[i - 1], height[i - 1]);
            for (int i = height.length - 2, h; i > 0; --i) {
                rightMax[i] = Math.max(rightMax[i + 1], height[i + 1]);
                h = Math.min(leftMax[i], rightMax[i]) - height[i];
                if (h > 0) result += h;
            }
            return result;
        }
    }

    public static class Solution2 {
        public int trap(int[] height) {
            if (height.length < 3) return 0;

            int result = 0;
            int[] stack = new int[height.length];
            int top = -1;
            for (int i = 0, j, leftBound; i < height.length; ++i) {
                while (top != -1 && height[i] > height[j = stack[top]]) {
                    if (--top == -1) break;
                    leftBound = stack[top];
                    result += (i - leftBound - 1) * (Math.min(height[i], height[leftBound]) - height[j]);
                }
                stack[++top] = i;
            }
            return result;
        }
    }

    public static class Solution3 {
        public int trap(int[] height) {
            if (height.length < 3) return 0;

            int result = 0;
            int i = 0, j = height.length - 1;
            int leftMax = 0, rightMax = 0;
            while (i < j) {
                if (height[i] <= height[j]) {
                    if (leftMax <= height[i])
                        leftMax = height[i];
                    else
                        result += leftMax - height[i];
                    ++i;
                } else {
                    if (rightMax <= height[j])
                        rightMax = height[j];
                    else
                        result += rightMax - height[j];
                    --j;
                }
            }
            return result;
        }
    }
}
