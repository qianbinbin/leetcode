"""
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
"""
from typing import List


class Solution1:
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = []
        self.combination_sum(sorted(candidates), 0, target, 0, result, [])
        return result

    def combination_sum(self, ordered: List[int], i: int, target: int, sum_: int,
                        result: List[List[int]], path: List[int]):
        if sum_ == target:
            result.append(path[:])
            return
        val = -1
        while i < len(ordered):
            if sum_ + ordered[i] <= target:
                val = ordered[i]
                path.append(val)
                self.combination_sum(ordered, i + 1, target, sum_ + val, result, path)
                path.pop()
            i += 1
            while i < len(ordered) and ordered[i] == val:
                i += 1
