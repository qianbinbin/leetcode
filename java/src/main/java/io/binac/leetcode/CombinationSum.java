package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>Given an array of <strong>distinct</strong> integers <code>candidates</code> and a target integer <code>target</code>, return <em>a list of all <strong>unique combinations</strong> of </em><code>candidates</code><em> where the chosen numbers sum to </em><code>target</code><em>.</em> You may return the combinations in <strong>any order</strong>.</p>
 *
 * <p>The <strong>same</strong> number may be chosen from <code>candidates</code> an <strong>unlimited number of times</strong>. Two combinations are unique if the frequency of at least one of the chosen numbers is different.</p>
 *
 * <p>It is <strong>guaranteed</strong> that the number of unique combinations that sum up to <code>target</code> is less than <code>150</code> combinations for the given input.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> candidates = [2,3,6,7], target = 7
 * <strong>Output:</strong> [[2,2,3],[7]]
 * <strong>Explanation:</strong>
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> candidates = [2,3,5], target = 8
 * <strong>Output:</strong> [[2,2,2,2],[2,3,3],[3,5]]
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> candidates = [2], target = 1
 * <strong>Output:</strong> []
 * </pre>
 *
 * <p><strong>Example 4:</strong></p>
 *
 * <pre><strong>Input:</strong> candidates = [1], target = 1
 * <strong>Output:</strong> [[1]]
 * </pre>
 *
 * <p><strong>Example 5:</strong></p>
 *
 * <pre><strong>Input:</strong> candidates = [1], target = 2
 * <strong>Output:</strong> [[1,1]]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= candidates.length &lt;= 30</code></li>
 * 	<li><code>1 &lt;= candidates[i] &lt;= 200</code></li>
 * 	<li>All elements of <code>candidates</code> are <strong>distinct</strong>.</li>
 * 	<li><code>1 &lt;= target &lt;= 500</code></li>
 * </ul>
 */
public class CombinationSum {
    public static class Solution1 {
        private void combinationSum(int[] candidates, int index, int target, List<List<Integer>> result,
                                    List<Integer> path, int sum) {
            if (sum == target) {
                result.add(new ArrayList<>(path));
                return;
            }
            for (; index < candidates.length; ++index) {
                if (candidates[index] + sum > target)
                    continue;
                path.add(candidates[index]);
                combinationSum(candidates, index, target, result, path, sum + candidates[index]);
                path.remove(path.size() - 1);
            }
        }

        public List<List<Integer>> combinationSum(int[] candidates, int target) {
            List<List<Integer>> result = new ArrayList<>();
            combinationSum(candidates, 0, target, result, new ArrayList<>(), 0);
            return result;
        }
    }
}
