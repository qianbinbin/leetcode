package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * <p>
 * <p>For example, given n = 3, a solution set is:
 * <blockquote><pre>
 *     [
 *       "((()))",
 *       "(()())",
 *       "(())()",
 *       "()(())",
 *       "()()()"
 *     ]
 * </blockquote></pre>
 */
public class GenerateParentheses {
    public static class Solution1 {
        private void generateParenthesis(final int n, int leftCount, int top, List<String> result, StringBuilder path) {
            if (path.length() == 2 * n) {
                result.add(path.toString());
                return;
            }
            if (leftCount < n) {
                path.append('(');
                generateParenthesis(n, leftCount + 1, top + 1, result, path);
                path.deleteCharAt(path.length() - 1);
            }
            if (top >= 0 && leftCount > 0) {
                path.append(')');
                generateParenthesis(n, leftCount, top - 1, result, path);
                path.deleteCharAt(path.length() - 1);
            }
        }

        public List<String> generateParenthesis(int n) {
            if (n < 0)
                throw new IllegalArgumentException("n can't be negative");
            if (n == 0)
                return Collections.emptyList();
            List<String> result = new ArrayList<>();
            StringBuilder path = new StringBuilder();
            generateParenthesis(n, 0, -1, result, path);
            return result;
        }
    }
}
