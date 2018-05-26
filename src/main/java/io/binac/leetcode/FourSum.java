package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 * <p>
 * <p>Note:
 * <p>
 * <p>The solution set must not contain duplicate quadruplets.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 *     A solution set is:
 *     [
 *       [-1,  0, 0, 1],
 *       [-2, -1, 1, 2],
 *       [-2,  0, 0, 2]
 *     ]
 * </blockquote></pre>
 */
public class FourSum {
    public static class Solution1 {
        public List<List<Integer>> fourSum(int[] nums, int target) {
            // if (nums.length < 4)
            //     throw new IllegalArgumentException("nums.length can't be less than 4");

            int values[] = new int[nums.length];
            System.arraycopy(nums, 0, values, 0, nums.length);
            Arrays.sort(values);

            List<List<Integer>> result = new ArrayList<>();
            for (int first = 0; first < values.length - 3; ) {
                for (int second = first + 1; second < values.length - 2; ) {
                    int low = second + 1, high = values.length - 1;
                    final int sum = target - values[first] - values[second];
                    while (low < high) {
                        if (values[low] + values[high] < sum) {
                            do {
                                ++low;
                            } while (low < high && values[low] == values[low - 1]);
                        } else if (values[low] + values[high] > sum) {
                            do {
                                --high;
                            } while (low < high && values[high] == values[high + 1]);
                        } else {
                            result.add(Arrays.asList(values[first], values[second], values[low], values[high]));
                            do {
                                ++low;
                            } while (low < high && values[low] == values[low - 1]);
                            do {
                                --high;
                            } while (low < high && values[high] == values[high + 1]);
                        }
                    }
                    do {
                        ++second;
                    } while (second < values.length - 2 && values[second] == values[second - 1]);
                }
                do {
                    ++first;
                } while (first < values.length - 2 && values[first] == values[first - 1]);
            }
            return result;
        }
    }
}
