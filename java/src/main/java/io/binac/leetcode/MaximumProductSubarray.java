package io.binac.leetcode;

/**
 * <p>Given an integer array <code>nums</code>, find a contiguous non-empty subarray within the array that has the largest product, and return <em>the product</em>.</p>
 *
 * <p>The test cases are generated so that the answer will fit in a <strong>32-bit</strong> integer.</p>
 *
 * <p>A <strong>subarray</strong> is a contiguous subsequence of the array.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [2,3,-2,4]
 * <strong>Output:</strong> 6
 * <strong>Explanation:</strong> [2,3] has the largest product 6.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [-2,0,-1]
 * <strong>Output:</strong> 0
 * <strong>Explanation:</strong> The result cannot be 2, because [-2,-1] is not a subarray.
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
 * 	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
 * 	<li>The product of any prefix or suffix of <code>nums</code> is <strong>guaranteed</strong> to fit in a <strong>32-bit</strong> integer.</li>
 * </ul>
 */
public class MaximumProductSubarray {
    public static class Solution1 {
        public int maxProduct(int[] nums) {
            int result = nums[0];
            int preMax = result, preMin = result, max, min;
            for (int i = 1; i < nums.length; ++i) {
                if (nums[i] >= 0) {
                    max = Math.max(nums[i], nums[i] * preMax);
                    min = Math.min(nums[i], nums[i] * preMin);
                } else {
                    max = Math.max(nums[i], nums[i] * preMin);
                    min = Math.min(nums[i], nums[i] * preMax);
                }
                result = Math.max(result, max);
                preMax = max;
                preMin = min;
            }
            return result;
        }
    }
}
