package io.binac.leetcode;

/**
 * Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
 * <p>
 * <p>You have the following 3 operations permitted on a word:
 * <p>
 * <p>Insert a character
 * <p>Delete a character
 * <p>Replace a character
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: word1 = "horse", word2 = "ros"
 *     Output: 3
 *     Explanation:
 *     horse -> rorse (replace 'h' with 'r')
 *     rorse -> rose (remove 'r')
 *     rose -> ros (remove 'e')
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: word1 = "intention", word2 = "execution"
 *     Output: 5
 *     Explanation:
 *     intention -> inention (remove 't')
 *     inention -> enention (replace 'i' with 'e')
 *     enention -> exention (replace 'n' with 'x')
 *     exention -> exection (replace 'n' with 'c')
 *     exection -> execution (insert 'u')
 * </blockquote></pre>
 */
public class EditDistance {
    public static class Solution1 {
        public int minDistance(String word1, String word2) {
            final int len1 = word1.length(), len2 = word2.length();
            int dp[][] = new int[len1 + 1][len2 + 1];
            for (int j = 0; j <= len2; ++j) dp[0][j] = j;
            for (int i = 0; i <= len1; ++i) dp[i][0] = i;
            for (int i = 1; i <= len1; ++i) {
                for (int j = 1; j <= len2; ++j) {
                    if (word1.charAt(i - 1) == word2.charAt(j - 1))
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
            return dp[len1][len2];
        }
    }
}
