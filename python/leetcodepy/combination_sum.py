"""
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
"""
from typing import List


class Solution1:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = []
        self.combination_sum(candidates, target, 0, 0, result, [])
        return result

    def combination_sum(self, candidates: List[int], target: int, sum_: int, index: int,
                        result: List[List[int]], path: List[int]):
        if sum_ == target:
            result.append(path[:])
            return
        for i in range(index, len(candidates)):
            if sum_ + candidates[i] <= target:
                path.append(candidates[i])
                self.combination_sum(candidates, target, sum_ + candidates[i], i, result, path)
                path.pop()
