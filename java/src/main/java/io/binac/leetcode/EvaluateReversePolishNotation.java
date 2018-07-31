package io.binac.leetcode;

import java.util.Stack;

/**
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * <p>
 * <p>Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * <p>
 * <p>Note:
 * <p>
 * <p>Division between two integers should truncate toward zero.
 * <p>The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: ["2", "1", "+", "3", "*"]
 *     Output: 9
 *     Explanation: ((2 + 1) * 3) = 9
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: ["4", "13", "5", "/", "+"]
 *     Output: 6
 *     Explanation: (4 + (13 / 5)) = 6
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 *     Output: 22
 *     Explanation:
 *       ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 *     = ((10 * (6 / (12 * -11))) + 17) + 5
 *     = ((10 * (6 / -132)) + 17) + 5
 *     = ((10 * 0) + 17) + 5
 *     = (0 + 17) + 5
 *     = 17 + 5
 *     = 22
 * </blockquote></pre>
 */
public class EvaluateReversePolishNotation {
    public static class Solution1 {
        public int evalRPN(String[] tokens) {
            Stack<Integer> stack = new Stack<>();
            for (String token : tokens) {
                switch (token) {
                    case "+":
                        stack.push(stack.pop() + stack.pop());
                        break;
                    case "-":
                        stack.push(-(stack.pop() - stack.pop()));
                        break;
                    case "*":
                        stack.push(stack.pop() * stack.pop());
                        break;
                    case "/":
                        int b = stack.pop(), a = stack.pop();
                        stack.push(a / b);
                        break;
                    default:
                        stack.push(Integer.parseInt(token));
                }
            }
            return stack.pop();
        }
    }
}
