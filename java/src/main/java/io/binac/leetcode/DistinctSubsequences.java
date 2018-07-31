package io.binac.leetcode;

/**
 * Given a string S and a string T, count the number of distinct subsequences of S which equals T.
 * <p>
 * <p>A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: S = "rabbbit", T = "rabbit"
 *     Output: 3
 *     Explanation:
 *
 *     As shown below, there are 3 ways you can generate "rabbit" from S.
 *     (The caret symbol ^ means the chosen letters)
 *
 *     rabbbit
 *     ^^^^ ^^
 *     rabbbit
 *     ^^ ^^^^
 *     rabbbit
 *     ^^^ ^^^
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: S = "babgbag", T = "bag"
 *     Output: 5
 *     Explanation:
 *
 *     As shown below, there are 5 ways you can generate "bag" from S.
 *     (The caret symbol ^ means the chosen letters)
 *
 *     babgbag
 *     ^^ ^
 *     babgbag
 *     ^^    ^
 *     babgbag
 *     ^    ^^
 *     babgbag
 *       ^  ^^
 *     babgbag
 *         ^^^
 * </blockquote></pre>
 */
public class DistinctSubsequences {
    public static class Solution1 {
        public int numDistinct(String s, String t) {
            final int lenS = s.length(), lenT = t.length();
            if (lenS < lenT) return 0;

            int dp[][] = new int[lenS + 1][lenT + 1];
            for (int i = 0; i <= lenS; ++i) dp[i][0] = 1;
            for (int i = 1; i <= lenS; ++i) {
                final int end = Math.min(i, lenT);
                for (int j = 1; j <= end; ++j) {
                    if (s.charAt(i - 1) == t.charAt(j - 1))
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
            return dp[lenS][lenT];
        }
    }
}
