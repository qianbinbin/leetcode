"""
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"

Note:

1. The length of both num1 and num2 is < 110.
2. Both num1 and num2 contain only digits 0-9.
3. Both num1 and num2 do not contain any leading zero, except the number 0 itself.
4. You must not use any built-in BigInteger library or convert the inputs to integer directly.
"""


class Solution1:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        num1 = [int(ch) for ch in num1]
        num2 = [int(ch) for ch in num2]
        len1, len2 = len(num1), len(num2)
        size = len1 + len2
        product = [0] * size
        for j in range(len2 - 1, -1, -1):
            for i in range(len1 - 1, -1, -1):
                product[i + j + 1] += num1[i] * num2[j]
                product[i + j] += product[i + j + 1] // 10
                product[i + j + 1] %= 10
        result = 0
        for val in product:
            result = result * 10 + val
        return str(result)
