package io.binac.leetcode;

/**
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * <p>
 * <p>Note: For the purpose of this problem, we define empty string as valid palindrome.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: "A man, a plan, a canal: Panama"
 *     Output: true
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: "race a car"
 *     Output: false
 * </blockquote></pre>
 */
public class ValidPalindrome {
    public static class Solution1 {
        public boolean isPalindrome(String s) {
            char str[] = s.toLowerCase().toCharArray();
            int i = 0, j = str.length - 1;
            while (i < j) {
                if (!Character.isLetterOrDigit(str[i])) {
                    ++i;
                } else if (!Character.isLetterOrDigit(str[j])) {
                    --j;
                } else if (str[i] != str[j]) {
                    return false;
                } else {
                    ++i;
                    --j;
                }
            }
            return true;
        }
    }
}
