package io.binac.leetcode;

/**
 * Given an array nums and a value val, remove all instances of that value in-place and return the new length.
 * <p>
 * <p>Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * <p>
 * <p>The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Given nums = [3,2,2,3], val = 3,
 *
 *     Your function should return length = 2, with the first two elements of nums being 2.
 *
 *     It doesn't matter what you leave beyond the returned length.
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Given nums = [0,1,2,2,3,0,4,2], val = 2,
 *
 *     Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
 *
 *     Note that the order of those five elements can be arbitrary.
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
 *     int len = removeElement(nums, val);
 *
 *     // any modification to nums in your function would be known by the caller.
 *     // using the length returned by your function, it prints the first len elements.
 *     for (int i = 0; i < len; i++) {
 *         print(nums[i]);
 *     }
 * </blockquote></pre>
 */
public class RemoveElement {
    public static class Solution1 {
        public int removeElement(int[] nums, int val) {
            int size = 0;
            for (int i = 0; i < nums.length; ++i) {
                if (nums[i] != val)
                    nums[size++] = nums[i];
            }
            return size;
        }
    }
}
