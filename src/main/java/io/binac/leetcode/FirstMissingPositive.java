package io.binac.leetcode;

/**
 * Given an unsorted integer array, find the smallest missing positive integer.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [1,2,0]
 *     Output: 3
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [3,4,-1,1]
 *     Output: 2
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input: [7,8,9,11,12]
 *     Output: 1
 * </blockquote></pre>
 * Note:
 * <p>
 * <p>Your algorithm should run in O(n) time and uses constant extra space.
 */
public class FirstMissingPositive {
    public static class Solution1 {
        private static void swap(int[] x, int a, int b) {
            int t = x[a];
            x[a] = x[b];
            x[b] = t;
        }

        public int firstMissingPositive(int[] nums) {
            if (nums.length == 0)
                return 1;

            for (int i = 0; i < nums.length; ++i) {
                while (1 <= nums[i] && nums[i] <= nums.length && nums[nums[i] - 1] != nums[i])
                    swap(nums, i, nums[i] - 1);
            }
            for (int i = 0; i < nums.length; ++i) {
                if (nums[i] != i + 1)
                    return i + 1;
            }
            return nums.length + 1;
        }
    }
}
