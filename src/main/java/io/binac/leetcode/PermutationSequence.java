package io.binac.leetcode;

import java.util.concurrent.atomic.AtomicInteger;

/**
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * <p>
 * <p>By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
 * <p>
 * <p>"123"
 * <p>"132"
 * <p>"213"
 * <p>"231"
 * <p>"312"
 * <p>"321"
 * <p>
 * <p>Given n and k, return the kth permutation sequence.
 * <p>
 * <p>Note:
 * <p>
 * <p>Given n will be between 1 and 9 inclusive.
 * <p>Given k will be between 1 and n! inclusive.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: n = 3, k = 3
 *     Output: "213"
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: n = 4, k = 9
 *     Output: "2314"
 * </blockquote></pre>
 */
public class PermutationSequence {
    public static class Solution1 {
        private boolean getPermutation(int n, int k, boolean[] visited, AtomicInteger count, char[] path, int index) {
            if (index == n)
                return count.incrementAndGet() == k;

            for (int i = 0; i < n; ++i) {
                if (visited[i]) continue;
                visited[i] = true;
                path[index] = (char) ('1' + i);
                if (getPermutation(n, k, visited, count, path, index + 1)) return true;
                visited[i] = false;
            }
            return false;
        }

        public String getPermutation(int n, int k) {
            if (n < 1 || n > 9)
                throw new IllegalArgumentException("n must be between 1 and 9 inclusive");
            char path[] = new char[n];
            boolean visited[] = new boolean[n];
            if (getPermutation(n, k, visited, new AtomicInteger(), path, 0))
                return new String(path);
            throw new IllegalArgumentException("k must be between 1 and n! inclusive");
        }
    }
}
