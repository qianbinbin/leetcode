package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>A <strong>valid IP address</strong> consists of exactly four integers separated by single dots. Each integer is between <code>0</code> and <code>255</code> (<strong>inclusive</strong>) and cannot have leading zeros.</p>
 *
 * <ul>
 * 	<li>For example, <code>"0.1.2.201"</code> and <code>"192.168.1.1"</code> are <strong>valid</strong> IP addresses, but <code>"0.011.255.245"</code>, <code>"192.168.1.312"</code> and <code>"192.168@1.1"</code> are <strong>invalid</strong> IP addresses.</li>
 * </ul>
 *
 * <p>Given a string <code>s</code> containing only digits, return <em>all possible valid IP addresses that can be formed by inserting dots into </em><code>s</code>. You are <strong>not</strong> allowed to reorder or remove any digits in <code>s</code>. You may return the valid IP addresses in <strong>any</strong> order.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "25525511135"
 * <strong>Output:</strong> ["255.255.11.135","255.255.111.35"]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "0000"
 * <strong>Output:</strong> ["0.0.0.0"]
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "101023"
 * <strong>Output:</strong> ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>0 &lt;= s.length &lt;= 20</code></li>
 * 	<li><code>s</code> consists of digits only.</li>
 * </ul>
 */
public class RestoreIPAddresses {
    public static class Solution1 {
        private void restoreIpAddresses(String s, int i, List<String> result, List<String> path) {
            if (path.size() == 4 || i == s.length()) {
                if (path.size() == 4 && i == s.length())
                    result.add(String.join(".", path));
                return;
            }
            path.add(s.substring(i, i + 1));
            restoreIpAddresses(s, i + 1, result, path);
            path.remove(path.size() - 1);
            if (s.charAt(i) == '0')
                return;
            if (i + 1 < s.length()) {
                path.add(s.substring(i, i + 2));
                restoreIpAddresses(s, i + 2, result, path);
                path.remove(path.size() - 1);
            }
            if (i + 2 < s.length() && Integer.parseInt(s.substring(i, i + 3)) <= 255) {
                path.add(s.substring(i, i + 3));
                restoreIpAddresses(s, i + 3, result, path);
                path.remove(path.size() - 1);
            }
        }

        public List<String> restoreIpAddresses(String s) {
            List<String> result = new ArrayList<>();
            restoreIpAddresses(s, 0, result, new ArrayList<>());
            return result;
        }
    }

    public static class Solution2 {
        private boolean isValidIpSegment(String s) {
            if (s.length() > 3)
                return false;
            if (s.charAt(0) == '0')
                return s.length() == 1;
            return Integer.parseInt(s) <= 255;
        }

        public List<String> restoreIpAddresses(String s) {
            List<String> result = new ArrayList<>();
            final int len = s.length();
            int i, ie, j, je, k, ke;
            for (i = 1, ie = Math.min(4, len); i < ie; ++i) {
                for (j = i + 1, je = Math.min(i + 4, len); j < je; ++j) {
                    for (k = j + 1, ke = Math.min(j + 4, len); k < ke; ++k) {
                        String s1 = s.substring(0, i), s2 = s.substring(i, j), s3 = s.substring(j, k), s4 = s.substring(k, len);
                        if (isValidIpSegment(s1) && isValidIpSegment(s2) && isValidIpSegment(s3) && isValidIpSegment(s4))
                            result.add(String.join(".", s1, s2, s3, s4));
                    }
                }
            }
            return result;
        }
    }
}
