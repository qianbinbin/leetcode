"""
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
"""
from typing import List


class Solution1:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
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
