package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * <p>The set <code>[1, 2, 3, ...,&nbsp;n]</code> contains a total of <code>n!</code> unique permutations.</p>
 *
 * <p>By listing and labeling all of the permutations in order, we get the following sequence for <code>n = 3</code>:</p>
 *
 * <ol>
 * 	<li><code>"123"</code></li>
 * 	<li><code>"132"</code></li>
 * 	<li><code>"213"</code></li>
 * 	<li><code>"231"</code></li>
 * 	<li><code>"312"</code></li>
 * 	<li><code>"321"</code></li>
 * </ol>
 *
 * <p>Given <code>n</code> and <code>k</code>, return the <code>k<sup>th</sup></code> permutation sequence.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> n = 3, k = 3
 * <strong>Output:</strong> "213"
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> n = 4, k = 9
 * <strong>Output:</strong> "2314"
 * </pre><p><strong>Example 3:</strong></p>
 * <pre><strong>Input:</strong> n = 3, k = 1
 * <strong>Output:</strong> "123"
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= n &lt;= 9</code></li>
 * 	<li><code>1 &lt;= k &lt;= n!</code></li>
 * </ul>
 */
public class PermutationSequence {
    public static class Solution1 {
        public String getPermutation(int n, int k) {
            int[] factorial = new int[n + 1];
            factorial[0] = 1;
            factorial[1] = 1;
            for (int i = 2; i <= n; ++i)
                factorial[i] = i * factorial[i - 1];

            List<Character> chars = new ArrayList<>();
            for (int i = 0; i < n; ++i) chars.add((char) ('1' + i));
            char[] result = new char[n];
            --k;
            for (int i = 0, index; i < n; ++i) {
                index = k / factorial[n - i - 1];
                result[i] = chars.remove(index);
                k = k % factorial[n - i - 1];
            }
            return new String(result);
        }
    }
}
