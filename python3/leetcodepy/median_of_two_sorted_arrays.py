"""
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000

Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000

Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000


Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
"""
from typing import List


class Solution1:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        (nums1, nums2) = (nums1, nums2) if len(nums1) <= len(nums2) else (nums2, nums1)
        m, n = len(nums1), len(nums2)
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
