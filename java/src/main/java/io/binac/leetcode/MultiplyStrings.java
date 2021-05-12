package io.binac.leetcode;

/**
 * <p>Given two non-negative integers <code>num1</code> and <code>num2</code> represented as strings, return the product of <code>num1</code> and <code>num2</code>, also represented as a string.</p>
 *
 * <p><strong>Note:</strong>&nbsp;You must not use any built-in BigInteger library or convert the inputs to integer directly.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> num1 = "2", num2 = "3"
 * <strong>Output:</strong> "6"
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> num1 = "123", num2 = "456"
 * <strong>Output:</strong> "56088"
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= num1.length, num2.length &lt;= 200</code></li>
 * 	<li><code>num1</code> and <code>num2</code> consist of digits only.</li>
 * 	<li>Both <code>num1</code> and <code>num2</code>&nbsp;do not contain any leading zero, except the number <code>0</code> itself.</li>
 * </ul>
 */
public class MultiplyStrings {
    public static class Solution1 {
        public String multiply(String num1, String num2) {
            final int len1 = num1.length(), len2 = num2.length(), len = len1 + len2;
            char[] result = new char[len];
            for (int i = len1 - 1, j; i >= 0; --i) {
                for (j = len2 - 1; j >= 0; --j) {
                    result[i + j + 1] += (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
                    result[i + j] += result[i + j + 1] / 10;
                    result[i + j + 1] = (char) (result[i + j + 1] % 10);
                }
            }
            for (int i = 0; i < len; ++i) result[i] += '0';
            int offset = 0;
            while (offset + 1 < len && result[offset] == '0') ++offset;
            return new String(result, offset, len - offset);
        }
    }
}
