package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * <p>
 * <p>Note:
 * <p>
 * <p>The solution set must not contain duplicate triplets.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 *     A solution set is:
 *     [
 *       [-1, 0, 1],
 *       [-1, -1, 2]
 *     ]
 * </blockquote></pre>
 */
public class ThreeSum {
    public static class Solution1 {
        public List<List<Integer>> threeSum(int[] nums) {
            // if (nums.length < 3)
            //     throw new IllegalArgumentException("nums.length can't be less than 3");

            int values[] = new int[nums.length];
            System.arraycopy(nums, 0, values, 0, nums.length);
            Arrays.sort(values);

            List<List<Integer>> result = new ArrayList<>();
            for (int start = 0; start < values.length - 2; ) {
                final int sum = 0 - values[start];
                int low = start + 1, high = values.length - 1;
                while (low < high) {
                    if (values[low] + values[high] < sum) {
                        do {
                            ++low;
                        } while (low < high && values[low] == values[low - 1]);
                    } else if (values[low] + values[high] > sum) {
                        do {
                            --high;
                        } while (high > low && values[high] == values[high + 1]);
                    } else {
                        result.add(Arrays.asList(values[start], values[low], values[high]));
                        do {
                            ++low;
                        } while (low < high && values[low] == values[low - 1]);
                        do {
                            --high;
                        } while (high > low && values[high] == values[high + 1]);
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
