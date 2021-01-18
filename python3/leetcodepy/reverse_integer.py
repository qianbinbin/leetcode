"""
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
"""


class Solution1:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        result = 0
        sign = 1 if x >= 0 else -1
        x = abs(x)
        while x:
            result = result * 10 + x % 10
            x = x // 10
        result *= sign
        if result > 0x7fffffff or result < -0x80000000:
            # This is ridiculous as Python hasn't integer overflow
            return 0
        return result
