package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * <p>Given <code>n</code> pairs of parentheses, write a function to <em>generate all combinations of well-formed parentheses</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> n = 3
 * <strong>Output:</strong> ["((()))","(()())","(())()","()(())","()()()"]
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> n = 1
 * <strong>Output:</strong> ["()"]
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= n &lt;= 8</code></li>
 * </ul>
 */
public class GenerateParentheses {
    public static class Solution1 {
        private void generateParenthesis(int n, int leftCount, int top, List<String> result, StringBuilder path) {
            if (path.length() == 2 * n) {
                result.add(path.toString());
                return;
            }
            if (leftCount < n) {
                path.append('(');
                generateParenthesis(n, leftCount + 1, top + 1, result, path);
                path.deleteCharAt(path.length() - 1);
            }
            if (top >= 0) {
                path.append(')');
                generateParenthesis(n, leftCount, top - 1, result, path);
                path.deleteCharAt(path.length() - 1);
            }
        }

        public List<String> generateParenthesis(int n) {
            List<String> result = new ArrayList<>();
            generateParenthesis(n, 0, -1, result, new StringBuilder());
            return result;
        }
    }
}
