package io.binac.leetcode;

/**
 * <p>Given an array of integers <code>nums</code> sorted in ascending order, find the starting and ending position of a given <code>target</code> value.</p>
 *
 * <p>If <code>target</code> is not found in the array, return <code>[-1, -1]</code>.</p>
 *
 * <p><strong>Follow up:</strong>&nbsp;Could you write an algorithm with&nbsp;<code>O(log n)</code> runtime complexity?</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> nums = [5,7,7,8,8,10], target = 8
 * <strong>Output:</strong> [3,4]
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> nums = [5,7,7,8,8,10], target = 6
 * <strong>Output:</strong> [-1,-1]
 * </pre><p><strong>Example 3:</strong></p>
 * <pre><strong>Input:</strong> nums = [], target = 0
 * <strong>Output:</strong> [-1,-1]
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>0 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
 * 	<li><code>-10<sup>9</sup>&nbsp;&lt;= nums[i]&nbsp;&lt;= 10<sup>9</sup></code></li>
 * 	<li><code>nums</code> is a non-decreasing array.</li>
 * 	<li><code>-10<sup>9</sup>&nbsp;&lt;= target&nbsp;&lt;= 10<sup>9</sup></code></li>
 * </ul>
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
            int[] result = new int[2];
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
