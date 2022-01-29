package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * <p>Given an integer array <code>nums</code> that may contain duplicates, return <em>all possible subsets (the power set)</em>.</p>
 *
 * <p>The solution set <strong>must not</strong> contain duplicate subsets. Return the solution in <strong>any order</strong>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> nums = [1,2,2]
 * <strong>Output:</strong> [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> nums = [0]
 * <strong>Output:</strong> [[],[0]]
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= nums.length &lt;= 10</code></li>
 * 	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
 * </ul>
 */
public class SubsetsII {
    public static class Solution1 {
        private void subsetsWithDup(int[] sorted, int i, List<Integer> path, List<List<Integer>> result) {
            result.add(new ArrayList<>(path));
            while (i < sorted.length) {
                path.add(sorted[i]);
                subsetsWithDup(sorted, i + 1, path, result);
                path.remove(path.size() - 1);
                do {
                    ++i;
                } while (i < sorted.length && sorted[i] == sorted[i - 1]);
            }
        }

        public List<List<Integer>> subsetsWithDup(int[] nums) {
            Arrays.sort(nums);
            List<List<Integer>> result = new ArrayList<>();
            subsetsWithDup(nums, 0, new ArrayList<>(), result);
            return result;
        }
    }
}
