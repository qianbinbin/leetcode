"""
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]


Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
"""
from typing import List


class Solution1:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        self.permutations(nums, [False] * len(nums), result, [])
        return result

    def permutations(self, nums: List[int], used: List[bool], result: List[List[int]], path: List[int]):
        if len(path) == len(nums):
            result.append(path[:])
            return
        for i in range(len(nums)):
            if used[i]:
                continue
            used[i] = True
            path.append(nums[i])
            self.permutations(nums, used, result, path)
            path.pop()
            used[i] = False
