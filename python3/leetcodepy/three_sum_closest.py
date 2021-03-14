"""
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.



Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
"""
from typing import List


class Solution1:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        result = sum(nums[0:3])
        nums.sort()
        size = len(nums)
        i = 0
        while i < size - 2:
            j = i + 1
            k = size - 1
            while j < k:
                _sum = nums[i] + nums[j] + nums[k]
                if abs(result - target) > abs(_sum - target):
                    result = _sum
                if _sum < target:
                    j += 1
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                elif _sum > target:
                    k -= 1
                    while j < k and nums[k] == nums[k + 1]:
                        k -= 1
                else:
                    return target
            i += 1
            while i < size - 2 and nums[i] == nums[i - 1]:
                i += 1
        return result
