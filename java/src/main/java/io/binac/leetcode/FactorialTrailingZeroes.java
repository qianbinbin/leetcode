package io.binac.leetcode;

/**
 * <p>Given an integer <code>n</code>, return <em>the number of trailing zeroes in </em><code>n!</code>.</p>
 *
 * <p>Note that <code>n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1</code>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 3
 * <strong>Output:</strong> 0
 * <strong>Explanation:</strong> 3! = 6, no trailing zero.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 5
 * <strong>Output:</strong> 1
 * <strong>Explanation:</strong> 5! = 120, one trailing zero.
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 0
 * <strong>Output:</strong> 0
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>0 &lt;= n &lt;= 10<sup>4</sup></code></li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <p><strong>Follow up:</strong> Could you write a solution that works in logarithmic time complexity?</p>
 */
public class FactorialTrailingZeroes {
    public static class Solution1 {
        public int trailingZeroes(int n) {
            int result = 0;
            while (n != 0)
                result += (n /= 5);
            return result;
        }
    }
}
