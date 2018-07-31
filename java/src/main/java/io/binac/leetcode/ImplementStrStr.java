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

    public static class Solution2 {
        private int[] getNext(char pattern[]) {
            final int len = pattern.length;
            if (len == 0)
                throw new IllegalArgumentException("pattern can't be empty");

            int next[] = new int[len];
            next[0] = -1;
            if (len == 1)
                return next;

            next[1] = 0;
            int i = 2, j = 0;
            while (i < len) {
                if (j == -1 || pattern[i - 1] == pattern[j]) {
                    if (pattern[i] == pattern[j + 1])
                        next[i++] = next[++j];
                    else
                        next[i++] = ++j;
                } else {
                    j = next[j];
                }
            }
            return next;
        }

        public int strStr(String haystack, String needle) {
            final int len1 = haystack.length(), len2 = needle.length();
            if (len2 == 0)
                return 0;
            if (len1 == 0 || len1 < len2)
                return -1;

            char pattern[] = needle.toCharArray();
            int next[] = getNext(pattern);

            final int end = len1 - len2;
            int i = 0, j = 0;
            while (i < len1 && j < len2) {
                if (j == -1 || haystack.charAt(i) == pattern[j]) {
                    ++i;
                    ++j;
                } else {
                    j = next[j];
                }
            }
            if (j == len2)
                return i - j;
            return -1;
        }
    }
}
