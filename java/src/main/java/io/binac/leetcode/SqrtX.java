package io.binac.leetcode;

/**
 * <p>Given a non-negative integer <code>x</code>,&nbsp;compute and return <em>the square root of</em> <code>x</code>.</p>
 *
 * <p>Since the return type&nbsp;is an integer, the decimal digits are <strong>truncated</strong>, and only <strong>the integer part</strong> of the result&nbsp;is returned.</p>
 *
 * <p><strong>Note:&nbsp;</strong>You are not allowed to use any built-in exponent function or operator, such as <code>pow(x, 0.5)</code> or&nbsp;<code>x ** 0.5</code>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> x = 4
 * <strong>Output:</strong> 2
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> x = 8
 * <strong>Output:</strong> 2
 * <strong>Explanation:</strong> The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.</pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>0 &lt;= x &lt;= 2<sup>31</sup> - 1</code></li>
 * </ul>
 */
public class SqrtX {
    public static class Solution1 {
        public int mySqrt(int x) {
            int low = 0, high = Math.max(Math.min(x / 2, 1 << 16), 1), mid;
            while (low <= high) {
                mid = (low + high) >>> 1;
                if (mid * mid - x > 0)
                    high = mid - 1;
                else if ((mid + 1) * (mid + 1) - x <= 0)
                    low = mid + 1;
                else
                    return mid;
            }
            throw new RuntimeException();
        }
    }

    public static class Solution2 {
        public int mySqrt(int x) {
            if (x < 2)
                return x;
            long result = x / 2;
            while (!(result * result <= x && x < (result + 1) * (result + 1))) {
                result = (result + x / result) / 2;
            }
            return (int) result;
        }
    }

    public static class Solution3 {
        public int mySqrt(int x) {
            int result = 0;
            int odd = 1;
            while (x >= odd) {
                x -= odd;
                ++result;
                odd += 2;
            }
            return result;
        }
    }
}
