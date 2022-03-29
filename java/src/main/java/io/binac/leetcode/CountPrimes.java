package io.binac.leetcode;

/**
 * <p>Given an integer <code>n</code>, return <em>the number of prime numbers that are strictly less than</em> <code>n</code>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 10
 * <strong>Output:</strong> 4
 * <strong>Explanation:</strong> There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 0
 * <strong>Output:</strong> 0
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 1
 * <strong>Output:</strong> 0
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>0 &lt;= n &lt;= 5 * 10<sup>6</sup></code></li>
 * </ul>
 */
public class CountPrimes {
    public static class Solution1 {
        public int countPrimes(int n) {
            if (n < 3)
                return 0;
            int result = 1;
            boolean[] composites = new boolean[(n + 1) / 2];
            for (int i = 3, j, step; i < n; i += 2) {
                if (composites[i / 2])
                    continue;
                ++result;
                for (j = i * 3, step = i * 2; j < n; j += step)
                    composites[j / 2] = true;
            }
            return result;
        }
    }
}
