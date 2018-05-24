package io.binac.leetcode;

/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 * <p>
 * <p>If there is no common prefix, return an empty string "".
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: ["flower","flow","flight"]
 *     Output: "fl"
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: ["dog","racecar","car"]
 *     Output: ""
 *     Explanation: There is no common prefix among the input strings.
 * </blockquote></pre>
 * Note:
 * <p>
 * <p>All given inputs are in lowercase letters a-z.
 */
public class LongestCommonPrefix {
    public static class Solution1 {
        public String longestCommonPrefix(String[] strs) {
            if (strs.length == 0)
                return "";

            final int len = strs[0].length();
            for (int i = 0; i < len; ++i) {
                final char ch = strs[0].charAt(i);
                for (int index = 1; index < strs.length; ++index) {
                    if (i >= strs[index].length() || ch != strs[index].charAt(i))
                        return strs[0].substring(0, i);
                }
            }
            return strs[0];
        }
    }
}
