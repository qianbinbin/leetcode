"""
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
"""
from typing import List


class Solution1:
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        set_ = set(nums)
        for num in nums:
            if num - 1 not in set_:
                end = num + 1
                while end in set_:
                    end += 1
                result = max(result, end - num)
        return result
