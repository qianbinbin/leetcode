package io.binac.leetcode;

/**
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 * <blockquote><pre>
 *     'A' -> 1
 *     'B' -> 2
 *     ...
 *     'Z' -> 26
 * </blockquote></pre>
 * Given a non-empty string containing only digits, determine the total number of ways to decode it.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: "12"
 *     Output: 2
 *     Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: "226"
 *     Output: 3
 *     Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 * </blockquote></pre>
 */
public class DecodeWays {
    public static class Solution1 {
        public int numDecodings(String s) {
            final int len = s.length();
            if (len == 0)
                throw new IllegalArgumentException("s can't be empty");

            int pre = 1, cur = s.charAt(0) == '0' ? 0 : 1, tmp;
            for (int i = 1; i < len && cur != 0; ++i) {
                tmp = cur;
                if (s.charAt(i - 1) == '1' || (s.charAt(i - 1) == '2' && s.charAt(i) <= '6')) {
                    if (s.charAt(i) == '0')
                        cur = pre;
                    else
                        cur += pre;
                } else if (s.charAt(i) == '0') {
                    cur = 0;
                }
                pre = tmp;
            }
            return cur;
        }
    }
}
