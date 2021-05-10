package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * <p>Given a collection of candidate numbers (<code>candidates</code>) and a target number (<code>target</code>), find all unique combinations in <code>candidates</code>&nbsp;where the candidate numbers sum to <code>target</code>.</p>
 *
 * <p>Each number in <code>candidates</code>&nbsp;may only be used <strong>once</strong> in the combination.</p>
 *
 * <p><strong>Note:</strong>&nbsp;The solution set must not contain duplicate combinations.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> candidates = [10,1,2,7,6,1,5], target = 8
 * <strong>Output:</strong>
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> candidates = [2,5,2,1,2], target = 5
 * <strong>Output:</strong>
 * [
 * [1,2,2],
 * [5]
 * ]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;=&nbsp;candidates.length &lt;= 100</code></li>
 * 	<li><code>1 &lt;=&nbsp;candidates[i] &lt;= 50</code></li>
 * 	<li><code>1 &lt;= target &lt;= 30</code></li>
 * </ul>
 */
public class CombinationSumII {
    public static class Solution1 {
        private void combinationSum2(int[] sortedArray, int index, int target, int sum,
                                     List<List<Integer>> result, List<Integer> path) {
            if (sum == target) {
                result.add(new ArrayList<>(path));
                return;
            }
            for (int prev = -1, val; index < sortedArray.length; ++index) {
                val = sortedArray[index];
                if (sum + val > target) break;
                if (val == prev) continue;
                prev = val;

                path.add(val);
                combinationSum2(sortedArray, index + 1, target, sum + val, result, path);
                path.remove(path.size() - 1);
            }
        }

        public List<List<Integer>> combinationSum2(int[] candidates, int target) {
            int[] sortedArray = Arrays.copyOf(candidates, candidates.length);
            Arrays.sort(sortedArray);
            List<List<Integer>> result = new ArrayList<>();
            combinationSum2(sortedArray, 0, target, 0, result, new ArrayList<>());
            return result;
        }
    }
}
