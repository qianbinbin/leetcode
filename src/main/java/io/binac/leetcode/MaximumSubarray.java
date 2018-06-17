package io.binac.leetcode;

/**
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: [-2,1,-3,4,-1,2,1,-5,4],
 *     Output: 6
 *     Explanation: [4,-1,2,1] has the largest sum = 6.
 * </blockquote></pre>
 * Follow up:
 * <p>
 * <p>If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */
public class MaximumSubarray {
    public static class Solution1 {
        public int maxSubArray(int[] nums) {
            if (nums.length == 0)
                return 0;

            int result = nums[0];
            int dp = nums[0];
            for (int i = 1; i < nums.length; ++i) {
                dp = nums[i] + (dp > 0 ? dp : 0);
                result = Math.max(result, dp);
            }
            return result;
        }
    }
}
