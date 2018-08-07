"""
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"

Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.

Example 1:

Input: n = 3, k = 3
Output: "213"

Example 2:

Input: n = 4, k = 9
Output: "2314"
"""


class Solution1:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        if n < 1 or n > 9:
            raise ValueError
        if k < 1:
            raise ValueError
        factorials = [1] * (n + 1)
        for i in range(2, n + 1):
            factorials[i] = factorials[i - 1] * i
        if k > factorials[n]:
            raise ValueError

        values = [str(i) for i in range(1, n + 1)]
        result = ""
        k -= 1
        while n > 0:
            i = k // factorials[n - 1]
            result += values[i]
            values.remove(values[i])
            k %= factorials[n - 1]
            n -= 1
        return result
