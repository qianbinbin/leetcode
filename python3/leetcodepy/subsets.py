"""
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
"""
from typing import List


class Solution1:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        self._subset(nums, 0, result, [])
        return result

    def _subset(self, nums: List[int], i: int, result: List[List[int]], path: List[int]):
        result.append(path[:])
        while i < len(nums):
            path.append(nums[i])
            self._subset(nums, i + 1, result, path)
            path.pop()
            i += 1
