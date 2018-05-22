package io.binac.leetcode;

/**
 * Implement atoi which converts a string to an integer.
 * <p>
 * <p>The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 * <p>
 * <p>The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 * <p>
 * <p>If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 * <p>
 * <p>If no valid conversion could be performed, a zero value is returned.
 * <p>
 * <p>Note:
 * <p>
 * <p>Only the space character ' ' is considered as whitespace character.
 * <p>Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: "42"
 *     Output: 42
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: "   -42"
 *     Output: -42
 *     Explanation: The first non-whitespace character is '-', which is the minus sign.
 *                  Then take as many numerical digits as possible, which gets 42.
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input: "4193 with words"
 *     Output: 4193
 *     Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
 * </blockquote></pre>
 * Example 4:
 * <blockquote><pre>
 *     Input: "words and 987"
 *     Output: 0
 *     Explanation: The first non-whitespace character is 'w', which is not a numerical
 *                  digit or a +/- sign. Therefore no valid conversion could be performed.
 * </blockquote></pre>
 * Example 5:
 * <blockquote><pre>
 *     Input: "-91283472332"
 *     Output: -2147483648
 *     Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
 *                  Thefore INT_MIN (−231) is returned.
 * </blockquote></pre>
 */
public class StringToIntegerAtoi {
    public static class Solution1 {
        private static boolean isDigit(char c) {
            return '0' <= c && c <= '9';
        }

        public int myAtoi(String str) {
            String s = str.trim();
            if (s.isEmpty())
                return 0;

            int sign = 1;
            if (s.charAt(0) == '-')
                sign = -1;
            if (s.charAt(0) == '+' || s.charAt(0) == '-')
                s = s.substring(1);
            long result = 0;
            for (int i = 0; i < s.length() && isDigit(s.charAt(i)); ++i) {
                result = result * 10 + s.charAt(i) - '0';
                if (result > Integer.MAX_VALUE)
                    break;
            }
            if (result > Integer.MAX_VALUE)
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            return (int) (sign * result);
        }
    }
}
