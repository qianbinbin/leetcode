package io.binac.leetcode;

/**
 * <p>Given a string <code>s</code>, return&nbsp;<em>the longest palindromic substring</em> in <code>s</code>.</p>
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> s = "babad"
 * <strong>Output:</strong> "bab"
 * <strong>Note:</strong> "aba" is also a valid answer.
 * </pre>
 * <p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> s = "cbbd"
 * <strong>Output:</strong> "bb"
 * </pre>
 * <p><strong>Example 3:</strong></p>
 * <pre><strong>Input:</strong> s = "a"
 * <strong>Output:</strong> "a"
 * </pre>
 * <p><strong>Example 4:</strong></p>
 * <pre><strong>Input:</strong> s = "ac"
 * <strong>Output:</strong> "a"
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 * <ul>
 * <li><code>1 &lt;= s.length &lt;= 1000</code></li>
 * <li><code>s</code> consist of only digits and English letters (lower-case and/or upper-case),</li>
 * </ul>
 */
public class LongestPalindromicSubstring {
    public static class Solution1 {
        public String longestPalindrome(String s) {
            final int len = s.length();
            int start = 0, longest = 0;
            boolean[][] dp = new boolean[len][len];
            for (int i = len - 1; i >= 0; --i) {
                for (int j = i; j < len; ++j) {
                    if (i == j || (s.charAt(i) == s.charAt(j) && (i + 1 == j || dp[i + 1][j - 1]))) {
                        dp[i][j] = true;
                        if (j - i + 1 >= longest) {
                            start = i;
                            longest = j - i + 1;
                        }
                    }
                }
            }
            return s.substring(start, start + longest);
        }
    }
}
