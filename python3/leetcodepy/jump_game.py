"""
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.



Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5
"""
from typing import List


class Solution1:
    def canJump(self, nums: List[int]) -> bool:
        farthest = 0
        size = len(nums)
        i = 0
        while i <= farthest < size - 1:
            farthest = max(farthest, i + nums[i])
            i += 1
        return farthest >= size - 1


class Solution2:
    def canJump(self, nums: List[int]) -> bool:
        size = len(nums)
        remainder = 0
        i = 0
        while i < size and remainder >= 0:
            remainder = max(remainder, nums[i]) - 1
            i += 1
        return i == size
