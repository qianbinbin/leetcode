"""
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).



Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25


Constraints:

-100.0 < x < 100.0
-2^31 <= n <= 2^31-1
-10^4 <= xn <= 10^4
"""


class Solution1:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        result = 1
        e = abs(n)
        while e:
            if e & 1 == 1:
                result *= x
            x *= x
            e = e >> 1
        return result if n >= 0 else 1 / result
