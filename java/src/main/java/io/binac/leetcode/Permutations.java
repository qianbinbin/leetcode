package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>Given an array <code>nums</code> of distinct integers, return <em>all the possible permutations</em>. You can return the answer in <strong>any order</strong>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> nums = [1,2,3]
 * <strong>Output:</strong> [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> nums = [0,1]
 * <strong>Output:</strong> [[0,1],[1,0]]
 * </pre><p><strong>Example 3:</strong></p>
 * <pre><strong>Input:</strong> nums = [1]
 * <strong>Output:</strong> [[1]]
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= nums.length &lt;= 6</code></li>
 * 	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
 * 	<li>All the integers of <code>nums</code> are <strong>unique</strong>.</li>
 * </ul>
 */
public class Permutations {
    public static class Solution1 {
        private void permute(int[] nums, List<List<Integer>> result, List<Integer> path, boolean[] visited) {
            if (path.size() == nums.length) {
                result.add(new ArrayList<>(path));
                return;
            }
            for (int i = 0; i < nums.length; ++i) {
                if (visited[i]) continue;
                path.add(nums[i]);
                visited[i] = true;
                permute(nums, result, path, visited);
                visited[i] = false;
                path.remove(path.size() - 1);
            }
        }

        public List<List<Integer>> permute(int[] nums) {
            List<List<Integer>> result = new ArrayList<>();
            permute(nums, result, new ArrayList<>(nums.length), new boolean[nums.length]);
            return result;
        }
    }
}
