package io.binac.leetcode;

/**
 * <p>Given an input string (<code>s</code>) and a pattern (<code>p</code>), implement wildcard pattern matching with support for <code>'?'</code> and <code>'*'</code> where:</p>
 *
 * <ul>
 * 	<li><code>'?'</code> Matches any single character.</li>
 * 	<li><code>'*'</code> Matches any sequence of characters (including the empty sequence).</li>
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
 * <pre><strong>Input:</strong> s = "aa", p = "*"
 * <strong>Output:</strong> true
 * <strong>Explanation:</strong>&nbsp;'*' matches any sequence.
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "cb", p = "?a"
 * <strong>Output:</strong> false
 * <strong>Explanation:</strong>&nbsp;'?' matches 'c', but the second letter is 'a', which does not match 'b'.
 * </pre>
 *
 * <p><strong>Example 4:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "adceb", p = "*a*b"
 * <strong>Output:</strong> true
 * <strong>Explanation:</strong>&nbsp;The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
 * </pre>
 *
 * <p><strong>Example 5:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "acdcb", p = "a*c?b"
 * <strong>Output:</strong> false
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>0 &lt;= s.length, p.length &lt;= 2000</code></li>
 * 	<li><code>s</code> contains only lowercase English letters.</li>
 * 	<li><code>p</code> contains only lowercase English letters, <code>'?'</code> or <code>'*'</code>.</li>
 * </ul>
 */
public class WildcardMatching {
    public static class Solution1 {
        public boolean isMatch(String s, String p) {
            final int m = s.length(), n = p.length();
            boolean[][] match = new boolean[m + 1][n + 1];
            match[0][0] = true;
            for (int j = 1; j <= n && p.charAt(j - 1) == '*'; ++j)
                match[0][j] = true;

            char ch;
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    ch = p.charAt(j - 1);
                    if (ch == '*')
                        match[i][j] = match[i - 1][j] || match[i][j - 1];
                    else if (ch == '?' || ch == s.charAt(i - 1))
                        match[i][j] = match[i - 1][j - 1];
                }
            }
            return match[m][n];
        }
    }

    public static class Solution2 {
        public boolean isMatch(String s, String p) {
            final int m = s.length(), n = p.length();
            int i = 0, j = 0;
            int star = -1, lastI = -1;
            char ch;
            while (i < m) {
                ch = j < n ? p.charAt(j) : '\0';
                if (ch == '?' || ch == s.charAt(i)) {
                    ++i;
                    ++j;
                } else if (ch == '*') {
                    lastI = i;
                    star = j;
                    ++j;
                } else if (star != -1) {
                    i = ++lastI;
                    j = star + 1;
                } else {
                    return false;
                }
            }
            while (j < n && p.charAt(j) == '*') ++j;
            return j == n;
        }
    }
}
