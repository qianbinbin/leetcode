package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: n = 4, k = 2
 *     Output:
 *     [
 *       [2,4],
 *       [3,4],
 *       [2,3],
 *       [1,2],
 *       [1,3],
 *       [1,4],
 *     ]
 * </blockquote></pre>
 */
public class Combinations {
    public static class Solution1 {
        private void combine(int n, int k, int start, List<Integer> path, List<List<Integer>> result) {
            if (path.size() == k) {
                result.add(new ArrayList<>(path));
                return;
            }
            for (int i = start; i <= n; ++i) {
                path.add(i);
                combine(n, k, i + 1, path, result);
                path.remove(path.size() - 1);
            }
        }

        private long factorial(int n, int k) {
            long result = 1;
            for (; k <= n; ++k) result *= k;
            return result;
        }

        private long combination(int n, int k) {
            k = Math.min(k, n - k);
            return factorial(n, n - k + 1) / factorial(k, 1);
        }

        public List<List<Integer>> combine(int n, int k) {
            if (n < 1 || k < 1 || k > n)
                throw new IllegalArgumentException();
            List<List<Integer>> result = new ArrayList<>((int) combination(n, k));
            List<Integer> path = new ArrayList<>(k);
            combine(n, k, 1, path, result);
            return result;
        }
    }
}
