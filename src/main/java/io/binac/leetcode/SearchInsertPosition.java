package io.binac.leetcode;

/**
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * <p>
 * <p>You may assume no duplicates in the array.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [1,3,5,6], 5
 *     Output: 2
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [1,3,5,6], 2
 *     Output: 1
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input: [1,3,5,6], 7
 *     Output: 4
 * </blockquote></pre>
 * Example 4:
 * <blockquote><pre>
 *     Input: [1,3,5,6], 0
 *     Output: 0
 * </blockquote></pre>
 */
public class SearchInsertPosition {
    public static class Solution1 {
        public int searchInsert(int[] nums, int target) {
            int low = 0, high = nums.length - 1;
            while (low <= high) {
                int mid = (low + high) >>> 1;
                int midVal = nums[mid];
                if (midVal == target)
                    return mid;
                else if (midVal > target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return low;
        }
    }
}
