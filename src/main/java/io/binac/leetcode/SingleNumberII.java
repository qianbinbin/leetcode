package io.binac.leetcode;

/**
 * Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
 * <p>
 * <p>Note:
 * <p>
 * <p>Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [2,2,3,2]
 *     Output: 3
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [0,1,0,1,0,1,99]
 *     Output: 99
 * </blockquote></pre>
 */
public class SingleNumberII {
    public static class Solution1 {
        public int singleNumber(int[] nums) {
            int one = 0, two = 0;
            for (int num : nums) {
                one = (one ^ num) & ~two;
                two = (two ^ num) & ~one;
            }
            return one;
        }
    }
}
