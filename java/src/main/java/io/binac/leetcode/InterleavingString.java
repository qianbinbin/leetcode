package io.binac.leetcode;

/**
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 *     Output: true
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 *     Output: false
 * </blockquote></pre>
 */
public class InterleavingString {
    public static class Solution1 {
        public boolean isInterleave(String s1, String s2, String s3) {
            final int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
            if (len1 + len2 != len3) return false;
            if (len1 == 0) return s3.equals(s2);
            if (len2 == 0) return s3.equals(s1);

            boolean dp[] = new boolean[len2 + 1];
            dp[0] = true;
            for (int j = 1; j <= len2 && dp[j - 1]; ++j)
                if (s2.charAt(j - 1) == s3.charAt(j - 1)) dp[j] = true;
            for (int i = 1; i <= len1; ++i) {
                dp[0] = dp[0] && s1.charAt(i - 1) == s3.charAt(i - 1);
                for (int j = 1; j <= len2; ++j) {
                    dp[j] = (dp[j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)) ||
                            (dp[j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
                }
            }
            return dp[len2];
        }
    }
}
