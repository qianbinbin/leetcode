"""
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2

Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
             the decimal part is truncated, 2 is returned.
"""


class Solution1:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0:
            raise ValueError("'x' must be a non-negative integer")
        if x < 2:
            return x
        low, high = 0, x // 2
        while low <= high:
            mid = (low + high) // 2
            val = mid * mid
            if val <= x < (mid + 1) * (mid + 1):
                return mid
            elif val > x:
                high = mid - 1
            else:
                low = mid + 1
        raise RuntimeError
