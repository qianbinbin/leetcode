package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: [1,1,2]
 *     Output:
 *     [
 *       [1,1,2],
 *       [1,2,1],
 *       [2,1,1]
 *     ]
 * </blockquote></pre>
 */
public class PermutationsII {
    public static class Solution1 {
        private void permuteUnique(int[] sorted, List<List<Integer>> result, List<Integer> path, boolean visited[]) {
            if (path.size() == sorted.length) {
                result.add(new ArrayList<>(path));
                return;
            }
            for (int i = 0; i < sorted.length; ++i) {
                if (visited[i] || (i > 0 && sorted[i] == sorted[i - 1] && !visited[i - 1]))
                    continue;
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
            List<Integer> path = new ArrayList<>(nums.length);
            boolean visited[] = new boolean[nums.length];
            permuteUnique(nums, result, path, visited);
            return result;
        }
    }
}
