package io.binac.leetcode;

/**
 * Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: 3
 *     Output: 5
 *     Explanation:
 *     Given n = 3, there are a total of 5 unique BST's:
 *
 *        1         3     3      2      1
 *         \       /     /      / \      \
 *          3     2     1      1   3      2
 *         /     /       \                 \
 *        2     1         2                 3
 * </blockquote></pre>
 */
public class UniqueBinarySearchTrees {
    public static class Solution1 {
        public int numTrees(int n) {
            // if (n < 1) throw new IllegalArgumentException("n must be positive");
            if (n < 2) return 1;
            int dp[] = new int[n + 1];
            dp[0] = 1;
            dp[1] = 1;
            for (int count = 2; count <= n; ++count) {
                for (int left = 0; left < count; ++left)
                    dp[count] += dp[left] * dp[count - left - 1];
            }
            return dp[n];
        }
    }

    public static class Solution2 {
        public int numTrees(int n) {
            // if (n < 1) throw new IllegalArgumentException("n must be positive");
            if (n < 2) return 1;
            long result = 1;
            for (int i = 1; i <= n; ++i)
                result = result * (n + i) / i;
            return (int) (result / (n + 1));
        }
    }
}
