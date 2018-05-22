package io.binac.leetcode;

/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * <blockquote><pre>
 *     P   A   H   N
 *     A P L S I I G
 *     Y   I   R
 * </blockquote></pre>
 * And then read line by line: "PAHNAPLSIIGYIR"
 * <p>
 * <p>Write the code that will take a string and make this conversion given a number of rows:
 * <blockquote><pre>
 *     string convert(string s, int numRows);
 * </blockquote></pre>
 * Example 1:
 * <blockquote><pre>
 *     Input: s = "PAYPALISHIRING", numRows = 3
 *     Output: "PAHNAPLSIIGYIR"
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: s = "PAYPALISHIRING", numRows = 4
 *     Output: "PINALSIGYAHRPI"
 *     Explanation:
 *
 *     P     I    N
 *     A   L S  I G
 *     Y A   H R
 *     P     I
 * </blockquote></pre>
 */
public class ZigZagConversion {
    public static class Solution1 {
        public String convert(String s, int numRows) {
            if (s == null)
                return null;
            if (numRows < 1)
                throw new IllegalArgumentException("numRows must be positive");
            if (numRows == 1)
                return s;

            final int cycle = 2 * numRows - 2;
            StringBuilder sb = new StringBuilder();

            for (int index = 0; index < s.length(); index += cycle)
                sb.append(s.charAt(index));
            for (int i = 1; i < numRows - 1; ++i) {
                final int offset = (numRows - i - 1) * 2;
                for (int index = i; index < s.length(); index += cycle) {
                    sb.append(s.charAt(index));
                    if (index + offset < s.length())
                        sb.append(s.charAt(index + offset));
                }
            }
            for (int index = numRows - 1; index < s.length(); index += cycle)
                sb.append(s.charAt(index));

            return sb.toString();
        }
    }
}
