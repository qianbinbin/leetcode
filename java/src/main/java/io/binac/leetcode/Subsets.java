package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 * <p>
 * <p>Note: The solution set must not contain duplicate subsets.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: nums = [1,2,3]
 *     Output:
 *     [
 *       [3],
 *       [1],
 *       [2],
 *       [1,2,3],
 *       [1,3],
 *       [2,3],
 *       [1,2],
 *       []
 *     ]
 * </blockquote></pre>
 */
public class Subsets {
    public static class Solution1 {
        private void subsets(int[] nums, int index, List<List<Integer>> result, List<Integer> path) {
            result.add(new ArrayList<>(path));
            for (int i = index; i < nums.length; ++i) {
                path.add(nums[i]);
                subsets(nums, i + 1, result, path);
                path.remove(path.size() - 1);
            }
        }

        public List<List<Integer>> subsets(int[] nums) {
            final int size = 1 << nums.length;
            List<List<Integer>> result = new ArrayList<>(size);
            List<Integer> path = new ArrayList<>(nums.length);
            subsets(nums, 0, result, path);
            return result;
        }
    }
}
