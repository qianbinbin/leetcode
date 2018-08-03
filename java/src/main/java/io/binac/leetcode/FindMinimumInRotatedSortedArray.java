package io.binac.leetcode;

/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * <p>
 * <p>(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * <p>
 * <p>Find the minimum element.
 * <p>
 * <p>You may assume no duplicate exists in the array.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [3,4,5,1,2]
 *     Output: 1
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [4,5,6,7,0,1,2]
 *     Output: 0
 * </blockquote></pre>
 */
public class FindMinimumInRotatedSortedArray {
    public static class Solution1 {
        public int findMin(int[] nums) {
            if (nums.length == 0)
                throw new IllegalArgumentException("nums can't be empty");
            int low = 0, high = nums.length - 1, mid;
            while (low < high && nums[low] > nums[high]) {
                mid = (low + high) >>> 1;
                if (nums[mid] > nums[high])
                    low = mid + 1;
                else
                    high = mid;
            }
            return nums[low];
        }
    }
}
