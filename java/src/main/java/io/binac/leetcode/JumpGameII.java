package io.binac.leetcode;

/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * <p>
 * <p>Each element in the array represents your maximum jump length at that position.
 * <p>
 * <p>Your goal is to reach the last index in the minimum number of jumps.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: [2,3,1,1,4]
 *     Output: 2
 *     Explanation: The minimum number of jumps to reach the last index is 2.
 *         Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * </blockquote></pre>
 * Note:
 * <p>
 * <p>You can assume that you can always reach the last index.
 */
public class JumpGameII {
    public static class Solution1 {
        public int jump(int[] nums) {
            int step = 0;
            int currentFarthest = 0, farthest = 0;
            for (int i = 0; i <= farthest && i < nums.length; ++i) {
                if (i > currentFarthest) {
                    ++step;
                    currentFarthest = farthest;
                }
                farthest = Math.max(farthest, i + nums[i]);
            }
            if (farthest < nums.length - 1)
                throw new IllegalArgumentException("can't reach the last index");
            return step;
        }
    }
}
