package io.binac.leetcode;

import java.util.Stack;

/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * <p>
 * <p>An input string is valid if:
 * <p>
 * <p>Open brackets must be closed by the same type of brackets.
 * <p>Open brackets must be closed in the correct order.
 * <p>
 * <p>Note that an empty string is also considered valid.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: "()"
 *     Output: true
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: "()[]{}"
 *     Output: true
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input: "(]"
 *     Output: false
 * </blockquote></pre>
 * Example 4:
 * <blockquote><pre>
 *     Input: "([)]"
 *     Output: false
 * </blockquote></pre>
 * Example 5:
 * <blockquote><pre>
 *     Input: "{[]}"
 *     Output: true
 * </blockquote></pre>
 */
public class ValidParentheses {
    public static class Solution1 {
        public boolean isValid(String s) {
            final int len = s.length();
            Stack<Character> stack = new Stack<>();
            for (int i = 0; i < len; ++i) {
                final char ch = s.charAt(i);
                switch (ch) {
                    case '(':
                        stack.push(ch);
                        break;
                    case ')':
                        if (stack.empty() || stack.pop() != '(')
                            return false;
                        break;
                    case '{':
                        stack.push(ch);
                        break;
                    case '}':
                        if (stack.empty() || stack.pop() != '{')
                            return false;
                        break;
                    case '[':
                        stack.push(ch);
                        break;
                    case ']':
                        if (stack.empty() || stack.pop() != '[')
                            return false;
                        break;
                    default:
                        break;
                }
            }
            return stack.empty();
        }
    }
}
