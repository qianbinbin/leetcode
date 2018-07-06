package io.binac.leetcode;

/**
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: S = "ADOBECODEBANC", T = "ABC"
 *     Output: "BANC"
 * </blockquote></pre>
 * <p>Note:
 * <p>
 * <p>If there is no such window in S that covers all characters in T, return the empty string "".
 * <p>If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
 */
public class MinimumWindowSubstring {
    public static class Solution1 {
        public String minWindow(String s, String t) {
            final int lenS = s.length(), lenT = t.length();
            if (lenT == 0 || lenT > lenS) return "";

            char sChars[] = s.toCharArray(), tChars[] = t.toCharArray();
            int expected[] = new int[128];
            for (char ch : tChars)
                ++expected[ch];

            int start = 0, end = 0, expectedCount = 0;
            int minWindow = Integer.MAX_VALUE, minStart = 0;
            while (end < lenS) {
                if (expected[sChars[end]] > 0)
                    ++expectedCount;
                --expected[sChars[end]];
                ++end;
                while (expectedCount == lenT) {
                    if (end - start < minWindow) {
                        minWindow = end - start;
                        minStart = start;
                    }
                    ++expected[sChars[start]];
                    if (expected[sChars[start]] > 0)
                        --expectedCount;
                    ++start;
                }
            }
            if (minWindow == Integer.MAX_VALUE) return "";
            return s.substring(minStart, minStart + minWindow);
        }
    }
}
