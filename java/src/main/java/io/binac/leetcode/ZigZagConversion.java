package io.binac.leetcode;

/**
 * <p>The string <code>"PAYPALISHIRING"</code> is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)</p>
 *
 * <pre>P   A   H   N
 * A P L S I I G
 * Y   I   R
 * </pre>
 *
 * <p>And then read line by line: <code>"PAHNAPLSIIGYIR"</code></p>
 *
 * <p>Write the code that will take a string and make this conversion given a number of rows:</p>
 *
 * <pre>string convert(string s, int numRows);
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "PAYPALISHIRING", numRows = 3
 * <strong>Output:</strong> "PAHNAPLSIIGYIR"
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "PAYPALISHIRING", numRows = 4
 * <strong>Output:</strong> "PINALSIGYAHRPI"
 * <strong>Explanation:</strong>
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "A", numRows = 1
 * <strong>Output:</strong> "A"
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
 * 	<li><code>s</code> consists of English letters (lower-case and upper-case), <code>','</code> and <code>'.'</code>.</li>
 * 	<li><code>1 &lt;= numRows &lt;= 1000</code></li>
 * </ul>
 */
public class ZigZagConversion {
    public static class Solution1 {
        public String convert(String s, int numRows) {
            final int len = s.length();
            if (numRows == 1 || numRows >= len)
                return s;

            StringBuilder sb = new StringBuilder();
            final int cycle = 2 * (numRows - 1);
            int index;
            for (index = 0; index < len; index += cycle)
                sb.append(s.charAt(index));
            for (int i = 1; i < numRows - 1; ++i) {
                final int offset = 2 * (numRows - i - 1);
                for (index = i; index < len; index += cycle) {
                    sb.append(s.charAt(index));
                    if (index + offset < len)
                        sb.append(s.charAt(index + offset));
                }
            }
            for (index = numRows - 1; index < len; index += cycle)
                sb.append(s.charAt(index));
            return sb.toString();
        }
    }
}
