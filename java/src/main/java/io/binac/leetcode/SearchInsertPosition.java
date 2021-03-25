package io.binac.leetcode;

/**
 * <p>Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> nums = [1,3,5,6], target = 5
 * <strong>Output:</strong> 2
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> nums = [1,3,5,6], target = 2
 * <strong>Output:</strong> 1
 * </pre><p><strong>Example 3:</strong></p>
 * <pre><strong>Input:</strong> nums = [1,3,5,6], target = 7
 * <strong>Output:</strong> 4
 * </pre><p><strong>Example 4:</strong></p>
 * <pre><strong>Input:</strong> nums = [1,3,5,6], target = 0
 * <strong>Output:</strong> 0
 * </pre><p><strong>Example 5:</strong></p>
 * <pre><strong>Input:</strong> nums = [1], target = 0
 * <strong>Output:</strong> 0
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
 * 	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
 * 	<li><code>nums</code> contains <strong>distinct</strong> values sorted in <strong>ascending</strong> order.</li>
 * 	<li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li>
 * </ul>
 */
public class SearchInsertPosition {
    public static class Solution1 {
        public int searchInsert(int[] nums, int target) {
            int low = 0, high = nums.length - 1, mid, val;
            while (low <= high) {
                mid = (low + high) >>> 1;
                val = nums[mid];
                if (val == target)
                    return mid;
                else if (val > target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return low;
        }
    }
}
