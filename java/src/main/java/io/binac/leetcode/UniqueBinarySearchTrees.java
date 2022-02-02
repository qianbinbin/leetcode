package io.binac.leetcode;

/**
 * <p>Given an integer <code>n</code>, return <em>the number of structurally unique <strong>BST'</strong>s (binary search trees) which has exactly </em><code>n</code><em> nodes of unique values from</em> <code>1</code> <em>to</em> <code>n</code>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg" style="width: 600px; height: 148px;">
 * <pre><strong>Input:</strong> n = 3
 * <strong>Output:</strong> 5
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 1
 * <strong>Output:</strong> 1
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= n &lt;= 19</code></li>
 * </ul>
 */
public class UniqueBinarySearchTrees {
    public static class Solution1 {
        public int numTrees(int n) {
            int[] dp = new int[n + 1];
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
            long result = 1;
            for (int i = 1; i <= n; ++i)
                result = result * (n + i) / i;
            return (int) (result / (n + 1));
        }
    }
}
