package io.binac.leetcode;

/**
 * Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
 * <p>
 * <p>Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Given nums = [1,1,1,2,2,3],
 *
 *     Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
 *
 *     It doesn't matter what you leave beyond the returned length.
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Given nums = [0,0,1,1,1,1,2,3,3],
 *
 *     Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
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
public class RemoveDuplicatesFromSortedArrayII {
    public static class Solution1 {
        public int removeDuplicates(int[] nums) {
            if (nums.length < 3) return nums.length;
            int size = 2;
            for (int i = 2; i < nums.length; ++i) {
                if (nums[i] != nums[size - 2])
                    nums[size++] = nums[i];
            }
            return size;
        }
    }
}
