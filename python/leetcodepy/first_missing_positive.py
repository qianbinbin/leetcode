"""
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3

Example 2:

Input: [3,4,-1,1]
Output: 2

Example 3:

Input: [7,8,9,11,12]
Output: 1

Note:

Your algorithm should run in O(n) time and uses constant extra space.
"""
from typing import List


class Solution1:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        size = len(nums)
        for i in range(size):
            while 0 < nums[i] <= size and nums[i] != i + 1 and nums[nums[i] - 1] != nums[i]:
                self.swap(nums, i, nums[i] - 1)
        for i in range(size):
            if nums[i] != i + 1:
                return i + 1
        return size + 1

    @staticmethod
    def swap(nums: List[int], i: int, j: int):
        nums[i], nums[j] = nums[j], nums[i]
