"""
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.



Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false


Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
nums is guaranteed to be rotated at some pivot.
-10^4 <= target <= 10^4


Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?
"""
from typing import List


class Solution1:
    def search(self, nums: List[int], target: int) -> bool:
        low, high = 0, len(nums) - 1
        while low <= high:
            mid = (low + high) // 2
            mid_val = nums[mid]
            if mid_val == target:
                return True
            if nums[low] < mid_val:
                if nums[low] <= target < mid_val:
                    high = mid - 1
                else:
                    low = mid + 1
            elif nums[low] > mid_val:
                if mid_val < target <= nums[high]:
                    low = mid + 1
                else:
                    high = mid - 1
            else:
                low += 1
                while low <= high and nums[low] == mid_val:
                    low += 1
        return False
