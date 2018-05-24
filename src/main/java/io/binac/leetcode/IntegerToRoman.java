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
 * <p>Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: 3
 *     Output: "III"
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: 4
 *     Output: "IV"
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input: 9
 *     Output: "IX"
 * </blockquote></pre>
 * Example 4:
 * <blockquote><pre>
 *     Input: 58
 *     Output: "LVIII"
 *     Explanation: C = 100, L = 50, XXX = 30 and III = 3.
 * </blockquote></pre>
 * Example 5:
 * <blockquote><pre>
 *     Input: 1994
 *     Output: "MCMXCIV"
 *     Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * </blockquote></pre>
 */
public class IntegerToRoman {
    public static class Solution1 {
        private static final int VALUES[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        private static final String SYMBOLS[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        public String intToRoman(int num) {
            if (num < 1 || num > 3999)
                throw new IllegalArgumentException("num must be within the range from 1 to 3999");

            StringBuilder sb = new StringBuilder();
            int index = 0;
            while (num != 0) {
                while (num < VALUES[index]) ++index;
                sb.append(SYMBOLS[index]);
                num -= VALUES[index];
            }
            return sb.toString();
        }
    }
}
