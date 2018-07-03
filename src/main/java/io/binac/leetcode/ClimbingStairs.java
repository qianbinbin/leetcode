package io.binac.leetcode;

/**
 * You are climbing a stair case. It takes n steps to reach to the top.
 * <p>
 * <p>Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * <p>
 * <p>Note: Given n will be a positive integer.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: 2
 *     Output: 2
 *     Explanation: There are two ways to climb to the top.
 *     1. 1 step + 1 step
 *     2. 2 steps
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: 3
 *     Output: 3
 *     Explanation: There are three ways to climb to the top.
 *     1. 1 step + 1 step + 1 step
 *     2. 1 step + 2 steps
 *     3. 2 steps + 1 step
 * </blockquote></pre>
 */
public class ClimbingStairs {
    public static class Solution1 {
        public int climbStairs(int n) {
            if (n < 1)
                throw new IllegalArgumentException("n must be a positive integer");
            if (n < 4) return n;
            int prePre = 2, pre = 3, result = 0;
            for (int i = 4; i <= n; ++i) {
                result = prePre + pre;
                prePre = pre;
                pre = result;
            }
            return result;
        }
    }
}
