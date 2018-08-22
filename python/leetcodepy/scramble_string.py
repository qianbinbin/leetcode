"""
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true

Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false
"""


class Solution1:
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        size = len(s1)
        if len(s2) != size:
            raise ValueError
        if size == 0:
            return True
        dp = [[[False] * size for _ in range(size)] for __ in range(size + 1)]
        for i in range(size):
            for j in range(size):
                if s1[i] == s2[j]:
                    dp[1][i][j] = True
        for length in range(2, size + 1):
            for i in range(size - length + 1):
                for j in range(size - length + 1):
                    for len_ in range(1, length):
                        if dp[len_][i][j] and dp[length - len_][i + len_][j + len_] \
                                or dp[len_][i][j + length - len_] and dp[length - len_][i + len_][j]:
                            dp[length][i][j] = True
                            break
        return dp[size][0][0]
