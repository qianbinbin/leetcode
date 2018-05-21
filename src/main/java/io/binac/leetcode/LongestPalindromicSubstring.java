package io.binac.leetcode;

/**
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: "babad"
 *     Output: "bab"
 *     Note: "aba" is also a valid answer.
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: "cbbd"
 *     Output: "bb"
 * </blockquote></pre>
 */
public class LongestPalindromicSubstring {
    /**
     * Dynamic programming
     */
    public static class Solution1 {
        public String longestPalindrome(String s) {
            final int len = s.length();
            int start = 0, longest = 0;
            boolean dp[][] = new boolean[len][len];
            for (int i = len - 1; i >= 0; --i) {
                for (int j = i; j < len; ++j) {
                    if (i == j || (s.charAt(i) == s.charAt(j) && (i + 1 == j || dp[i + 1][j - 1]))) {
                        dp[i][j] = true;
                        if (j - i + 1 > longest) {
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
