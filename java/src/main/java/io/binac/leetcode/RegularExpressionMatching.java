package io.binac.leetcode;

import java.util.Arrays;

/**
 * <p>Given an input string (<code>s</code>) and a pattern (<code>p</code>), implement regular expression matching with support for <code>'.'</code> and <code>'*'</code> where:<code>&nbsp;</code></p>
 *
 * <ul>
 * 	<li><code>'.'</code> Matches any single character.​​​​</li>
 * 	<li><code>'*'</code> Matches zero or more of the preceding element.</li>
 * </ul>
 *
 * <p>The matching should cover the <strong>entire</strong> input string (not partial).</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "aa", p = "a"
 * <strong>Output:</strong> false
 * <strong>Explanation:</strong> "a" does not match the entire string "aa".
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "aa", p = "a*"
 * <strong>Output:</strong> true
 * <strong>Explanation:</strong>&nbsp;'*' means zero or more of the preceding&nbsp;element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "ab", p = ".*"
 * <strong>Output:</strong> true
 * <strong>Explanation:</strong>&nbsp;".*" means "zero or more (*) of any character (.)".
 * </pre>
 *
 * <p><strong>Example 4:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "aab", p = "c*a*b"
 * <strong>Output:</strong> true
 * <strong>Explanation:</strong>&nbsp;c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
 * </pre>
 *
 * <p><strong>Example 5:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "mississippi", p = "mis*is*p*."
 * <strong>Output:</strong> false
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>0 &lt;= s.length&nbsp;&lt;= 20</code></li>
 * 	<li><code>0 &lt;= p.length&nbsp;&lt;= 30</code></li>
 * 	<li><code>s</code> contains only lowercase English letters.</li>
 * 	<li><code>p</code> contains only lowercase English letters, <code>'.'</code>, and&nbsp;<code>'*'</code>.</li>
 * 	<li>It is guaranteed for each appearance of the character <code>'*'</code>, there will be a previous valid character to match.</li>
 * </ul>
 */
public class RegularExpressionMatching {
    /**
     * Recursion
     */
    public static class Solution1 {
        private boolean match(char[] s, int i, char[] p, int j) {
            if (p[j] == '\0')
                return s[i] == '\0';
            if (s[i] == '\0')
                return p[j + 1] == '*' && match(s, i, p, j + 2);
            if (p[j + 1] == '*') {
                if (p[j] == '.' || s[i] == p[j])
                    return match(s, i, p, j + 2) || match(s, i + 1, p, j);
                return match(s, i, p, j + 2);
            }
            return (p[j] == '.' || s[i] == p[j]) && match(s, i + 1, p, j + 1);
        }

        public boolean isMatch(String s, String p) {
            return match((s + '\0').toCharArray(), 0, (p + '\0').toCharArray(), 0);
        }
    }

    /**
     * Dynamic programming
     */
    public static class Solution2 {
        private static boolean match(char ch, char p) {
            return p == '.' || ch == p;
        }

        public boolean isMatch(String s, String p) {
            final int row = s.length() + 1, col = p.length() + 1;
            if (col == 1)
                return row == 1;
            boolean[][] dp = new boolean[row][col];
            dp[0][0] = true;
            for (int j = 2; j < col && p.charAt(j - 1) == '*'; j += 2) dp[0][j] = true;
            if (row > 1 && match(s.charAt(0), p.charAt(0))) dp[1][1] = true;

            for (int i = 1; i < row; ++i) {
                for (int j = 2; j < col; ++j) {
                    final char chS = s.charAt(i - 1), chP = p.charAt(j - 1);
                    if (chP != '*') {
                        dp[i][j] = dp[i - 1][j - 1] && match(chS, chP);
                    } else {
                        dp[i][j] = dp[i][j - 2] || (match(chS, p.charAt(j - 2)) && dp[i - 1][j]);
                    }
                }
            }
            return dp[row - 1][col - 1];
        }
    }
}
