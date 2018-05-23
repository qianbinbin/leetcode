package io.binac.leetcode;

/**
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: 121
 *     Output: true
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: -121
 *     Output: false
 *     Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input: 10
 *     Output: false
 *     Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 * </blockquote></pre>
 * Follow up:
 * <p>
 * <p>Coud you solve it without converting the integer to a string?
 */
public class PalindromeNumber {
    public static class Solution1 {
        public boolean isPalindrome(int x) {
            if (x < 0) return false;
            String str = Integer.toString(x);
            String reverse = new StringBuilder(str).reverse().toString();
            return str.equals(reverse);
        }
    }
}
