package io.binac.leetcode;

/**
 * <p>Given a string <code>s</code> consists of some words separated by spaces, return <em>the length of the last word&nbsp;in the string. If the last word does not exist, return </em><code>0</code>.</p>
 *
 * <p>A <strong>word</strong> is a maximal substring consisting&nbsp;of non-space characters only.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> s = "Hello World"
 * <strong>Output:</strong> 5
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> s = " "
 * <strong>Output:</strong> 0
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
 * 	<li><code>s</code> consists of only English letters and spaces <code>' '</code>.</li>
 * </ul>
 */
public class LengthOfLastWord {
    public static class Solution1 {
        public int lengthOfLastWord(String s) {
            final int len = s.length();
            int end = len - 1;
            while (end >= 0 && s.charAt(end) == ' ')
                --end;
            int start = end - 1;
            while (start >= 0 && s.charAt(start) != ' ')
                --start;
            return end - start;
        }
    }
}
