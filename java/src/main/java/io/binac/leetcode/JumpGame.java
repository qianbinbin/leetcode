package io.binac.leetcode;

/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * <p>
 * <p>Each element in the array represents your maximum jump length at that position.
 * <p>
 * <p>Determine if you are able to reach the last index.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [2,3,1,1,4]
 *     Output: true
 *     Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [3,2,1,0,4]
 *     Output: false
 *     Explanation: You will always arrive at index 3 no matter what. Its maximum
 *                  jump length is 0, which makes it impossible to reach the last index.
 * </blockquote></pre>
 */
public class JumpGame {
    public static class Solution1 {
        public boolean canJump(int[] nums) {
            if (nums.length == 0)
                throw new IllegalArgumentException("nums can't be empty");
            int farthest = 0;
            for (int i = 0; i <= farthest && i < nums.length; ++i) {
                farthest = Math.max(farthest, i + nums[i]);
            }
            return farthest >= nums.length - 1;
        }
    }

    public static class Solution2 {
        public boolean canJump(int[] nums) {
            if (nums.length == 0)
                throw new IllegalArgumentException("nums can't be empty");
            int remainder = 0;
            for (int i = 1; i < nums.length; ++i) {
                remainder = Math.max(remainder, nums[i - 1]) - 1;
                if (remainder < 0)
                    return false;
            }
            return true;
        }
    }
}
