package io.binac.leetcode;

/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * <p>
 * <p>Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     nums1 = [1, 3]
 *     nums2 = [2]
 *
 *     The median is 2.0
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     nums1 = [1, 2]
 *     nums2 = [3, 4]
 *
 *     The median is (2 + 3)/2 = 2.5
 * </blockquote></pre>
 */
public class MedianOfTwoSortedArrays {
    public static class Solution1 {
        public double findMedianSortedArrays(int[] nums1, int[] nums2) {
            if (nums1.length == 0 && nums2.length == 0)
                throw new IllegalArgumentException("nums1 and nums2 can't be empty at the same time");

            if (nums1.length > nums2.length) {
                int tmp[] = nums1;
                nums1 = nums2;
                nums2 = tmp;
            }

            int low = 0, high = nums1.length, mid1 = 0, mid2 = 0;
            final int sum = (nums1.length + nums2.length + 1) >>> 1;
            while (low <= high) {
                mid1 = (low + high) >>> 1;
                mid2 = sum - mid1;
                if (mid1 > 0 && mid2 < nums2.length && nums1[mid1 - 1] > nums2[mid2])
                    high = mid1 - 1;
                else if (mid1 < nums1.length && mid2 > 0 && nums2[mid2 - 1] > nums1[mid1])
                    low = mid1 + 1;
                else
                    break;
            }

            int left;
            if (mid1 == 0)
                left = nums2[mid2 - 1];
            else if (mid2 == 0)
                left = nums1[mid1 - 1];
            else
                left = Math.max(nums1[mid1 - 1], nums2[mid2 - 1]);

            if ((nums1.length + nums2.length) % 2 != 0)
                return left;

            int right;
            if (mid1 == nums1.length)
                right = nums2[mid2];
            else if (mid2 == nums2.length)
                right = nums1[mid1];
            else
                right = Math.min(nums1[mid1], nums2[mid2]);
            return (left + right) / 2.0;
        }
    }
}
