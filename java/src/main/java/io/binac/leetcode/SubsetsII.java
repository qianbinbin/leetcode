package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 * <p>
 * <p>Note: The solution set must not contain duplicate subsets.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: [1,2,2]
 *     Output:
 *     [
 *       [2],
 *       [1],
 *       [1,2,2],
 *       [2,2],
 *       [1,2],
 *       []
 *     ]
 * </blockquote></pre>
 */
public class SubsetsII {
    public static class Solution1 {
        private void subsetsWithDup(int[] sorted, int index, List<List<Integer>> result, List<Integer> path) {
            result.add(new ArrayList<>(path));
            int last = -1;
            for (int i = index; i < sorted.length; ++i) {
                if (last != -1 && sorted[i] == sorted[last]) continue;
                last = i;
                path.add(sorted[i]);
                subsetsWithDup(sorted, i + 1, result, path);
                path.remove(path.size() - 1);
            }
        }

        public List<List<Integer>> subsetsWithDup(int[] nums) {
            Arrays.sort(nums);
            List<List<Integer>> result = new ArrayList<>();
            List<Integer> path = new ArrayList<>(nums.length);
            subsetsWithDup(nums, 0, result, path);
            return result;
        }
    }
}
