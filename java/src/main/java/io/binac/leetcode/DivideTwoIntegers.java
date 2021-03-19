package io.binac.leetcode;

/**
 * <p>Given two integers <code>dividend</code> and <code>divisor</code>, divide two integers without using multiplication, division, and mod operator.</p>
 *
 * <p>Return the quotient after dividing <code>dividend</code> by <code>divisor</code>.</p>
 *
 * <p>The integer division should truncate toward zero, which means losing its fractional part. For example, <code>truncate(8.345) = 8</code> and <code>truncate(-2.7335) = -2</code>.</p>
 *
 * <p><strong>Note:</strong></p>
 *
 * <ul>
 * 	<li>Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2<sup>31</sup>, &nbsp;2<sup>31</sup> − 1]. For this problem, assume that your function <strong>returns 2<sup>31</sup> − 1 when the division result&nbsp;overflows</strong>.</li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> dividend = 10, divisor = 3
 * <strong>Output:</strong> 3
 * <strong>Explanation:</strong> 10/3 = truncate(3.33333..) = 3.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> dividend = 7, divisor = -3
 * <strong>Output:</strong> -2
 * <strong>Explanation:</strong> 7/-3 = truncate(-2.33333..) = -2.
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> dividend = 0, divisor = 1
 * <strong>Output:</strong> 0
 * </pre>
 *
 * <p><strong>Example 4:</strong></p>
 *
 * <pre><strong>Input:</strong> dividend = 1, divisor = 1
 * <strong>Output:</strong> 1
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>-2<sup>31</sup> &lt;= dividend,&nbsp;divisor &lt;= 2<sup>31</sup> - 1</code></li>
 * 	<li><code>divisor != 0</code></li>
 * </ul>
 */
public class DivideTwoIntegers {
    public static class Solution1 {
        public int divide(int dividend, int divisor) {
            if (divisor == 0)
                throw new ArithmeticException("divisor can't be 0");
            if (dividend == Integer.MIN_VALUE && divisor == -1)
                return Integer.MAX_VALUE;

            boolean sign = dividend >= 0 == divisor >= 0;
            dividend = Math.abs(dividend);
            divisor = Math.abs(divisor);
            int result = 0, exp;
            while (dividend - divisor >= 0) {
                exp = 0;
                while (dividend - (divisor << exp << 1) >= 0)
                    ++exp;
                result += 1 << exp;
                dividend -= divisor << exp;
            }
            return sign ? result : -result;
        }
    }
}
