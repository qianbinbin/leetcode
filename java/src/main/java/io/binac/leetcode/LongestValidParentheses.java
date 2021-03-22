package io.binac.leetcode;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * <p>Given a string containing just the characters <code>'('</code> and <code>')'</code>, find the length of the longest valid (well-formed) parentheses substring.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "(()"
 * <strong>Output:</strong> 2
 * <strong>Explanation:</strong> The longest valid parentheses substring is "()".
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> s = ")()())"
 * <strong>Output:</strong> 4
 * <strong>Explanation:</strong> The longest valid parentheses substring is "()()".
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> s = ""
 * <strong>Output:</strong> 0
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>0 &lt;= s.length &lt;= 3 * 10<sup>4</sup></code></li>
 * 	<li><code>s[i]</code> is <code>'('</code>, or <code>')'</code>.</li>
 * </ul>
 */
public class LongestValidParentheses {
    public static class Solution1 {
        public int longestValidParentheses(String s) {
            final int len = s.length();
            int result = 0;
            int top = -1;
            int start = -1;
            for (int i = 0; i < len; ++i) {
                switch (s.charAt(i)) {
                    case '(':
                        ++top;
                        break;
                    case ')':
                        if (top >= 0) {
                            if (--top == -1)
                                result = Math.max(result, i - start);
                        } else {
                            start = i;
                        }
                        break;
                }
            }
            top = -1;
            start = len;
            for (int i = len - 1; i >= 0; --i) {
                switch (s.charAt(i)) {
                    case ')':
                        ++top;
                        break;
                    case '(':
                        if (top >= 0) {
                            if (--top == -1)
                                result = Math.max(result, start - i);
                        } else {
                            start = i;
                        }
                        break;
                }
            }
            return result;
        }
    }

    public static class Solution2 {
        public int longestValidParentheses(String s) {
            final int len = s.length();
            int result = 0;
            Deque<Integer> stack = new ArrayDeque<>();
            stack.push(-1);
            for (int i = 0; i < len; ++i) {
                switch (s.charAt(i)) {
                    case '(':
                        stack.push(i);
                        break;
                    case ')':
                        stack.pop();
                        if (stack.isEmpty())
                            stack.push(i);
                        else
                            result = Math.max(result, i - stack.peek());
                        break;
                }
            }
            return result;
        }
    }

    public static class Solution3 {
        public int longestValidParentheses(String s) {
            final int len = s.length();
            if (len < 2)
                return 0;

            int[] dp = new int[len];
            dp[0] = 0;
            dp[1] = s.charAt(0) == '(' && s.charAt(1) == ')' ? 2 : 0;
            int result = dp[1];
            for (int i = 2, j; i < len; ++i) {
                if (s.charAt(i) == ')') {
                    if (s.charAt(i - 1) == '(') {
                        dp[i] = dp[i - 2] + 2;
                    } else if (dp[i - 1] > 0) {
                        j = i - dp[i - 1] - 1;
                        if (j >= 0 && s.charAt(j) == '(')
                            dp[i] = dp[i - 1] + 2 + (j > 0 ? dp[j - 1] : 0);
                    }
                    result = Math.max(result, dp[i]);
                }
            }
            return result;
        }
    }
}
