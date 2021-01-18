"""
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3

Example 2:

Input: dividend = 7, divisor = -3
Output: -2

Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function returns 2^31 − 1 when the division result overflows.
"""


class Solution1:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if divisor == 0:
            raise ZeroDivisionError
        sign = 1
        if dividend > 0 > divisor or dividend < 0 < divisor:
            sign = -1
        dividend, divisor = abs(dividend), abs(divisor)
        result = 0
        while dividend >= divisor:
            count = 1
            sub = divisor
            while dividend >= sub:
                count += count
                sub += sub
            dividend -= sub >> 1
            result += count >> 1
        result *= sign
        # This is ridiculous
        if result < -0x80000000:
            return -0x80000000
        if result > 0x7fffffff:
            return 0x7fffffff
        return result
