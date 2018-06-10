package io.binac.leetcode;

/**
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: num1 = "2", num2 = "3"
 *     Output: "6"
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: num1 = "123", num2 = "456"
 *     Output: "56088"
 * </blockquote></pre>
 * Note:
 * <p>
 * <p>The length of both num1 and num2 is < 110.
 * <p>Both num1 and num2 contain only digits 0-9.
 * <p>Both num1 and num2 do not contain any leading zero, except the number 0 itself.
 * <p>You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */
public class MultiplyStrings {
    public static class Solution1 {
        public String multiply(String num1, String num2) {
            final int len1 = num1.length(), len2 = num2.length();
            final int len = len1 + len2;

            int result[] = new int[len];
            for (int i = len1 - 1; i >= 0; --i) {
                for (int j = len2 - 1; j >= 0; --j) {
                    int tmp = (num1.charAt(i) - '0') * (num2.charAt(j) - '0') + result[i + j + 1];
                    result[i + j + 1] = tmp % 10;
                    result[i + j] += tmp / 10;
                }
            }
            int start = 0;
            while (start < len && result[start] == 0) ++start;
            if (start == len) return "0";
            char value[] = new char[len - start];
            for (int i = start; i < len; ++i)
                value[i - start] = (char) (result[i] + '0');
            return new String(value);
        }
    }
}
