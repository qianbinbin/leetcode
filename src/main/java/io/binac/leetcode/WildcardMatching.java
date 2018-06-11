package io.binac.leetcode;

/**
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
 * <blockquote><pre>
 *     '?' Matches any single character.
 *     '*' Matches any sequence of characters (including the empty sequence).
 * </blockquote></pre>
 * <p>The matching should cover the entire input string (not partial).
 * <p>
 * <p>Note:
 * <p>
 * <p>s could be empty and contains only lowercase letters a-z.
 * <p>p could be empty and contains only lowercase letters a-z, and characters like ? or *.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input:
 *     s = "aa"
 *     p = "a"
 *     Output: false
 *     Explanation: "a" does not match the entire string "aa".
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input:
 *     s = "aa"
 *     p = "*"
 *     Output: true
 *     Explanation: '*' matches any sequence.
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input:
 *     s = "cb"
 *     p = "?a"
 *     Output: false
 *     Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 * </blockquote></pre>
 * Example 4:
 * <blockquote><pre>
 *     Input:
 *     s = "adceb"
 *     p = "*a*b"
 *     Output: true
 *     Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
 * </blockquote></pre>
 * Example 5:
 * <blockquote><pre>
 *     Input:
 *     s = "acdcb"
 *     p = "a*c?b"
 *     Output: false
 * </blockquote></pre>
 */
public class WildcardMatching {
    public static class Solution1 {
        public boolean isMatch(String s, String p) {
            final int lenS = s.length(), lenP = p.length();

            boolean match[][] = new boolean[lenS + 1][lenP + 1];
            match[0][0] = true;
            for (int j = 1; j <= lenP; ++j) {
                if (p.charAt(j - 1) == '*' && match[0][j - 1])
                    match[0][j] = true;
                else break;
            }

            for (int i = 1; i <= lenS; ++i) {
                for (int j = 1; j <= lenP; ++j) {
                    final char ch = p.charAt(j - 1);
                    if (ch == '*')
                        match[i][j] = match[i - 1][j] || match[i][j - 1];
                    else if (ch == '?' || ch == s.charAt(i - 1))
                        match[i][j] = match[i - 1][j - 1];
                }
            }
            return match[lenS][lenP];
        }
    }
}
