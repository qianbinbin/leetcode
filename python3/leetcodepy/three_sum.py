"""
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:

Input: nums = []
Output: []

Example 3:

Input: nums = [0]
Output: []


Constraints:

0 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5
"""
from typing import List


class Solution1(object):
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        i = 0
        size = len(nums)
        while i < size - 2:
            target = - nums[i]
            j = i + 1
            k = size - 1
            while j < k:
                val = nums[j] + nums[k]
                if val < target:
                    j += 1
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                elif val > target:
                    k -= 1
                    while j < k and nums[k] == nums[k + 1]:
                        k -= 1
                else:
                    result.append([nums[i], nums[j], nums[k]])
                    j += 1
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                    k -= 1
                    while j < k and nums[k] == nums[k + 1]:
                        k -= 1
            i += 1
            while i < size - 2 and nums[i] == nums[i - 1]:
                i += 1
        return result
