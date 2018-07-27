package io.binac.leetcode;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
 * <p>
 * <p>Note:
 * <p>
 * <p>The same word in the dictionary may be reused multiple times in the segmentation.
 * <p>You may assume the dictionary does not contain duplicate words.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input:
 *     s = "catsanddog"
 *     wordDict = ["cat", "cats", "and", "sand", "dog"]
 *     Output:
 *     [
 *       "cats and dog",
 *       "cat sand dog"
 *     ]
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input:
 *     s = "pineapplepenapple"
 *     wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 *     Output:
 *     [
 *       "pine apple pen apple",
 *       "pineapple pen apple",
 *       "pine applepen apple"
 *     ]
 *     Explanation: Note that you are allowed to reuse a dictionary word.
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input:
 *     s = "catsandog"
 *     wordDict = ["cats", "dog", "sand", "and", "cat"]
 *     Output:
 *     []
 * </blockquote></pre>
 */
public class WordBreakII {
    public static class Solution1 {
        private void wordBreak(String s, int index, boolean[][] valid, List<String> result, StringBuilder path) {
            if (index == s.length()) {
                result.add(path.substring(0, path.length() - 1));
                return;
            }
            for (int i = index + 1; i <= s.length(); ++i) {
                if (!valid[index][i - 1]) continue;
                path.append(s, index, i).append(' ');
                wordBreak(s, i, valid, result, path);
                path.delete(path.length() - i + index - 1, path.length());
            }
        }

        public List<String> wordBreak(String s, List<String> wordDict) {
            final int len = s.length();
            Set<String> dict = new HashSet<>(wordDict);
            boolean dp[] = new boolean[len + 1];
            dp[0] = true;
            boolean valid[][] = new boolean[len][len];
            for (int i = 1; i <= len; ++i) {
                for (int j = i - 1; j >= 0; --j) {
                    if (dp[j] && dict.contains(s.substring(j, i))) {
                        dp[i] = true;
                        valid[j][i - 1] = true;
                    }
                }
            }
            List<String> result = new ArrayList<>();
            if (!dp[len]) return result;

            wordBreak(s, 0, valid, result, new StringBuilder());
            return result;
        }
    }
}
