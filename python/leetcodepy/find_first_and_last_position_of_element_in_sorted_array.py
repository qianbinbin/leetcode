"""
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
"""
from typing import List


class Solution1:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        low, high = 0, len(nums) - 1
        while low <= high:
            mid = (low + high) // 2
            mid_val = nums[mid]
            if mid_val == target:
                first = mid
                while first > 0 and nums[first - 1] == mid_val:
                    first -= 1
                last = mid
                while last + 1 < len(nums) and nums[last + 1] == mid_val:
                    last += 1
                return [first, last]
            if mid_val > target:
                high = mid - 1
            else:
                low = mid + 1
        return [-1, -1]
