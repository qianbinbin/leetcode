package io.binac.leetcode;

/**
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * <p>
 * <p>If the last word does not exist, return 0.
 * <p>
 * <p>Note: A word is defined as a character sequence consists of non-space characters only.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: "Hello World"
 *     Output: 5
 * </blockquote></pre>
 */
public class LengthOfLastWord {
    public static class Solution1 {
        public int lengthOfLastWord(String s) {
            final int len = s.length();
            if (len == 0) return 0;
            int end = len - 1;
            while (end >= 0 && s.charAt(end) == ' ')
                --end;
            if (end < 0) return 0;
            int start = end - 1;
            while (start >= 0 && s.charAt(start) != ' ')
                --start;
            return end - start;
        }
    }
}
