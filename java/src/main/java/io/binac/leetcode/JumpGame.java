package io.binac.leetcode;

/**
 * <p>Given an array of non-negative integers <code>nums</code>, you are initially positioned at the <strong>first index</strong> of the array.</p>
 *
 * <p>Each element in the array represents your maximum jump length at that position.</p>
 *
 * <p>Determine if you are able to reach the last index.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [2,3,1,1,4]
 * <strong>Output:</strong> true
 * <strong>Explanation:</strong> Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [3,2,1,0,4]
 * <strong>Output:</strong> false
 * <strong>Explanation:</strong> You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
 * 	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
 * </ul>
 */
public class JumpGame {
    public static class Solution1 {
        public boolean canJump(int[] nums) {
            int farthest = 0;
            for (int i = 0; i <= farthest && farthest + 1 < nums.length; ++i) {
                farthest = Math.max(farthest, i + nums[i]);
            }
            return farthest >= nums.length - 1;
        }
    }

    public static class Solution2 {
        public boolean canJump(int[] nums) {
            int remainder = 0;
            int i;
            for (i = 0; i < nums.length && remainder >= 0; ++i) {
                remainder = Math.max(remainder, nums[i]) - 1;
            }
            return i == nums.length;
        }
    }
}
