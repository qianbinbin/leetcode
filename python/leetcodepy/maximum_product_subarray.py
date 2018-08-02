"""
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
"""


class Solution1:
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = nums[0]
        dp_max = result
        dp_min = result
        for i in range(1, len(nums)):
            if nums[i] < 0:
                dp_max, dp_min = dp_min, dp_max
            dp_max = max(nums[i], nums[i] * dp_max)
            dp_min = min(nums[i], nums[i] * dp_min)
            result = max(result, dp_max)
        return result
