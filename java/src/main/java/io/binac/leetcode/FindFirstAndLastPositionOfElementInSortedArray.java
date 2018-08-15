package io.binac.leetcode;

/**
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 * <p>
 * <p>Your algorithm's runtime complexity must be in the order of O(log n).
 * <p>
 * <p>If the target is not found in the array, return [-1, -1].
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: nums = [5,7,7,8,8,10], target = 8
 *     Output: [3,4]
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: nums = [5,7,7,8,8,10], target = 6
 *     Output: [-1,-1]
 * </blockquote></pre>
 */
public class FindFirstAndLastPositionOfElementInSortedArray {
    public static class Solution1 {
        private int insertIndex(int[] array, int fromIndex, int toIndex, int value, boolean before) {
            int low = fromIndex, high = toIndex - 1;
            while (low <= high) {
                int mid = (low + high) >>> 1;
                int midVal = array[mid];
                if (midVal > value || (before && midVal == value))
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return low;
        }

        public int[] searchRange(int[] nums, int target) {
            if (nums == null) throw new NullPointerException();

            int result[] = new int[2];
            int index = insertIndex(nums, 0, nums.length, target, true);
            if (index == nums.length || nums[index] != target) {
                result[0] = -1;
                result[1] = -1;
            } else {
                result[0] = index;
                result[1] = insertIndex(nums, index, nums.length, target, false) - 1;
            }
            return result;
        }
    }
}
