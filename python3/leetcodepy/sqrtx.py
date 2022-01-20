"""
Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.



Example 1:

Input: x = 4
Output: 2

Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.


Constraints:

0 <= x <= 231 - 1
"""


class Solution1:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x
        low, high = 0, x // 2
        while low <= high:
            mid = (low + high) // 2
            if mid * mid > x:
                high = mid - 1
            elif (mid + 1) * (mid + 1) <= x:
                low = mid + 1
            else:
                return mid
        raise RuntimeError


class Solution2:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x
        result = x // 2
        while not (result * result <= x < (result + 1) * (result + 1)):
            result = (x // result + result) // 2
        return result


class Solution3:
    def mySqrt(self, x: int) -> int:
        result = 0
        odd = 1
        while x >= odd:
            x -= odd
            result += 1
            odd += 2
        return result
