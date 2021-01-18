"""
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"

Example 2:

Input: 4
Output: "1211"
"""


class Solution1:
    @staticmethod
    def count_and_say(s: str) -> str:
        size = len(s)
        result = ''
        i = 0
        while i < size:
            j = i + 1
            while j < size and s[j] == s[i]:
                j += 1
            result += str(j - i) + s[i]
            i = j
        return result

    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n < 1:
            raise ValueError
        result = '1'
        for i in range(n - 1):
            result = self.count_and_say(result)
        return result
