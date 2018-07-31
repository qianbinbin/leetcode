package io.binac.leetcode;

/**
 * The count-and-say sequence is the sequence of integers with the first five terms as following:
 * <blockquote><pre>
 *     1.     1
 *     2.     11
 *     3.     21
 *     4.     1211
 *     5.     111221
 * </blockquote></pre>
 * <p>1 is read off as "one 1" or 11.
 * <p>11 is read off as "two 1s" or 21.
 * <p>21 is read off as "one 2, then one 1" or 1211.
 * <p>Given an integer n, generate the nth term of the count-and-say sequence.
 * <p>
 * <p>Note: Each term of the sequence of integers will be represented as a string.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: 1
 *     Output: "1"
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: 4
 *     Output: "1211"
 * </blockquote></pre>
 */
public class CountAndSay {
    public static class Solution1 {
        private String countAndSay(String sequence) {
            StringBuilder sb = new StringBuilder();
            final int len = sequence.length();
            int i = 0, count;
            while (i < len) {
                final char ch = sequence.charAt(i);
                count = 1;
                while (i + 1 < len && sequence.charAt(i + 1) == ch) {
                    ++i;
                    ++count;
                }
                sb.append(count).append(ch);
                ++i;
            }
            return sb.toString();
        }

        public String countAndSay(int n) {
            if (n < 1) throw new IllegalArgumentException("n can't be less than 1");

            String preSeq;
            String seq = "1";
            while (n-- > 1) {
                preSeq = seq;
                seq = countAndSay(preSeq);
            }
            return seq;
        }
    }
}
