package io.binac.leetcode;

/**
 * <p>Implement <a href="http://www.cplusplus.com/reference/valarray/pow/" target="_blank">pow(<em>x</em>, <em>n</em>)</a>, which calculates&nbsp;<em>x</em> raised to the power <em>n</em> (i.e. x<sup><span style="font-size:10.8333px">n</span></sup>).</p>
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> x = 2.00000, n = 10
 * <strong>Output:</strong> 1024.00000
 * </pre>
 * <p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> x = 2.10000, n = 3
 * <strong>Output:</strong> 9.26100
 * </pre>
 * <p><strong>Example 3:</strong></p>
 * <pre><strong>Input:</strong> x = 2.00000, n = -2
 * <strong>Output:</strong> 0.25000
 * <strong>Explanation:</strong> 2<sup>-2</sup> = 1/2<sup>2</sup> = 1/4 = 0.25
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 * <ul>
 * <li><code>-100.0 &lt;&nbsp;x&nbsp;&lt; 100.0</code></li>
 * <li><code>-2<sup>31</sup>&nbsp;&lt;= n &lt;=&nbsp;2<sup>31</sup>-1</code></li>
 * <li><code>-10<sup>4</sup> &lt;= x<sup>n</sup> &lt;= 10<sup>4</sup></code></li>
 * </ul>
 */
public class PowXN {
    public static class Solution1 {
        public double myPow(double x, int n) {
            if (n == 0) return 1;

            double result = 1;
            for (long e = Math.abs((long) n); e > 0; e >>= 1) {
                if ((e & 1) == 1)
                    result = result * x;
                x *= x;
            }
            return n >= 0 ? result : 1 / result;
        }
    }
}
