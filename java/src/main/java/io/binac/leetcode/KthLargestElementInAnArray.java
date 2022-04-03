package io.binac.leetcode;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * <p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the</em> <code>k<sup>th</sup></code> <em>largest element in the array</em>.</p>
 *
 * <p>Note that it is the <code>k<sup>th</sup></code> largest element in the sorted order, not the <code>k<sup>th</sup></code> distinct element.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> nums = [3,2,1,5,6,4], k = 2
 * <strong>Output:</strong> 5
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> nums = [3,2,3,1,2,4,5,5,6], k = 4
 * <strong>Output:</strong> 4
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
 * 	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
 * </ul>
 */
public class KthLargestElementInAnArray {
    public static class Solution1 {
        public int findKthLargest(int[] nums, int k) {
            int i = nums.length - k;
            Queue<Integer> heap = new PriorityQueue<Integer>(k - 1 <= i ? Comparator.reverseOrder() : Comparator.naturalOrder());
            Arrays.stream(nums).forEach(heap::add);
            for (int j = Math.min(k - 1, i); j > 0; --j)
                heap.remove();
            return heap.remove();
        }
    }

    public static class Solution2 {
        private int partition(int[] nums, int i, int j) {
            int pivot = nums[i];
            while (i < j) {
                while (i < j && pivot <= nums[j])
                    --j;
                nums[i] = nums[j];
                while (i < j && nums[i] <= pivot)
                    ++i;
                nums[j] = nums[i];
            }
            nums[i] = pivot;
            return i;
        }

        private int findKthSmallestFrom0(int[] nums, int i, int j, int k) {
            int p = partition(nums, i, j);
            if (p == k)
                return nums[p];
            return p > k ? findKthSmallestFrom0(nums, i, p - 1, k) : findKthSmallestFrom0(nums, p + 1, j, k);
        }

        public int findKthLargest(int[] nums, int k) {
            return findKthSmallestFrom0(nums, 0, nums.length - 1, nums.length - k);
        }
    }
}
