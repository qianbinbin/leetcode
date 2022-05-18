package io.binac.leetcode;

/**
 * <p>Given two strings <code>s</code> and <code>t</code>, return <code>true</code> <em>if</em> <code>t</code> <em>is an anagram of</em> <code>s</code><em>, and</em> <code>false</code> <em>otherwise</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> s = "anagram", t = "nagaram"
 * <strong>Output:</strong> true
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> s = "rat", t = "car"
 * <strong>Output:</strong> false
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= s.length, t.length &lt;= 5 * 10<sup>4</sup></code></li>
 * 	<li><code>s</code> and <code>t</code> consist of lowercase English letters.</li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <p><strong>Follow up:</strong> What if the inputs contain Unicode characters? How would you adapt your solution to such a case?</p>
 */
public class ValidAnagram {
    public static class Solution1 {
        public boolean isAnagram(String s, String t) {
            final int n = s.length();
            if (t.length() != n)
                return false;
            int[] counts = new int[26];
            for (int i = 0; i < n; ++i)
                ++counts[s.charAt(i) - 'a'];
            for (int i = 0; i < n; ++i)
                --counts[t.charAt(i) - 'a'];
            for (int count : counts) {
                if (count != 0)
                    return false;
            }
            return true;
        }
    }
}
