package io.binac.leetcode;

/**
 * Given a 32-bit signed integer, reverse digits of an integer.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: 123
 *     Output: 321
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: -123
 *     Output: -321
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input: 120
 *     Output: 21
 * </blockquote></pre>
 * Note:
 * <p>Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */
public class ReverseInteger {
    public static class Solution1 {
        public int reverse(int x) {
            int sign = x >= 0 ? 1 : -1;
            long val = x;
            val = val >= 0 ? val : -val;
            long result = 0;
            while (val > 0) {
                result = result * 10 + val % 10;
                val /= 10;
            }
            if ((sign == 1 && result > Integer.MAX_VALUE)
                    || (sign == -1 && result - 1 > Integer.MAX_VALUE))
                return 0;
            return (int) (sign * result);
        }
    }
}
