package io.binac.leetcode;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * <p>Given a string <code>s</code> and a dictionary of strings <code>wordDict</code>, add spaces in <code>s</code> to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in <strong>any order</strong>.</p>
 *
 * <p><strong>Note</strong> that the same word in the dictionary may be reused multiple times in the segmentation.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
 * <strong>Output:</strong> ["cats and dog","cat sand dog"]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
 * <strong>Output:</strong> ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
 * <strong>Explanation:</strong> Note that you are allowed to reuse a dictionary word.
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * <strong>Output:</strong> []
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= s.length &lt;= 20</code></li>
 * 	<li><code>1 &lt;= wordDict.length &lt;= 1000</code></li>
 * 	<li><code>1 &lt;= wordDict[i].length &lt;= 10</code></li>
 * 	<li><code>s</code> and <code>wordDict[i]</code> consist of only lowercase English letters.</li>
 * 	<li>All the strings of <code>wordDict</code> are <strong>unique</strong>.</li>
 * </ul>
 */
public class WordBreakII {
    public static class Solution1 {
        private void wordBreak(String s, int i, boolean[][] valid, List<String> result, List<String> path) {
            final int len = s.length();
            if (i == len) {
                result.add(String.join(" ", path));
                return;
            }
            for (int j = i + 1; j <= len; ++j) {
                if (!valid[i][j]) continue;
                path.add(s.substring(i, j));
                wordBreak(s, j, valid, result, path);
                path.remove(path.size() - 1);
            }
        }

        public List<String> wordBreak(String s, List<String> wordDict) {
            final int len = s.length();
            Set<String> dict = new HashSet<>(wordDict);
            boolean[] dp = new boolean[len + 1];
            dp[0] = true;
            boolean[][] valid = new boolean[len][len + 1];
            for (int i, j = 1; j <= len; ++j) {
                for (i = j - 1; i >= 0; --i) {
                    if (dp[i] && dict.contains(s.substring(i, j))) {
                        dp[j] = true;
                        valid[i][j] = true;
                    }
                }
            }
            List<String> result = new ArrayList<>();
            if (!dp[len]) return result;

            wordBreak(s, 0, valid, result, new ArrayList<>());
            return result;
        }
    }
}
