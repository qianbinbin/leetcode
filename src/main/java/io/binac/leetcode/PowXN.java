package io.binac.leetcode;

/**
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: 2.00000, 10
 *     Output: 1024.00000
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: 2.10000, 3
 *     Output: 9.26100
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input: 2.00000, -2
 *     Output: 0.25000
 *     Explanation: 2^(-2) = 1/2^2 = 1/4 = 0.25
 * </blockquote></pre>
 * Note:
 * <p>
 * <p>-100.0 < x < 100.0
 * <p>n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 */
public class PowXN {
    public static class Solution1 {
        public double myPow(double x, int n) {
            if (n == 0) return 1;

            long e = Math.abs((long) n);
            double result = 1;
            while (e > 0) {
                if ((e & 1) == 1)
                    result = result * x;
                x *= x;
                e >>= 1;
            }
            return n > 0 ? result : 1 / result;
        }
    }
}
