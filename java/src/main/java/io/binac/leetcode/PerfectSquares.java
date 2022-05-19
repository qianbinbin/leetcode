package io.binac.leetcode;

import java.util.HashSet;
import java.util.Set;

/**
 * <p>Given an integer <code>n</code>, return <em>the least number of perfect square numbers that sum to</em> <code>n</code>.</p>
 *
 * <p>A <strong>perfect square</strong> is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, <code>1</code>, <code>4</code>, <code>9</code>, and <code>16</code> are perfect squares while <code>3</code> and <code>11</code> are not.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 12
 * <strong>Output:</strong> 3
 * <strong>Explanation:</strong> 12 = 4 + 4 + 4.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 13
 * <strong>Output:</strong> 2
 * <strong>Explanation:</strong> 13 = 4 + 9.
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
 * </ul>
 */
public class PerfectSquares {
    public static class Solution1 {
        private static final int[] dp = new int[10001];

        static {
            for (int i = 0; i < dp.length; ++i) dp[i] = i;
        }

        private static int size = 2;

        public int numSquares(int n) {
            for (int i, square; size <= n; ++size) {
                for (i = 1; (square = i * i) <= size; ++i) {
                    dp[size] = Math.min(dp[size], dp[size - square] + 1);
                }
            }
            return dp[n];
        }
    }

    public static class Solution2 {
        public int numSquares(int n) {
            Set<Integer> set = new HashSet<>(), next = new HashSet<>();
            set.add(n);
            int depth = 1;
            while (!set.isEmpty()) {
                for (int v : set) {
                    for (int i = 1, square; (square = i * i) <= v; ++i) {
                        if (v == square)
                            return depth;
                        next.add(v - square);
                    }
                }
                Set<Integer> tmp = set;
                set = next;
                next = tmp;
                next.clear();
                ++depth;
            }
            throw new RuntimeException();
        }
    }

    public static class Solution3 {
        private boolean fourSquare(int n) {
            while (n % 4 == 0)
                n /= 4;
            return n % 8 == 7;
        }

        public int numSquares(int n) {
            if (fourSquare(n))
                return 4;
            for (int i = 0, square, j; (square = i * i) <= n / 2; ++i) {
                j = (int) Math.sqrt(n - square);
                if (square + j * j == n)
                    return (i == 0 ? 0 : 1) + (j == 0 ? 0 : 1);
            }
            return 3;
        }
    }
}
