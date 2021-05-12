"""
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.



Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"


Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
"""


class Solution1:
    def multiply(self, num1: str, num2: str) -> str:
        len1, len2 = len(num1), len(num2)
        size = len1 + len2
        product = [0] * size
        for j in range(len2 - 1, -1, -1):
            for i in range(len1 - 1, -1, -1):
                product[i + j + 1] += int(num1[i]) * int(num2[j])
                product[i + j] += product[i + j + 1] // 10
                product[i + j + 1] %= 10
        start = 0
        while start < size - 1 and product[start] == 0:
            start += 1
        result = str()
        for i in range(start, size):
            result += str(product[i])
        return result
