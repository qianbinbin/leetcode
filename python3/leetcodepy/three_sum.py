"""
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
"""


class Solution1(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ordered = sorted(nums)
        result = []
        i = 0
        size = len(ordered)
        while i < size - 2:
            target = - ordered[i]
            j = i + 1
            k = size - 1
            while j < k:
                val = ordered[j] + ordered[k]
                if val < target:
                    j += 1
                    while j < k and ordered[j] == ordered[j - 1]:
                        j += 1
                elif val > target:
                    k -= 1
                    while j < k and ordered[k] == ordered[k + 1]:
                        k -= 1
                else:
                    result.append([ordered[i], ordered[j], ordered[k]])
                    j += 1
                    while j < k and ordered[j] == ordered[j - 1]:
                        j += 1
                    k -= 1
                    while j < k and ordered[k] == ordered[k + 1]:
                        k -= 1
            i += 1
            while i < size - 2 and ordered[i] == ordered[i - 1]:
                i += 1
        return result
