package io.binac.leetcode;

import javafx.util.Pair;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * <p>We can scramble a string s to get a string t using the following algorithm:</p>
 *
 * <ol>
 * 	<li>If the length of the string is 1, stop.</li>
 * 	<li>If the length of the string is &gt; 1, do the following:
 * 	<ul>
 * 		<li>Split the string into two non-empty substrings at a random index, i.e., if the string is <code>s</code>, divide it to <code>x</code> and <code>y</code> where <code>s = x + y</code>.</li>
 * 		<li><strong>Randomly</strong>&nbsp;decide to swap the two substrings or to keep them in the same order. i.e., after this step, <code>s</code> may become <code>s = x + y</code> or <code>s = y + x</code>.</li>
 * 		<li>Apply step 1 recursively on each of the two substrings <code>x</code> and <code>y</code>.</li>
 * 	</ul>
 * 	</li>
 * </ol>
 *
 * <p>Given two strings <code>s1</code> and <code>s2</code> of <strong>the same length</strong>, return <code>true</code> if <code>s2</code> is a scrambled string of <code>s1</code>, otherwise, return <code>false</code>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> s1 = "great", s2 = "rgeat"
 * <strong>Output:</strong> true
 * <strong>Explanation:</strong> One possible scenario applied on s1 is:
 * "great" --&gt; "gr/eat" // divide at random index.
 * "gr/eat" --&gt; "gr/eat" // random decision is not to swap the two substrings and keep them in order.
 * "gr/eat" --&gt; "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at ranom index each of them.
 * "g/r / e/at" --&gt; "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
 * "r/g / e/at" --&gt; "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
 * "r/g / e/ a/t" --&gt; "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
 * The algorithm stops now and the result string is "rgeat" which is s2.
 * As there is one possible scenario that led s1 to be scrambled to s2, we return true.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> s1 = "abcde", s2 = "caebd"
 * <strong>Output:</strong> false
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> s1 = "a", s2 = "a"
 * <strong>Output:</strong> true
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>s1.length == s2.length</code></li>
 * 	<li><code>1 &lt;= s1.length &lt;= 30</code></li>
 * 	<li><code>s1</code> and <code>s2</code> consist of lower-case English letters.</li>
 * </ul>
 */
public class ScrambleString {
    public static class Solution1 {
        private final int[] EQ_COUNT = new int[26];

        private boolean isScramble(String s1, String s2, Map<String, Boolean> map) {
            String k = s1 + s2;
            if (map.containsKey(k))
                return map.get(k);
            final int len = s1.length();
            if (len == 1) {
                boolean b = s1.equals(s2);
                map.put(k, b);
                return b;
            }
            int[] count = new int[26];
            for (int i = 0; i < len; ++i) {
                ++count[s1.charAt(i) - 'a'];
                --count[s2.charAt(i) - 'a'];
            }
            if (!Arrays.equals(count, EQ_COUNT)) {
                map.put(k, false);
                return false;
            }
            for (int l = 1; l < len; ++l) {
                if ((isScramble(s1.substring(0, l), s2.substring(0, l), map) && isScramble(s1.substring(l, len), s2.substring(l, len), map))
                        || (isScramble(s1.substring(0, l), s2.substring(len - l, len), map) && isScramble(s1.substring(l, len), s2.substring(0, len - l), map))) {
                    map.put(k, true);
                    return true;
                }
            }
            map.put(k, false);
            return false;
        }

        public boolean isScramble(String s1, String s2) {
            return isScramble(s1, s2, new HashMap<>());
        }
    }

    public static class Solution2 {
        public boolean isScramble(String s1, String s2) {
            final int len = s1.length();

            boolean[][][] dp = new boolean[len + 1][len][len];
            for (int i = 0, j; i < len; ++i) {
                for (j = 0; j < len; ++j) {
                    if (s1.charAt(i) == s2.charAt(j))
                        dp[1][i][j] = true;
                }
            }
            for (int l = 2, i, j, k; l <= len; ++l) {
                for (i = 0; i + l <= len; ++i) {
                    for (j = 0; j + l <= len; ++j) {
                        for (k = 1; k < l; ++k) {
                            if ((dp[k][i][j] && dp[l - k][i + k][j + k])
                                    || (dp[k][i][j + l - k] && dp[l - k][i + k][j])) {
                                dp[l][i][j] = true;
                                break;
                            }
                        }
                    }
                }
            }
            return dp[len][0][0];
        }
    }
}
