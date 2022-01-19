"""
Given two binary strings a and b, return their sum as a binary string.



Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
"""


class Solution1:
    def addBinary(self, a: str, b: str) -> str:
        result = ''
        i, j = len(a) - 1, len(b) - 1
        carry = 0
        while i >= 0 and j >= 0:
            val = int(a[i]) + int(b[j]) + carry
            result = str(val % 2) + result
            carry = val // 2
            i -= 1
            j -= 1
        while i >= 0:
            val = int(a[i]) + carry
            result = str(val % 2) + result
            carry = val // 2
            i -= 1
        while j >= 0:
            val = int(b[j]) + carry
            result = str(val % 2) + result
            carry = val // 2
            j -= 1
        if carry:
            result = '1' + result
        return result


class Solution2:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a, 2) + int(b, 2))[2:]
