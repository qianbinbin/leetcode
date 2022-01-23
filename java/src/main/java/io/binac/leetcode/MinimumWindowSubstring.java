package io.binac.leetcode;

/**
 * <p>Given two strings <code>s</code> and <code>t</code> of lengths <code>m</code> and <code>n</code> respectively, return <em>the <strong>minimum window substring</strong> of </em><code>s</code><em> such that every character in </em><code>t</code><em> (<strong>including duplicates</strong>) is included in the window. If there is no such substring</em><em>, return the empty string </em><code>""</code><em>.</em></p>
 *
 * <p>The testcases will be generated such that the answer is <strong>unique</strong>.</p>
 *
 * <p>A <strong>substring</strong> is a contiguous sequence of characters within the string.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "ADOBECODEBANC", t = "ABC"
 * <strong>Output:</strong> "BANC"
 * <strong>Explanation:</strong> The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "a", t = "a"
 * <strong>Output:</strong> "a"
 * <strong>Explanation:</strong> The entire string s is the minimum window.
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "a", t = "aa"
 * <strong>Output:</strong> ""
 * <strong>Explanation:</strong> Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>m == s.length</code></li>
 * 	<li><code>n == t.length</code></li>
 * 	<li><code>1 &lt;= m, n&nbsp;&lt;= 10<sup>5</sup></code></li>
 * 	<li><code>s</code> and <code>t</code> consist of uppercase and lowercase English letters.</li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <strong>Follow up:</strong> Could you find an algorithm that runs in <code>O(m + n)</code> time?
 */
public class MinimumWindowSubstring {
    public static class Solution1 {
        public String minWindow(String s, String t) {
            final int m = s.length(), n = t.length();

            int[] expected = new int[128];
            for (int i = 0; i < n; ++i)
                ++expected[t.charAt(i)];
            int expectedCount = 0;

            int start = -1, len = Integer.MAX_VALUE;
            for (int i = 0, j = 0; j < m; ++j) {
                if (expected[s.charAt(j)]-- > 0)
                    ++expectedCount;
                for (; expectedCount == n; ++i) {
                    if (j - i + 1 < len)
                        len = j - (start = i) + 1;
                    if (++expected[s.charAt(i)] > 0)
                        --expectedCount;
                }
            }
            return start == -1 ? "" : s.substring(start, start + len);
        }
    }
}
