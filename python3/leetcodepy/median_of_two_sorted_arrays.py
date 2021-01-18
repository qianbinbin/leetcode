"""
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.



Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
"""
from typing import List


class Solution1:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m, n = len(nums1), len(nums2)
        if m == 0 and n == 0:
            raise ValueError("'nums1' and 'nums2' cannot be both empty")
        if m > n:
            nums1, nums2 = nums2, nums1
            m, n = n, m
        _sum = (m + n + 1) // 2
        low, high = 0, m
        i, j = 0, 0
        while low <= high:
            i = (low + high) // 2
            j = _sum - i
            if i > 0 and j < n and nums1[i - 1] > nums2[j]:
                high = i - 1
            elif i < m and j > 0 and nums2[j - 1] > nums1[i]:
                low = i + 1
            else:
                break
        if i == 0:
            left = nums2[j - 1]
        elif j == 0:
            left = nums1[i - 1]
        else:
            left = max(nums1[i - 1], nums2[j - 1])
        if (m + n) % 2 != 0:
            return left

        if i == m:
            right = nums2[j]
        elif j == n:
            right = nums1[i]
        else:
            right = min(nums1[i], nums2[j])
        return (left + right) / 2
