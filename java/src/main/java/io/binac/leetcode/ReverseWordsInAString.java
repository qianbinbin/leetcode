package io.binac.leetcode;

/**
 * Given an input string, reverse the string word by word.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: "the sky is blue",
 *     Output: "blue is sky the".
 * </blockquote></pre>
 * Note:
 * <p>
 * <p>A word is defined as a sequence of non-space characters.
 * <p>Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
 * <p>You need to reduce multiple spaces between two words to a single space in the reversed string.
 * <p>
 * <p>Follow up: For C programmers, try to solve it in-place in O(1) space.
 */
public class ReverseWordsInAString {
    public static class Solution1 {
        public String reverseWords(String s) {
            String words[] = s.trim().split("\\s+");
            final int half = words.length / 2;
            for (int i = 0; i < half; ++i) {
                String tmp = words[i];
                words[i] = words[words.length - i - 1];
                words[words.length - i - 1] = tmp;
            }
            return String.join(" ", words);
        }
    }
}
