package io.binac.leetcode;

/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * <p>
 * <p>Note:
 * <p>
 * <p>The number of elements initialized in nums1 and nums2 are m and n respectively.
 * <p>You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input:
 *     nums1 = [1,2,3,0,0,0], m = 3
 *     nums2 = [2,5,6],       n = 3
 *
 *     Output: [1,2,2,3,5,6]
 * </blockquote></pre>
 */
public class MergeSortedArray {
    public static class Solution1 {
        public void merge(int[] nums1, int m, int[] nums2, int n) {
            if (nums1.length < m + n)
                throw new IllegalArgumentException();
            --m;
            --n;
            while (m >= 0 && n >= 0) {
                if (nums1[m] > nums2[n]) {
                    nums1[m + n + 1] = nums1[m];
                    --m;
                } else {
                    nums1[m + n + 1] = nums2[n];
                    --n;
                }
            }
            if (n >= 0)
                System.arraycopy(nums2, 0, nums1, 0, n + 1);
        }
    }
}
