package io.binac.leetcode;

/**
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * <p>
 * <p>Note: You may not slant the container and n is at least 2.
 */
public class ContainerWithMostWater {
    public static class Solution1 {
        public int maxArea(int[] height) {
            if (height.length < 2)
                throw new IllegalArgumentException("height.length must be at least 2");

            int i = 0, j = height.length - 1;
            int area = 0;
            while (i < j) {
                if (height[i] < height[j]) {
                    area = Math.max(area, (j - i) * height[i]);
                    ++i;
                } else {
                    area = Math.max(area, (j - i) * height[j]);
                    --j;
                }
            }
            return area;
        }
    }
}
