"""
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.

Note:

You can assume that you can always reach the last index.
"""
from typing import List


class Solution1:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        step = 0
        cur_farthest, farthest = 0, 0
        size = len(nums)
        i = 0
        while i <= farthest and i < size:
            if i > cur_farthest:
                step += 1
                cur_farthest = farthest
            farthest = max(farthest, i + nums[i])
            i += 1
        if farthest < size - 1:
            raise ValueError("can't reach the last index")
        return step
