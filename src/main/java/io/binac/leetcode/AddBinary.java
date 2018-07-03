package io.binac.leetcode;

/**
 * Given two binary strings, return their sum (also a binary string).
 * <p>
 * <p>The input strings are both non-empty and contains only characters 1 or 0.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: a = "11", b = "1"
 *     Output: "100"
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: a = "1010", b = "1011"
 *     Output: "10101"
 * </blockquote></pre>
 */
public class AddBinary {
    public static class Solution1 {
        public String addBinary(String a, String b) {
            final int len1 = a.length(), len2 = b.length();
            if (len1 == 0) return b;
            if (len2 == 0) return a;

            final int len = Math.max(len1, len2) + 1;
            char bits[] = new char[len];
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
