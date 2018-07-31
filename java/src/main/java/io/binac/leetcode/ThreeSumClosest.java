package io.binac.leetcode;

import java.util.Arrays;

/**
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Given array nums = [-1, 2, 1, -4], and target = 1.
 *
 *     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * </blockquote></pre>
 */
public class ThreeSumClosest {
    public static class Solution1 {
        public int threeSumClosest(int[] nums, int target) {
            if (nums.length < 3)
                throw new IllegalArgumentException("nums.length can't be less than 3");

            int values[] = new int[nums.length];
            System.arraycopy(nums, 0, values, 0, nums.length);
            Arrays.sort(values);

            int result = values[0] + values[1] + values[2];
            for (int start = 0; start < values.length - 2; ) {
                int low = start + 1, high = values.length - 1;
                while (low < high) {
                    final int sum = values[start] + values[low] + values[high];
                    if (Math.abs(sum - target) < Math.abs(result - target))
                        result = sum;
                    if (sum < target) {
                        do {
                            ++low;
                        } while (low < high && values[low] == values[low - 1]);
                    } else if (sum > target) {
                        do {
                            --high;
                        } while (high > low && values[high] == values[high + 1]);
                    } else {
                        return result;
                    }
                }
                do {
                    ++start;
                } while (start < values.length - 2 && values[start] == values[start - 1]);
            }
            return result;
        }
    }
}
