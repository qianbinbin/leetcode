package io.binac.leetcode;

/**
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 * <p>
 * <p>Note:
 * <p>
 * <p>Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [2,2,1]
 *     Output: 1
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [4,1,2,1,2]
 *     Output: 4
 * </blockquote></pre>
 */
public class SingleNumber {
    public static class Solution1 {
        public int singleNumber(int[] nums) {
            int result = 0;
            for (int num : nums)
                result ^= num;
            return result;
        }
    }
}
