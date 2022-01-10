package io.binac.leetcode;

/**
 * <p>Implement <a href="http://www.cplusplus.com/reference/cstring/strstr/" target="_blank">strStr()</a>.</p>
 *
 * <p>Return the index of the first occurrence of needle in haystack, or <code>-1</code> if <code>needle</code> is not part of <code>haystack</code>.</p>
 *
 * <p><strong>Clarification:</strong></p>
 *
 * <p>What should we return when <code>needle</code> is an empty string? This is a great question to ask during an interview.</p>
 *
 * <p>For the purpose of this problem, we will return 0 when <code>needle</code> is an empty string. This is consistent to C's&nbsp;<a href="http://www.cplusplus.com/reference/cstring/strstr/" target="_blank">strstr()</a> and Java's&nbsp;<a href="https://docs.oracle.com/javase/7/docs/api/java/lang/String.html#indexOf(java.lang.String)" target="_blank">indexOf()</a>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> haystack = "hello", needle = "ll"
 * <strong>Output:</strong> 2
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> haystack = "aaaaa", needle = "bba"
 * <strong>Output:</strong> -1
 * </pre><p><strong>Example 3:</strong></p>
 * <pre><strong>Input:</strong> haystack = "", needle = ""
 * <strong>Output:</strong> 0
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>0 &lt;= haystack.length, needle.length &lt;= 5 * 10<sup>4</sup></code></li>
 * 	<li><code>haystack</code> and&nbsp;<code>needle</code> consist of only lower-case English characters.</li>
 * </ul>
 */
public class ImplementStrStr {
    public static class Solution1 {
        public int strStr(String haystack, String needle) {
            final int len1 = haystack.length(), len2 = needle.length();
            if (len2 == 0)
                return 0;
            if (len1 == 0 || len1 < len2)
                return -1;

            int i = 0, j = 0;
            while (i < len1 && j < len2) {
                if (haystack.charAt(i) != needle.charAt(j)) {
                    i = i - j + 1;
                    j = 0;
                } else {
                    ++i;
                    ++j;
                }
            }
            return j == len2 ? i - j : -1;
        }
    }

    public static class Solution2 {
        private int[] getNext(String str) {
            final int size = str.length();
            int[] next = new int[size];
            next[0] = -1;
            for (int i = 1, j = -1; i < size; ++i) {
                while (j != -1 && str.charAt(i - 1) != str.charAt(j))
                    j = next[j];
                ++j;
                next[i] = str.charAt(i) != str.charAt(j) ? j : next[j];
            }
            return next;
        }

        public int strStr(String haystack, String needle) {
            final int len1 = haystack.length(), len2 = needle.length();
            if (len2 == 0)
                return 0;
            if (len1 < len2)
                return -1;

            int[] next = getNext(needle);
            int i = 0, j = 0;
            while (i < len1 && j < len2) {
                while (j != -1 && haystack.charAt(i) != needle.charAt(j))
                    j = next[j];
                ++i;
                ++j;
            }
            return j == len2 ? i - j : -1;
        }
    }
}
