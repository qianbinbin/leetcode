package io.binac.leetcode;

/**
 * Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
 * <p>
 * <p>Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Given nums = [1,1,2],
 *
 *     Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 *
 *     It doesn't matter what you leave beyond the returned length.
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Given nums = [0,0,1,1,1,2,2,3,3,4],
 *
 *     Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
 *
 *     It doesn't matter what values are set beyond the returned length.
 * </blockquote></pre>
 * Clarification:
 * <p>
 * <p>Confused why the returned value is an integer but your answer is an array?
 * <p>
 * <p>Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
 * <p>
 * <p>Internally you can think of this:
 * <blockquote><pre>
 *     // nums is passed in by reference. (i.e., without making a copy)
 *     int len = removeDuplicates(nums);
 *
 *     // any modification to nums in your function would be known by the caller.
 *     // using the length returned by your function, it prints the first len elements.
 *     for (int i = 0; i < len; i++) {
 *         print(nums[i]);
 *     }
 * </blockquote></pre>
 */
public class RemoveDuplicatesFromSortedArray {
    public static class Solution1 {
        public int removeDuplicates(int[] nums) {
            if (nums.length < 2)
                return nums.length;

            int index = 0;
            for (int i = 1; i < nums.length; ++i) {
                if (nums[index] != nums[i])
                    nums[++index] = nums[i];
            }
            return index + 1;
        }
    }
}
