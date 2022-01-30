"""
A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.

Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.



Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]

Example 3:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]


Constraints:

0 <= s.length <= 20
s consists of digits only.
"""
from typing import List


class Solution1:
    def restoreIpAddresses(self, s: str) -> List[str]:
        result = []
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


class Solution2:
    def restoreIpAddresses(self, s: str) -> List[str]:
        result = []
        size = len(s)
        for i in range(1, 4):
            for j in range(i + 1, min(i + 4, size - 1)):
                for k in range(j + 1, min(j + 4, size)):
                    s1, s2, s3, s4 = s[:i], s[i:j], s[j:k], s[k:]
                    if self.is_valid(s1) and self.is_valid(s2) and self.is_valid(s3) and self.is_valid(s4):
                        result.append(s1 + '.' + s2 + '.' + s3 + '.' + s4)
        return result

    @staticmethod
    def is_valid(s: str) -> bool:
        size = len(s)
        if size < 1 or size > 3:
            return False
        if s[0] == '0':
            return size == 1
        return int(s) < 256
