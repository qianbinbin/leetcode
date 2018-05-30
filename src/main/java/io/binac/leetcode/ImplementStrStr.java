package io.binac.leetcode;

/**
 * Implement strStr().
 * <p>
 * <p>Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: haystack = "hello", needle = "ll"
 *     Output: 2
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: haystack = "aaaaa", needle = "bba"
 *     Output: -1
 * </blockquote></pre>
 * <p>Clarification:
 * <p>
 * <p>What should we return when needle is an empty string? This is a great question to ask during an interview.
 * <p>
 * <p>For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
 */
public class ImplementStrStr {
    public static class Solution1 {
        public int strStr(String haystack, String needle) {
            final int len1 = haystack.length(), len2 = needle.length();
            if (len2 == 0)
                return 0;
            if (len1 == 0 || len1 < len2)
                return -1;

            final char first = needle.charAt(0);
            final int end = len1 - len2;
            int i, j;
            for (i = 0; i <= end; ++i) {
                while (i <= end && haystack.charAt(i) != first) ++i;
                if (i > end)
                    return -1;
                j = 1;
                while (j < len2 && haystack.charAt(i + j) == needle.charAt(j)) ++j;
                if (j == len2)
                    return i;
            }
            return -1;
        }
    }
}
