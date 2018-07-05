package io.binac.leetcode;

/**
 * Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 * <p>
 * <p>Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 * <p>
 * <p>Note: You are not suppose to use the library's sort function for this problem.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: [2,0,2,1,1,0]
 *     Output: [0,0,1,1,2,2]
 * </blockquote></pre>
 * <p>Follow up:
 * <p>
 * <p>A rather straight forward solution is a two-pass algorithm using counting sort.
 * <p>First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 * <p>Could you come up with a one-pass algorithm using only constant space?
 */
public class SortColors {
    public static class Solution1 {
        public void sortColors(int[] nums) {
            int count0 = 0, count1 = 0;
            for (int num : nums) {
                if (num == 0)
                    ++count0;
                else if (num == 1)
                    ++count1;
            }
            int i = 0;
            for (; i < count0; ++i)
                nums[i] = 0;
            count1 += count0;
            for (; i < count1; ++i)
                nums[i] = 1;
            for (; i < nums.length; ++i)
                nums[i] = 2;
        }
    }
}
