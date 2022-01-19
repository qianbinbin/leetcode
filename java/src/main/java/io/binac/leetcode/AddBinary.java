package io.binac.leetcode;

/**
 * <p>Given two binary strings <code>a</code> and <code>b</code>, return <em>their sum as a binary string</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> a = "11", b = "1"
 * <strong>Output:</strong> "100"
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> a = "1010", b = "1011"
 * <strong>Output:</strong> "10101"
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= a.length, b.length &lt;= 10<sup>4</sup></code></li>
 * 	<li><code>a</code> and <code>b</code> consist&nbsp;only of <code>'0'</code> or <code>'1'</code> characters.</li>
 * 	<li>Each string does not contain leading zeros except for the zero itself.</li>
 * </ul>
 */
public class AddBinary {
    public static class Solution1 {
        public String addBinary(String a, String b) {
            final int len1 = a.length(), len2 = b.length();
            final int len = Math.max(len1, len2) + 1;
            char[] bits = new char[len];
            int i = len1 - 1, j = len2 - 1, k = len - 1;
            int carry = 0;
            for (; i >= 0 && j >= 0; --i, --j, --k) {
                int sum = a.charAt(i) - '0' + b.charAt(j) - '0' + carry;
                bits[k] = (char) (sum % 2 + '0');
                carry = sum / 2;
            }
            for (; i >= 0; --i, --k) {
                int sum = a.charAt(i) - '0' + carry;
                bits[k] = (char) (sum % 2 + '0');
                carry = sum / 2;
            }
            for (; j >= 0; --j, --k) {
                int sum = b.charAt(j) - '0' + carry;
                bits[k] = (char) (sum % 2 + '0');
                carry = sum / 2;
            }
            if (carry != 0)
                bits[k--] = '1';
            return new String(bits, k + 1, len - k - 1);
        }
    }
}
