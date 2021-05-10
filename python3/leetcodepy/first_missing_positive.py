"""
Given an unsorted integer array nums, find the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.



Example 1:

Input: nums = [1,2,0]
Output: 3

Example 2:

Input: nums = [3,4,-1,1]
Output: 2

Example 3:

Input: nums = [7,8,9,11,12]
Output: 1


Constraints:

1 <= nums.length <= 5 * 10^5
-2^31 <= nums[i] <= 2^31 - 1
"""
from typing import List


class Solution1:
    def firstMissingPositive(self, nums: List[int]) -> int:
        size = len(nums)
        for i in range(size):
            val = nums[i]
            while val != i + 1 and val != i + 1 and 0 < val <= size and nums[val - 1] != val:
                self.swap(nums, i, val - 1)
                val = nums[i]
        for i in range(size):
            if nums[i] != i + 1:
                return i + 1
        return size + 1

    @staticmethod
    def swap(nums: List[int], i: int, j: int):
        nums[i], nums[j] = nums[j], nums[i]
