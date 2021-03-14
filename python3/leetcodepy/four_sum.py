"""
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.



Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [], target = 0
Output: []


Constraints:

0 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
"""
from collections import defaultdict
from typing import List


class Solution1:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        nums.sort()
        i1 = 0
        size = len(nums)
        while i1 < size - 3:
            i2 = i1 + 1
            while i2 < size - 2:
                i3 = i2 + 1
                i4 = size - 1
                while i3 < i4:
                    s = target - nums[i1] - nums[i2]
                    val = nums[i3] + nums[i4]
                    if val < s:
                        i3 += 1
                        while i3 < i4 and nums[i3] == nums[i3 - 1]:
                            i3 += 1
                    elif val > s:
                        i4 -= 1
                        while i3 < i4 and nums[i4] == nums[i4 + 1]:
                            i4 -= 1
                    else:
                        result.append([nums[i1], nums[i2], nums[i3], nums[i4]])
                        i3 += 1
                        while i3 < i4 and nums[i3] == nums[i3 - 1]:
                            i3 += 1
                        i4 -= 1
                        while i3 < i4 and nums[i4] == nums[i4 + 1]:
                            i4 -= 1
                i2 += 1
                while i2 < size - 2 and nums[i2] == nums[i2 - 1]:
                    i2 += 1
            i1 += 1
            while i1 < size - 3 and nums[i1] == nums[i1 - 1]:
                i1 += 1
        return result


class Solution2:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = set()
        _map = defaultdict(list)
        nums.sort()
        size = len(nums)
        for i in range(size - 1):
            for j in range(i + 1, size):
                s = nums[i] + nums[j]
                _map[s].append((i, j))

        for k, v in _map.items():
            if target - k not in _map:
                continue
            for (i, j) in v:
                for (m, n) in _map[target - k]:
                    if i != m and i != n and j != m and j != n:
                        result.add(tuple(sorted([nums[i], nums[j], nums[m], nums[n]])))
        result = [list(e) for e in result]
        return result
