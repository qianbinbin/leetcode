"""
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

Example 4:

Input: x = 0
Output: 0


Constraints:

-2^31 <= x <= 2^31 - 1
"""


class Solution1:
    def reverse(self, x: int) -> int:
        result = 0
        mod = 10 if x >= 0 else -10  # correction for python
        while x != 0:
            if result > 214748364 or result < -214748364:
                return 0
            result = result * 10 + x % mod
            x = int(x / 10)
        return result
