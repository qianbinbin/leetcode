"""
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 10^5
"""
from typing import List


class Solution1:
    def jump(self, nums: List[int]) -> int:
        step = 0
        last_farthest, farthest = 0, 0
        for i in range(len(nums)):
            if i > farthest:
                break
            if i > last_farthest:
                step += 1
                last_farthest = farthest
            farthest = max(farthest, i + nums[i])
            i += 1
        return step
