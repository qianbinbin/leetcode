package io.binac.leetcode;

/**
 * Implement int sqrt(int x).
 * <p>
 * <p>Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 * <p>
 * <p>Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: 4
 *     Output: 2
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: 8
 *     Output: 2
 *     Explanation: The square root of 8 is 2.82842..., and since
 *                  the decimal part is truncated, 2 is returned.
 * </blockquote></pre>
 */
public class SqrtX {
    public static class Solution1 {
        public int mySqrt(int x) {
            if (x < 0)
                throw new IllegalArgumentException("x must be a non-negative integer");
            if (x < 2) return x;

            long low = 1, high = x / 2;
            while (low <= high) {
                long mid = (low + high) >>> 1;
                long square = mid * mid, squareUpper = (mid + 1) * (mid + 1);
                if (square <= x && x < squareUpper)
                    return (int) mid;
                else if (square > x)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            throw new RuntimeException();
        }
    }

    public static class Solution2 {
        public int mySqrt(int x) {
            if (x < 0)
                throw new IllegalArgumentException("x must be a non-negative integer");
            if (x < 2) return x;
            long result = x / 2;
            while (!(result * result <= x && x < (result + 1) * (result + 1))) {
                result = (result + x / result) / 2;
            }
            return (int) result;
        }
    }
}
