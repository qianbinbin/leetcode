package io.binac.leetcode;

/**
 * Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [2,3,-2,4]
 *     Output: 6
 *     Explanation: [2,3] has the largest product 6.
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [-2,0,-1]
 *     Output: 0
 *     Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * </blockquote></pre>
 */
public class MaximumProductSubarray {
    public static class Solution1 {
        public int maxProduct(int[] nums) {
            if (nums.length == 0)
                throw new IllegalArgumentException("nums must contain at least one number");
            int result = nums[0];
            int dp_max = result, dp_min = result, tmp;
            for (int i = 1; i < nums.length; ++i) {
                if (nums[i] < 0) {
                    tmp = dp_max;
                    dp_max = dp_min;
                    dp_min = tmp;
                }
                dp_max = Math.max(nums[i], nums[i] * dp_max);
                dp_min = Math.min(nums[i], nums[i] * dp_min);
                result = Math.max(result, dp_max);
            }
            return result;
        }
    }
}
