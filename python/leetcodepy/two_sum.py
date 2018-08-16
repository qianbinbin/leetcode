"""
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
"""
from typing import List


class Solution1:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) < 2:
            raise ValueError
        hash_map = {nums[0]: 0}
        for i in range(1, len(nums)):
            if target - nums[i] in hash_map:
                return [hash_map[target - nums[i]], i]
            hash_map[nums[i]] = i
        raise ValueError
