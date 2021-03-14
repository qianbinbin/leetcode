"""
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png



Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

Input: digits = ""
Output: []

Example 3:

Input: digits = "2"
Output: ["a","b","c"]


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
"""
from typing import Dict, List


class Solution1:
    __DICT: Dict[str, str] = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv',
                              '9': 'wxyz'}

    def letterCombinations(self, digits: str) -> List[str]:
        result = []
        if not digits:
            return result
        self.letter_combinations(digits, result, '')
        return result

    def letter_combinations(self, digits: str, result: List[str], path: str):
        if len(path) == len(digits):
            result.append(path)
            return
        for ch in self.__DICT[digits[len(path)]]:
            self.letter_combinations(digits, result, path + ch)
