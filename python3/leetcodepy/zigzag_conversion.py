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

Example 3:

Input: s = "A", numRows = 1
Output: "A"


Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
"""


class Solution1:
    def convert(self, s: str, numRows: int) -> str:
        size = len(s)
        if numRows == 1 or numRows >= size:
            return s
        result = ''
        cycle = 2 * (numRows - 1)
        index = 0
        while index < size:
            result += s[index]
            index += cycle
        for i in range(1, numRows - 1):
            index = i
            offset = 2 * (numRows - i - 1)
            while index < size:
                result += s[index]
                if index + offset < size:
                    result += s[index + offset]
                index += cycle
        index = numRows - 1
        while index < size:
            result += s[index]
            index += cycle
        return result


class Solution2:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s
        lines = ['' for _ in range(numRows)]
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
