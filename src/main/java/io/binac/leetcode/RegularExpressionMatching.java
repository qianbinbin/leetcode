package io.binac.leetcode;

/**
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 * <blockquote><pre>
 *     '.' Matches any single character.
 *     '*' Matches zero or more of the preceding element.
 * </blockquote></pre>
 * The matching should cover the entire input string (not partial).
 * <p>
 * <p>Note:
 * <p>
 * <p>s could be empty and contains only lowercase letters a-z.
 * <p>p could be empty and contains only lowercase letters a-z, and characters like . or *.
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
 *     p = "a*"
 *     Output: true
 *     Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input:
 *     s = "ab"
 *     p = ".*"
 *     Output: true
 *     Explanation: ".*" means "zero or more (*) of any character (.)".
 * </blockquote></pre>
 * Example 4:
 * <blockquote><pre>
 *     Input:
 *     s = "aab"
 *     p = "c*a*b"
 *     Output: true
 *     Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
 * </blockquote></pre>
 * Example 5:
 * <blockquote><pre>
 *     Input:
 *     s = "mississippi"
 *     p = "mis*is*p*."
 *     Output: false
 * </blockquote></pre>
 */
public class RegularExpressionMatching {
    /**
     * Recursion
     */
    public static class Solution1 {
        public boolean isMatch(String s, String p) {
            if (s.isEmpty() && p.isEmpty()) return true;
            if (s.isEmpty())
                return p.length() >= 2 && p.charAt(1) == '*' && isMatch(s, p.substring(2));
            if (p.isEmpty())
                return false;

            char firstS = s.charAt(0), firstP = p.charAt(0);
            boolean firstMatch = firstP == '.' || firstS == firstP;
            if (p.length() == 1)
                return s.length() == 1 && firstMatch;

            char secondP = p.charAt(1);
            if (secondP == '*') {
                if (firstMatch)
                    return isMatch(s, p.substring(2)) || isMatch(s.substring(1), p);
                else
                    return isMatch(s, p.substring(2));
            } else {
                return firstMatch && isMatch(s.substring(1), p.substring(1));
            }
        }
    }
}
