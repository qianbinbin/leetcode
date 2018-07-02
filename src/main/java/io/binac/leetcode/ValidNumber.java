package io.binac.leetcode;

/**
 * Validate if a given string is numeric.
 * <p>
 * <p>Some examples:
 * <p>"0" => true
 * <p>" 0.1 " => true
 * <p>"abc" => false
 * <p>"1 a" => false
 * <p>"2e10" => true
 * <p>
 * <p>Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 * <p>
 * <p>Update (2015-02-10):
 * <p>The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
 */
public class ValidNumber {
    public static class Solution1 {
        public boolean isNumber(String s) {
            final int len = s.length();
            int i = 0;
            while (i < len && s.charAt(i) == ' ') ++i;
            if (i < len && (s.charAt(i) == '+' || s.charAt(i) == '-')) ++i;
            int dot = 0, exponent = 0, num = 0;
            while (i < len) {
                final char ch = s.charAt(i);
                if (ch == '.') {
                    if (dot > 0 || exponent > 0) return false;
                    ++dot;
                    ++i;
                } else if (ch == 'e') {
                    if (exponent != 0 || num == 0) return false;
                    ++exponent;
                    num = 0;
                    if (i + 1 < len && (s.charAt(i + 1) == '+' || s.charAt(i + 1) == '-'))
                        i += 2;
                    else
                        ++i;
                } else if ('0' <= ch && ch <= '9') {
                    ++num;
                    ++i;
                } else break;
            }
            while (i < len && s.charAt(i) == ' ') ++i;
            return i == len && num > 0;
        }
    }
}
