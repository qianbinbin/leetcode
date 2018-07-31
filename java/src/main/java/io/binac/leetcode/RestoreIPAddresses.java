package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: "25525511135"
 *     Output: ["255.255.11.135", "255.255.111.35"]
 * </blockquote></pre>
 */
public class RestoreIPAddresses {
    public static class Solution1 {
        private boolean isValidByte(char[] chars, int offset, int count) {
            if (offset < 0 || count < 1 || count > 3 || offset + count > chars.length)
                return false;
            if (chars[offset] == '0')
                return count == 1;
            int val = 0;
            for (int i = 0; i < count; ++i)
                val = val * 10 + chars[offset + i] - '0';
            return val < 256;
        }

        private void restoreIpAddresses(char[] chars, int offset, List<String> result, char[] path, int len, int level) {
            if (level == 4 || offset == chars.length) {
                if (level == 4 && offset == chars.length)
                    result.add(new String(path, 0, len - 1));
                return;
            }
            for (int count = 1; count <= 3; ++count) {
                if (isValidByte(chars, offset, count)) {
                    System.arraycopy(chars, offset, path, len, count);
                    len += count;
                    path[len++] = '.';
                    restoreIpAddresses(chars, offset + count, result, path, len, level + 1);
                    len -= count + 1;
                }
            }
        }

        public List<String> restoreIpAddresses(String s) {
            if (s.length() < 4 || s.length() > 12)
                return Collections.emptyList();
            List<String> result = new ArrayList<>();
            char path[] = new char[16];
            restoreIpAddresses(s.toCharArray(), 0, result, path, 0, 0);
            return result;
        }
    }

    public static class Solution2 {
        private boolean isValidByte(char[] chars, int offset, int count) {
            if (offset < 0 || count < 1 || count > 3 || offset + count > chars.length)
                return false;
            if (chars[offset] == '0')
                return count == 1;
            int val = 0;
            for (int i = 0; i < count; ++i)
                val = val * 10 + chars[offset + i] - '0';
            return val < 256;
        }

        public List<String> restoreIpAddresses(String s) {
            if (s.length() < 4 || s.length() > 12)
                return Collections.emptyList();
            char chars[] = s.toCharArray();
            List<String> result = new ArrayList<>();
            for (int a = 1; a <= 3; ++a) {
                for (int b = 1; b <= 3; ++b) {
                    for (int c = 1; c <= 3; ++c) {
                        if (isValidByte(chars, 0, a)
                                && isValidByte(chars, a, b)
                                && isValidByte(chars, a + b, c)
                                && isValidByte(chars, a + b + c, chars.length - a - b - c)) {
                            result.add(String.join(".",
                                    new String(chars, 0, a), new String(chars, a, b),
                                    new String(chars, a + b, c), new String(chars, a + b + c, chars.length - a - b - c)));
                        }
                    }
                }
            }
            return result;
        }
    }
}
