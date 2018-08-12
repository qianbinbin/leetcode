"""
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
"""


class Solution1:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        if not a or not b:
            raise ValueError('a and b must be non-empty')
        result = ''
        i, j = len(a) - 1, len(b) - 1
        carry = False
        while i >= 0 and j >= 0:
            tmp = 0
            if a[i] != '0':
                tmp += 1
            if b[j] != '0':
                tmp += 1
            if carry:
                tmp += 1
            result = str(tmp % 2) + result
            carry = True if tmp >= 2 else False
            i -= 1
            j -= 1
        while i >= 0:
            tmp = 0
            if a[i] != '0':
                tmp += 1
            if carry:
                tmp += 1
            result = str(tmp % 2) + result
            carry = True if tmp >= 2 else False
            i -= 1
        while j >= 0:
            tmp = 0
            if b[j] != '0':
                tmp += 1
            if carry:
                tmp += 1
            result = str(tmp % 2) + result
            carry = True if tmp >= 2 else False
            j -= 1
        if carry:
            result = '1' + result
        return result
