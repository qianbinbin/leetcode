package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Given a collection of distinct integers, return all possible permutations.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: [1,2,3]
 *     Output:
 *     [
 *       [1,2,3],
 *       [1,3,2],
 *       [2,1,3],
 *       [2,3,1],
 *       [3,1,2],
 *       [3,2,1]
 *     ]
 * </blockquote></pre>
 */
public class Permutations {
    public static class Solution1 {
        private void permute(int[] nums, List<List<Integer>> result, List<Integer> path, boolean visited[]) {
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
            List<Integer> path = new ArrayList<>(nums.length);
            boolean visited[] = new boolean[nums.length];
            permute(nums, result, path, visited);
            return result;
        }
    }
}
