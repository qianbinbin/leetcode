package io.binac.leetcode;

import java.util.HashSet;
import java.util.Set;

/**
 * <p>Write an algorithm to determine if a number <code>n</code> is happy.</p>
 *
 * <p>A <strong>happy number</strong> is a number defined by the following process:</p>
 *
 * <ul>
 * 	<li>Starting with any positive integer, replace the number by the sum of the squares of its digits.</li>
 * 	<li>Repeat the process until the number equals 1 (where it will stay), or it <strong>loops endlessly in a cycle</strong> which does not include 1.</li>
 * 	<li>Those numbers for which this process <strong>ends in 1</strong> are happy.</li>
 * </ul>
 *
 * <p>Return <code>true</code> <em>if</em> <code>n</code> <em>is a happy number, and</em> <code>false</code> <em>if not</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 19
 * <strong>Output:</strong> true
 * <strong>Explanation:</strong>
 * 1<sup>2</sup> + 9<sup>2</sup> = 82
 * 8<sup>2</sup> + 2<sup>2</sup> = 68
 * 6<sup>2</sup> + 8<sup>2</sup> = 100
 * 1<sup>2</sup> + 0<sup>2</sup> + 0<sup>2</sup> = 1
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 2
 * <strong>Output:</strong> false
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
 * </ul>
 */
public class HappyNumber {
    public static class Solution1 {
        public boolean isHappy(int n) {
            int next;
            Set<Integer> set = new HashSet<>();
            while (set.add(n)) {
                next = 0;
                for (; n != 0; n /= 10)
                    next += (n % 10) * (n % 10);
                n = next;
            }
            return n == 1;
        }
    }

    public static class Solution2 {
        private int sumOfSquaresOfDigits(int i) {
            int result = 0;
            for (; i != 0; i /= 10)
                result += (i % 10) * (i % 10);
            return result;
        }

        public boolean isHappy(int n) {
            int slow = n, fast = n;
            do {
                slow = sumOfSquaresOfDigits(slow);
                fast = sumOfSquaresOfDigits(sumOfSquaresOfDigits(fast));
            } while (slow != fast);
            return fast == 1;
        }
    }

    public static class Solution3 {
        public boolean isHappy(int n) {
            int next;
            while (n != 1) {
                if (n == 4)
                    return false;
                next = 0;
                for (; n != 0; n /= 10)
                    next += (n % 10) * (n % 10);
                n = next;
            }
            return true;
        }
    }
}
