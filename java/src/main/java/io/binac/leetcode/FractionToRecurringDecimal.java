package io.binac.leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * <p>Given two integers representing the <code>numerator</code> and <code>denominator</code> of a fraction, return <em>the fraction in string format</em>.</p>
 *
 * <p>If the fractional part is repeating, enclose the repeating part in parentheses.</p>
 *
 * <p>If multiple answers are possible, return <strong>any of them</strong>.</p>
 *
 * <p>It is <strong>guaranteed</strong> that the length of the answer string is less than <code>10<sup>4</sup></code> for all the given inputs.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> numerator = 1, denominator = 2
 * <strong>Output:</strong> "0.5"
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> numerator = 2, denominator = 1
 * <strong>Output:</strong> "2"
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> numerator = 4, denominator = 333
 * <strong>Output:</strong> "0.(012)"
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>-2<sup>31</sup> &lt;=&nbsp;numerator, denominator &lt;= 2<sup>31</sup> - 1</code></li>
 * 	<li><code>denominator != 0</code></li>
 * </ul>
 */
public class FractionToRecurringDecimal {
    public static class Solution1 {
        public String fractionToDecimal(int numerator, int denominator) {
            if (numerator == 0)
                return "0";
            StringBuilder sb = new StringBuilder();
            if (numerator >= 0 != denominator >= 0)
                sb.append('-');
            long n = Math.abs((long) numerator), m = Math.abs((long) denominator);
            sb.append(n / m);
            n %= m;
            if (n == 0)
                return sb.toString();
            sb.append('.');
            Map<Long, Integer> map = new HashMap<>();
            map.put(n, sb.length());
            while (n != 0) {
                n *= 10;
                sb.append(n / m);
                n %= m;
                if (map.containsKey(n)) {
                    sb.insert(map.get(n), "(");
                    sb.append(')');
                    return sb.toString();
                }
                map.put(n, sb.length());
            }
            return sb.toString();
        }
    }
}
