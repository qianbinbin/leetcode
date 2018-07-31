package io.binac.leetcode;

/**
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * <blockquote><pre>
 *     Symbol       Value
 *     I             1
 *     V             5
 *     X             10
 *     L             50
 *     C             100
 *     D             500
 *     M             1000
 * </blockquote></pre>
 * <p>For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
 * <p>
 * <p>Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 * <p>
 * <p>I can be placed before V (5) and X (10) to make 4 and 9.
 * <p>X can be placed before L (50) and C (100) to make 40 and 90.
 * <p>C can be placed before D (500) and M (1000) to make 400 and 900.
 * <p>
 * <p>Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
 * <p>
 * Example 1:
 * <blockquote><pre>
 *     Input: "III"
 *     Output: 3
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: "IV"
 *     Output: 4
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input: "IX"
 *     Output: 9
 * </blockquote></pre>
 * Example 4:
 * <blockquote><pre>
 *     Input: "LVIII"
 *     Output: 58
 *     Explanation: C = 100, L = 50, XXX = 30 and III = 3.
 * </blockquote></pre>
 * Example 5:
 * <blockquote><pre>
 *     Input: "MCMXCIV"
 *     Output: 1994
 *     Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * </blockquote></pre>
 */
public class RomanToInteger {
    public static class Solution1 {
        private static final int MAP[] = new int[26];

        static {
            MAP['I' - 'A'] = 1;
            MAP['V' - 'A'] = 5;
            MAP['X' - 'A'] = 10;
            MAP['L' - 'A'] = 50;
            MAP['C' - 'A'] = 100;
            MAP['D' - 'A'] = 500;
            MAP['M' - 'A'] = 1000;
        }

        private static int value(char roman) {
            return MAP[roman - 'A'];
        }

        public int romanToInt(String s) {
            final int len = s.length();
            int value = 0;
            for (int i = 0; i < len; ) {
                if (i < len - 1 && value(s.charAt(i)) < value(s.charAt(i + 1))) {
                    value += value(s.charAt(i + 1)) - value(s.charAt(i));
                    i += 2;
                } else {
                    value += value(s.charAt(i));
                    ++i;
                }
            }
            return value;
        }
    }
}
