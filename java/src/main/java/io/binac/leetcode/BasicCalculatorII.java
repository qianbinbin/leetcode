package io.binac.leetcode;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * <p>Given a string <code>s</code> which represents an expression, <em>evaluate this expression and return its value</em>.&nbsp;</p>
 *
 * <p>The integer division should truncate toward zero.</p>
 *
 * <p>You may assume that the given expression is always valid. All intermediate results will be in the range of <code>[-2<sup>31</sup>, 2<sup>31</sup> - 1]</code>.</p>
 *
 * <p><strong>Note:</strong> You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as <code>eval()</code>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> s = "3+2*2"
 * <strong>Output:</strong> 7
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> s = " 3/2 "
 * <strong>Output:</strong> 1
 * </pre><p><strong>Example 3:</strong></p>
 * <pre><strong>Input:</strong> s = " 3+5 / 2 "
 * <strong>Output:</strong> 5
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
 * 	<li><code>s</code> consists of integers and operators <code>('+', '-', '*', '/')</code> separated by some number of spaces.</li>
 * 	<li><code>s</code> represents <strong>a valid expression</strong>.</li>
 * 	<li>All the integers in the expression are non-negative integers in the range <code>[0, 2<sup>31</sup> - 1]</code>.</li>
 * 	<li>The answer is <strong>guaranteed</strong> to fit in a <strong>32-bit integer</strong>.</li>
 * </ul>
 */
public class BasicCalculatorII {
    public static class Solution1 {
        public int calculate(String s) {
            s = s.replace(" ", "") + '+';
            Deque<Integer> stack = new ArrayDeque<>();
            int num = 0;
            char ch, preOp = '+';
            for (int i = 0, e = s.length(); i < e; ++i) {
                ch = s.charAt(i);
                if ('0' <= ch && ch <= '9') {
                    num = num * 10 + ch - '0';
                    continue;
                }
                switch (preOp) {
                    case '+':
                        stack.push(num);
                        break;
                    case '-':
                        stack.push(-num);
                        break;
                    case '*':
                        stack.push(stack.pop() * num);
                        break;
                    case '/':
                        stack.push(stack.pop() / num);
                        break;
                }
                preOp = ch;
                num = 0;
            }
            int result = 0;
            for (int i : stack)
                result += i;
            return result;
        }
    }
}
