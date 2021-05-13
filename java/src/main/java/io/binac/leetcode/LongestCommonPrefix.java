package io.binac.leetcode;

/**
 * <p>Write a function to find the longest common prefix string amongst an array of strings.</p>
 * <p>If there is no common prefix, return an empty string <code>""</code>.</p>
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> strs = ["flower","flow","flight"]
 * <strong>Output:</strong> "fl"
 * </pre>
 * <p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> strs = ["dog","racecar","car"]
 * <strong>Output:</strong> ""
 * <strong>Explanation:</strong> There is no common prefix among the input strings.
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 * <ul>
 * <li><code>0 &lt;= strs.length &lt;= 200</code></li>
 * <li><code>0 &lt;= strs[i].length &lt;= 200</code></li>
 * <li><code>strs[i]</code> consists of only lower-case English letters.</li>
 * </ul>
 */
public class LongestCommonPrefix {
    public static class Solution1 {
        public String longestCommonPrefix(String[] strs) {
            if (strs.length == 0)
                return "";

            char ch;
            for (int j = 0, n = strs[0].length(), i, m = strs.length; j < n; ++j) {
                ch = strs[0].charAt(j);
                for (i = 1; i < m; ++i) {
                    if (j >= strs[i].length() || ch != strs[i].charAt(j))
                        return strs[0].substring(0, j);
                }
            }
            return strs[0];
        }
    }
}
