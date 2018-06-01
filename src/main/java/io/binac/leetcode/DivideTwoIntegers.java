package io.binac.leetcode;

/**
 * Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
 * <p>
 * <p>Return the quotient after dividing dividend by divisor.
 * <p>
 * <p>The integer division should truncate toward zero.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: dividend = 10, divisor = 3
 *     Output: 3
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: dividend = 7, divisor = -3
 *     Output: -2
 * </blockquote></pre>
 * <p>Note:
 * <p>
 * <p>Both dividend and divisor will be 32-bit signed integers.
 * <p>The divisor will never be 0.
 * <p>Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
 */
public class DivideTwoIntegers {
    public static class Solution1 {
        public int divide(int dividend, int divisor) {
            if (divisor == 0)
                throw new ArithmeticException("divisor can't be 0");

            boolean sign = dividend >= 0 == divisor > 0;
            long dvd = Math.abs((long) dividend), dvs = Math.abs((long) divisor);

            long result = 0;
            while (dvd >= dvs) {
                long sub = dvs, count = 1;
                while (dvd >= sub) {
                    sub <<= 1;
                    count <<= 1;
                }
                dvd -= sub >> 1;
                result += count >> 1;
            }
            if (result > Integer.MAX_VALUE)
                return sign ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            return (int) (sign ? result : -result);
        }
    }
}
