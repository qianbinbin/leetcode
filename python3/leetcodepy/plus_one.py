"""
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
"""
from typing import List


class Solution1:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        if not digits:
            raise ValueError
        return [int(ch) for ch in str(int(''.join([str(num) for num in digits])) + 1)]


class Solution2:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        if not digits:
            raise ValueError
        result = digits[:]
        for i in range(len(digits) - 1, -1, -1):
            if result[i] == 9:
                result[i] = 0
            else:
                result[i] += 1
                return result
        return [1] + result
