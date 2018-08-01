"""
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
"""


class Solution1:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        result = sum(nums[0:3])
        ordered = sorted(nums)
        size = len(ordered)
        i = 0
        while i < size - 2:
            s = target - ordered[i]
            j = i + 1
            k = size - 1
            while j < k:
                val = ordered[j] + ordered[k]
                if abs(result - target) > abs(ordered[i] + val - target):
                    result = ordered[i] + val
                if val < s:
                    j += 1
                    while j < k and ordered[j] == ordered[j - 1]:
                        j += 1
                elif val > s:
                    k -= 1
                    while j < k and ordered[k] == ordered[k + 1]:
                        k -= 1
                else:
                    return target
            i += 1
            while i < size - 2 and ordered[i] == ordered[i - 1]:
                i += 1
        return result
