"""
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:

Input: "race a car"
Output: false
"""


class Solution1:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = ''.join([ch for ch in s if ch.isalnum()]).lower()
        return s == s[::-1]
