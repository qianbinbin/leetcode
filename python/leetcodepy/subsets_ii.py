"""
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
"""
from typing import List


class Solution1:
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        self.subsets_with_dup(sorted(nums), 0, result, [])
        return result

    def subsets_with_dup(self, ordered: List[int], i: int, result: List[List[int]], path: List[int]):
        result.append(path[:])
        while i < len(ordered):
            val = ordered[i]
            path.append(val)
            self.subsets_with_dup(ordered, i + 1, result, path)
            path.pop()
            i += 1
            while i < len(ordered) and ordered[i] == val:
                i += 1
