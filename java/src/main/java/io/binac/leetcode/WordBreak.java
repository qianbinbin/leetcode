package io.binac.leetcode;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * <p>Given a string <code>s</code> and a dictionary of strings <code>wordDict</code>, return <code>true</code> if <code>s</code> can be segmented into a space-separated sequence of one or more dictionary words.</p>
 *
 * <p><strong>Note</strong> that the same word in the dictionary may be reused multiple times in the segmentation.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "leetcode", wordDict = ["leet","code"]
 * <strong>Output:</strong> true
 * <strong>Explanation:</strong> Return true because "leetcode" can be segmented as "leet code".
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "applepenapple", wordDict = ["apple","pen"]
 * <strong>Output:</strong> true
 * <strong>Explanation:</strong> Return true because "applepenapple" can be segmented as "apple pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * <strong>Output:</strong> false
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= s.length &lt;= 300</code></li>
 * 	<li><code>1 &lt;= wordDict.length &lt;= 1000</code></li>
 * 	<li><code>1 &lt;= wordDict[i].length &lt;= 20</code></li>
 * 	<li><code>s</code> and <code>wordDict[i]</code> consist of only lowercase English letters.</li>
 * 	<li>All the strings of <code>wordDict</code> are <strong>unique</strong>.</li>
 * </ul>
 */
public class WordBreak {
    public static class Solution1 {
        public boolean wordBreak(String s, List<String> wordDict) {
            final int len = s.length();
            Set<String> dict = new HashSet<>(wordDict);
            boolean[] dp = new boolean[len + 1];
            dp[0] = true;
            for (int i, j = 1; j <= len; ++j) {
                for (i = j - 1; i >= 0; --i) {
                    if (dp[i] && dict.contains(s.substring(i, j))) {
                        dp[j] = true;
                        break;
                    }
                }
            }
            return dp[len];
        }
    }
}
