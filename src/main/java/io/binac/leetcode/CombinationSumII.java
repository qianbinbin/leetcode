package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 * <p>
 * <p>Each number in candidates may only be used once in the combination.
 * <p>
 * <p>Note:
 * <p>
 * <p>All numbers (including target) will be positive integers.
 * <p>The solution set must not contain duplicate combinations.
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: candidates = [10,1,2,7,6,1,5], target = 8,
 *     A solution set is:
 *     [
 *       [1, 7],
 *       [1, 2, 5],
 *       [2, 6],
 *       [1, 1, 6]
 *     ]
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: candidates = [2,5,2,1,2], target = 5,
 *     A solution set is:
 *     [
 *       [1,2,2],
 *       [5]
 *     ]
 * </blockquote></pre>
 */
public class CombinationSumII {
    public static class Solution1 {
        private void combinationSum2(int[] sortedArray, int index, int target, int sum,
                                     List<List<Integer>> result, List<Integer> path) {
            if (sum == target) {
                result.add(new ArrayList<>(path));
                return;
            }
            int prev = -1;
            for (int i = index; i < sortedArray.length; ++i) {
                final int val = sortedArray[i];
                if (sum + val > target) break;
                if (val == prev) continue;
                prev = val;

                path.add(val);
                combinationSum2(sortedArray, i + 1, target, sum + val, result, path);
                path.remove(path.size() - 1);
            }
        }

        public List<List<Integer>> combinationSum2(int[] candidates, int target) {
            if (candidates.length == 0)
                throw new IllegalArgumentException();
            if (target <= 0)
                throw new IllegalArgumentException();

            int sortedArray[] = Arrays.copyOf(candidates, candidates.length);
            Arrays.sort(sortedArray);
            List<List<Integer>> result = new ArrayList<>();
            List<Integer> path = new ArrayList<>();
            combinationSum2(sortedArray, 0, target, 0, result, path);
            return result;
        }
    }
}
