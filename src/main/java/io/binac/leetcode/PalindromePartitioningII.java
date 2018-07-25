package io.binac.leetcode;

/**
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * <p>
 * <p>Return the minimum cuts needed for a palindrome partitioning of s.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: "aab"
 *     Output: 1
 *     Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
 * </blockquote></pre>
 */
public class PalindromePartitioningII {
    public static class Solution1 {
        public int minCut(String s) {
            final char chars[] = s.toCharArray();
            final int len = chars.length;

            int cut[] = new int[len + 1];
            for (int i = 0; i <= len; ++i) cut[i] = len - i - 1;
            boolean dp[][] = new boolean[len][len];
            for (int i = len - 1; i >= 0; --i) {
                for (int j = i; j < len; ++j) {
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
            final char chars[] = s.toCharArray();
            final int len = chars.length;

            int cut[] = new int[len + 1];
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
