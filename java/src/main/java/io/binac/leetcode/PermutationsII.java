package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * <p>Given a collection of numbers, <code>nums</code>,&nbsp;that might contain duplicates, return <em>all possible unique permutations <strong>in any order</strong>.</em></p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [1,1,2]
 * <strong>Output:</strong>
 * [[1,1,2],
 *  [1,2,1],
 *  [2,1,1]]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [1,2,3]
 * <strong>Output:</strong> [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= nums.length &lt;= 8</code></li>
 * 	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
 * </ul>
 */
public class PermutationsII {
    public static class Solution1 {
        private void permuteUnique(int[] sorted, List<List<Integer>> result, List<Integer> path, boolean[] visited) {
            if (path.size() == sorted.length) {
                result.add(new ArrayList<>(path));
                return;
            }
            for (int i = 0, last = -1; i < sorted.length; ++i) {
                if (visited[i] || (last != -1 && sorted[i] == sorted[last]))
                    continue;
                last = i;
                path.add(sorted[i]);
                visited[i] = true;
                permuteUnique(sorted, result, path, visited);
                visited[i] = false;
                path.remove(path.size() - 1);
            }
        }

        public List<List<Integer>> permuteUnique(int[] nums) {
            Arrays.sort(nums);
            List<List<Integer>> result = new ArrayList<>();
            permuteUnique(nums, result, new ArrayList<>(nums.length), new boolean[nums.length]);
            return result;
        }
    }
}
