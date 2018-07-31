package io.binac.leetcode;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 * <p>
 * <p>Note:
 * <p>
 * <p>The same word in the dictionary may be reused multiple times in the segmentation.
 * <p>You may assume the dictionary does not contain duplicate words.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: s = "leetcode", wordDict = ["leet", "code"]
 *     Output: true
 *     Explanation: Return true because "leetcode" can be segmented as "leet code".
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: s = "applepenapple", wordDict = ["apple", "pen"]
 *     Output: true
 *     Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
 *                  Note that you are allowed to reuse a dictionary word.
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 *     Output: false
 * </blockquote></pre>
 */
public class WordBreak {
    public static class Solution1 {
        public boolean wordBreak(String s, List<String> wordDict) {
            final int len = s.length();
            Set<String> dict = new HashSet<>(wordDict);
            boolean dp[] = new boolean[len + 1];
            dp[0] = true;
            for (int i = 1; i <= len; ++i) {
                for (int j = i - 1; j >= 0; --j) {
                    if (dp[j] && dict.contains(s.substring(j, i))) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            return dp[len];
        }
    }
}
