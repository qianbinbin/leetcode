package io.binac.leetcode;

/**
 * <p>Given a string <code>s</code>, partition <code>s</code> such that every substring of the partition is a palindrome.</p>
 *
 * <p>Return <em>the minimum cuts needed</em> for a palindrome partitioning of <code>s</code>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "aab"
 * <strong>Output:</strong> 1
 * <strong>Explanation:</strong> The palindrome partitioning ["aa","b"] could be produced using 1 cut.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "a"
 * <strong>Output:</strong> 0
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "ab"
 * <strong>Output:</strong> 1
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
 * 	<li><code>s</code> consists of lower-case English letters only.</li>
 * </ul>
 */
public class PalindromePartitioningII {
    public static class Solution1 {
        public int minCut(String s) {
            final char[] chars = s.toCharArray();
            final int len = chars.length;

            int[] cut = new int[len + 1];
            for (int i = 0; i <= len; ++i) cut[i] = len - i - 1;
            boolean[][] dp = new boolean[len][len];
            for (int i = len - 1, j; i >= 0; --i) {
                for (j = i; j < len; ++j) {
                    if (chars[i] == chars[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                        dp[i][j] = true;
                        cut[i] = Math.min(cut[i], cut[j + 1] + 1);
                    }
                }
            }
            return cut[0];
        }
    }

    public static class Solution2 {
        public int minCut(String s) {
            final char[] chars = s.toCharArray();
            final int len = chars.length;

            int[] cut = new int[len + 1];
            for (int i = 0; i <= len; ++i) cut[i] = i - 1;

            for (int i = 0; i < len; ++i) {
                for (int l = 0; i - l >= 0 && i + l < len && chars[i - l] == chars[i + l]; ++l)
                    cut[i + l + 1] = Math.min(cut[i + l + 1], cut[i - l] + 1);
                for (int l = 0; i - l >= 0 && i + l + 1 < len && chars[i - l] == chars[i + l + 1]; ++l)
                    cut[i + l + 2] = Math.min(cut[i + l + 2], cut[i - l] + 1);
            }
            return cut[len];
        }
    }
}
