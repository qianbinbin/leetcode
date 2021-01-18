"""
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
"""


class Solution1:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows < 1:
            raise ValueError
        if numRows == 1:
            return s
        size = len(s)
        result = ''
        cycle = 2 * numRows - 2

        index = 0
        while index < size:
            result += s[index]
            index += cycle
        for i in range(1, numRows - 1):
            index = i
            c = 2 * (numRows - i) - 2
            while index < size:
                result += s[index]
                if index + c < size:
                    result += s[index + c]
                index += cycle
        index = numRows - 1
        while index < size:
            result += s[index]
            index += cycle
        return result


class Solution2:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows < 1:
            raise ValueError
        if numRows == 1:
            return s
        lines = ['' for i in range(numRows)]
        row = 0
        increase = 0
        for ch in s:
            if row == 0:
                increase = 1
            elif row == numRows - 1:
                increase = -1
            lines[row] += ch
            row += increase
        return ''.join(lines)
