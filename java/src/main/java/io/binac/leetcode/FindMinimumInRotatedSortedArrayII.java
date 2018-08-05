package io.binac.leetcode;

/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * <p>
 * <p>(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * <p>
 * <p>Find the minimum element.
 * <p>
 * <p>The array may contain duplicates.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [1,3,5]
 *     Output: 1
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [2,2,2,0,1]
 *     Output: 0
 * </blockquote></pre>
 * Note:
 * <p>
 * <p>This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * <p>Would allow duplicates affect the run-time complexity? How and why?
 */
public class FindMinimumInRotatedSortedArrayII {
    public static class Solution1 {
        public int findMin(int[] nums) {
            int low = 0, high = nums.length - 1, mid;
            while (low < high && nums[low] >= nums[high]) {
                mid = (low + high) >>> 1;
                if (nums[mid] > nums[high])
                    low = mid + 1;
                else if (nums[mid] < nums[low])
                    high = mid;
                else
                    --high;
            }
            return nums[low];
        }
    }
}
