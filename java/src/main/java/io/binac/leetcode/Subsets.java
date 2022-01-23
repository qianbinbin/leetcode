package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>Given an integer array <code>nums</code> of <strong>unique</strong> elements, return <em>all possible subsets (the power set)</em>.</p>
 *
 * <p>The solution set <strong>must not</strong> contain duplicate subsets. Return the solution in <strong>any order</strong>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [1,2,3]
 * <strong>Output:</strong> [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [0]
 * <strong>Output:</strong> [[],[0]]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= nums.length &lt;= 10</code></li>
 * 	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
 * 	<li>All the numbers of&nbsp;<code>nums</code> are <strong>unique</strong>.</li>
 * </ul>
 */
public class Subsets {
    public static class Solution1 {
        private void subsets(int[] nums, int i, List<List<Integer>> result, List<Integer> path) {
            result.add(new ArrayList<>(path));
            for (; i < nums.length; ++i) {
                path.add(nums[i]);
                subsets(nums, i + 1, result, path);
                path.remove(path.size() - 1);
            }
        }

        public List<List<Integer>> subsets(int[] nums) {
            List<List<Integer>> result = new ArrayList<>();
            subsets(nums, 0, result, new ArrayList<>());
            return result;
        }
    }
}
