"""
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9
"""
from typing import List


class Solution1:
    @staticmethod
    def insert_index(nums: List[int], low: int, high: int, val: int, before: bool) -> int:
        while low < high:
            mid = (low + high) // 2
            if nums[mid] > val or (before and nums[mid] == val):
                high = mid
            else:
                low = mid + 1
        return low

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        i = self.insert_index(nums, 0, len(nums), target, True)
        if i == len(nums) or nums[i] != target:
            return [-1, -1]
        return [i, self.insert_index(nums, i, len(nums), target, False) - 1]
