package io.binac.leetcode;

/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 * <p>
 * <p>http://www.leetcode.com/static/images/problemset/rainwatertrap.png
 * <p>The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 *     Output: 6
 * </blockquote></pre>
 */
public class TrappingRainWater {
    public static class Solution1 {
        public int trap(int[] height) {
            if (height.length < 3) return 0;

            int leftMax[] = new int[height.length];
            int rightMax[] = new int[height.length];
            for (int i = 1; i < height.length; ++i)
                leftMax[i] = Math.max(leftMax[i - 1], height[i - 1]);
            for (int i = height.length - 2; i >= 0; --i)
                rightMax[i] = Math.max(rightMax[i + 1], height[i + 1]);

            int result = 0;
            for (int i = 1; i < height.length - 1; ++i) {
                final int h = Math.min(leftMax[i], rightMax[i]) - height[i];
                if (h > 0) result += h;
            }
            return result;
        }
    }

    public static class Solution2 {
        public int trap(int[] height) {
            if (height.length < 3) return 0;

            int result = 0;
            int stack[] = new int[height.length];
            int top = -1;
            for (int i = 0; i < height.length; ++i) {
                while (top != -1 && height[i] > height[stack[top]]) {
                    int j = stack[top--];
                    if (top == -1) break;
                    int leftBound = stack[top];
                    int length = i - leftBound - 1;
                    int h = Math.min(height[i], height[leftBound]) - height[j];
                    result += length * h;
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
            int left = 0, right = height.length - 1;
            int leftMax = 0, rightMax = 0;
            while (left < right) {
                if (height[left] < height[right]) {
                    if (height[left] < leftMax)
                        result += leftMax - height[left];
                    else
                        leftMax = height[left];
                    ++left;
                } else {
                    if (height[right] < rightMax)
                        result += rightMax - height[right];
                    else
                        rightMax = height[right];
                    --right;
                }
            }
            return result;
        }
    }
}
