"""
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]


Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.


Follow up: Could you come up with a one-pass algorithm using only constant extra space?
"""
from typing import List


class Solution1:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count0, count1 = 0, 0
        for n in nums:
            if n == 0:
                count0 += 1
            elif n == 1:
                count1 += 1
        for i in range(0, count0):
            nums[i] = 0
        for i in range(count0, count0 + count1):
            nums[i] = 1
        for i in range(count0 + count1, len(nums)):
            nums[i] = 2


class Solution2:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        last0, i, first2 = -1, 0, len(nums)
        while i < first2:
            if nums[i] == 0:
                last0 += 1
                nums[last0], nums[i] = nums[i], nums[last0]
                i += 1
            elif nums[i] == 2:
                first2 -= 1
                nums[i], nums[first2] = nums[first2], nums[i]
            else:
                i += 1
