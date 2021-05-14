package io.binac.leetcode;

/**
 * <p>Given an array of non-negative integers <code>nums</code>, you are initially positioned at the first index of the array.</p>
 *
 * <p>Each element in the array represents your maximum jump length at that position.</p>
 *
 * <p>Your goal is to reach the last index in the minimum number of jumps.</p>
 *
 * <p>You can assume that you can always reach the last index.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [2,3,1,1,4]
 * <strong>Output:</strong> 2
 * <strong>Explanation:</strong> The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [2,3,0,1,4]
 * <strong>Output:</strong> 2
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
public class JumpGameII {
    public static class Solution1 {
        public int jump(int[] nums) {
            int step = 0;
            int lastFarthest = 0, farthest = 0;
            for (int i = 0; i <= farthest && i < nums.length; ++i) {
                if (i > lastFarthest) {
                    ++step;
                    lastFarthest = farthest;
                }
                farthest = Math.max(farthest, i + nums[i]);
            }
            return step;
        }
    }
}
