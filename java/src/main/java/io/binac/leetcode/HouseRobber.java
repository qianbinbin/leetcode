package io.binac.leetcode;

/**
 * <p>You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and <b>it will automatically contact the police if two adjacent houses were broken into on the same night</b>.</p>
 *
 * <p>Given an integer array <code>nums</code> representing the amount of money of each house, return <em>the maximum amount of money you can rob tonight <b>without alerting the police</b></em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [1,2,3,1]
 * <strong>Output:</strong> 4
 * <strong>Explanation:</strong> Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [2,7,9,3,1]
 * <strong>Output:</strong> 12
 * <strong>Explanation:</strong> Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
 * 	<li><code>0 &lt;= nums[i] &lt;= 400</code></li>
 * </ul>
 */
public class HouseRobber {
    public static class Solution1 {
        public int rob(int[] nums) {
            int dp0 = 0, dp1 = 0, tmp;
            for (int num : nums) {
                tmp = dp0;
                dp0 = Math.max(dp0, dp1);
                dp1 = tmp + num;
            }
            return Math.max(dp0, dp1);
        }
    }
}
