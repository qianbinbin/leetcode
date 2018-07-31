package io.binac.leetcode;

/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * <p>
 * <p>(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * <p>
 * <p>You are given a target value to search. If found in the array return true, otherwise return false.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: nums = [2,5,6,0,0,1,2], target = 0
 *     Output: true
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: nums = [2,5,6,0,0,1,2], target = 3
 *     Output: false
 * </blockquote></pre>
 * Follow up:
 * <p>
 * <p>This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
 * <p>Would this affect the run-time complexity? How and why?
 */
public class SearchInRotatedSortedArrayII {
    public static class Solution1 {
        public boolean search(int[] nums, int target) {
            int low = 0, high = nums.length - 1;
            while (low <= high) {
                int mid = (low + high) >>> 1;
                int midVal = nums[mid];
                if (target == midVal)
                    return true;
                if (nums[low] > midVal) {
                    if (midVal < target && target <= nums[high])
                        low = mid + 1;
                    else
                        high = mid - 1;
                } else if (nums[low] < midVal) {
                    if (nums[low] <= target && target < midVal)
                        high = mid - 1;
                    else
                        low = mid + 1;
                } else {
                    while (low < nums.length && nums[low] == midVal) ++low;
                }
            }
            return false;
        }
    }
}
