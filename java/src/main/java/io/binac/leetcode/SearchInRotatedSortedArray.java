package io.binac.leetcode;

/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * <p>
 * <p>(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * <p>
 * <p>You are given a target value to search. If found in the array return its index, otherwise return -1.
 * <p>
 * <p>You may assume no duplicate exists in the array.
 * <p>
 * <p>Your algorithm's runtime complexity must be in the order of O(log n).
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: nums = [4,5,6,7,0,1,2], target = 0
 *     Output: 4
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: nums = [4,5,6,7,0,1,2], target = 3
 *     Output: -1
 * </blockquote></pre>
 */
public class SearchInRotatedSortedArray {
    public static class Solution1 {
        public int search(int[] nums, int target) {
            int low = 0, high = nums.length - 1;
            while (low <= high) {
                int mid = (low + high) >>> 1;
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] < target) {
                    if (nums[low] <= nums[mid]) {
                        low = mid + 1;
                    } else {
                        if (nums[high] >= target)
                            low = mid + 1;
                        else
                            high = mid - 1;
                    }
                } else {
                    if (nums[mid] <= nums[high]) {
                        high = mid - 1;
                    } else {
                        if (nums[low] <= target)
                            high = mid - 1;
                        else
                            low = mid + 1;
                    }
                }
            }
            return -1;
        }
    }
}
