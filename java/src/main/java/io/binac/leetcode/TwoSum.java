package io.binac.leetcode;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * <p>
 * <p>You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Given nums = [2, 7, 11, 15], target = 9,
 *
 *     Because nums[0] + nums[1] = 2 + 7 = 9,
 *     return [0, 1].
 * </blockquote></pre>
 */
public class TwoSum {
    public static class Solution1 {
        public int[] twoSum(int[] nums, int target) {
            if (nums.length < 2)
                throw new IllegalArgumentException("nums too few elements: " + Arrays.toString(nums));
            Map<Integer, Integer> map = new HashMap<>();
            map.put(nums[0], 0);
            for (int i = 1; i < nums.length; ++i) {
                if (map.containsKey(target - nums[i])) {
                    int[] result = new int[2];
                    result[0] = map.get(target - nums[i]);
                    result[1] = i;
                    return result;
                }
                map.put(nums[i], i);
            }
            throw new IllegalArgumentException("No solutions found");
        }
    }
}
