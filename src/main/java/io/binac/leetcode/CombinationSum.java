package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 * <p>
 * <p>The same repeated number may be chosen from candidates unlimited number of times.
 * <p>
 * <p>Note:
 * <p>
 * <p>All numbers (including target) will be positive integers.
 * <p>The solution set must not contain duplicate combinations.
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: candidates = [2,3,6,7], target = 7,
 *     A solution set is:
 *     [
 *       [7],
 *       [2,2,3]
 *     ]
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: candidates = [2,3,5], target = 8,
 *     A solution set is:
 *     [
 *       [2,2,2,2],
 *       [2,3,3],
 *       [3,5]
 *     ]
 * </blockquote></pre>
 */
public class CombinationSum {
    public static class Solution1 {
        private void combinationSum(int[] candidates, int index, int target, List<List<Integer>> result,
                                    List<Integer> path, int sum) {
            if (sum == target)
                result.add(new ArrayList<>(path));
            if (sum > target)
                return;
            for (int i = index; i < candidates.length; ++i) {
                path.add(candidates[i]);
                combinationSum(candidates, i, target, result, path, sum + candidates[i]);
                path.remove(path.size() - 1);
            }
        }

        public List<List<Integer>> combinationSum(int[] candidates, int target) {
            if (candidates.length == 0)
                throw new IllegalArgumentException();
            if (target <= 0)
                throw new IllegalArgumentException();

            List<List<Integer>> result = new ArrayList<>();
            List<Integer> path = new ArrayList<>();
            combinationSum(candidates, 0, target, result, path, 0);
            return result;
        }
    }
}
