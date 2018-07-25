package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * <p>
 * <p>Return all possible palindrome partitioning of s.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: "aab"
 *     Output:
 *     [
 *       ["aa","b"],
 *       ["a","a","b"]
 *     ]
 * </blockquote></pre>
 */
public class PalindromePartitioning {
    public static class Solution1 {
        private void partition(char[] chars, int index, boolean[][] palindrome, List<List<String>> result, List<String> path) {
            if (index == chars.length) {
                result.add(new ArrayList<>(path));
                return;
            }
            for (int j = index; j < chars.length; ++j) {
                if (palindrome[index][j]) {
                    path.add(new String(chars, index, j - index + 1));
                    partition(chars, j + 1, palindrome, result, path);
                    path.remove(path.size() - 1);
                }
            }
        }

        public List<List<String>> partition(String s) {
            final char chars[] = s.toCharArray();
            final int len = chars.length;
            boolean dp[][] = new boolean[len][len];
            for (int i = len - 1; i >= 0; --i) {
                dp[i][i] = true;
                if (i + 1 < len && chars[i] == chars[i + 1]) dp[i][i + 1] = true;
                for (int j = i + 2; j < len; ++j) {
                    if (dp[i + 1][j - 1] && chars[i] == chars[j])
                        dp[i][j] = true;
                }
            }

            List<List<String>> result = new ArrayList<>();
            partition(chars, 0, dp, result, new ArrayList<>(len));
            return result;
        }
    }
}
