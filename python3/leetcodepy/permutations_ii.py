"""
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
"""
from typing import List


class Solution1:
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        self.permute_unique(sorted(nums), [False] * len(nums), result, [])
        return result

    def permute_unique(self, ordered: List[int], used: List[bool], result: List[List[int]], path: List[int]):
        if len(path) == len(ordered):
            result.append(path[:])
            return
        i = 0
        while i < len(ordered):
            if used[i]:
                i += 1
                continue
            val = ordered[i]
            used[i] = True
            path.append(val)
            self.permute_unique(ordered, used, result, path)
            path.pop()
            used[i] = False
            i += 1
            while i < len(ordered) and ordered[i] == val:
                i += 1
