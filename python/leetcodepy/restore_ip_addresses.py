"""
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
"""
from typing import List


class Solution1:
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        result = []
        size = len(s)
        if size < 4 or size > 12:
            return result
        self.restore_ip_addresses(s, 0, result, [])
        return result

    def restore_ip_addresses(self, s: str, i: int, result: List[str], path: List[str]):
        if i == len(s) or len(path) == 4:
            if i == len(s) and len(path) == 4:
                result.append('.'.join(path))
            return
        if s[i] == '0':
            path.append('0')
            self.restore_ip_addresses(s, i + 1, result, path)
            path.pop()
            return
        for j in range(i + 1, min(i + 4, len(s) + 1)):
            segment = s[i:j]
            if int(segment) < 256:
                path.append(segment)
                self.restore_ip_addresses(s, j, result, path)
                path.pop()
