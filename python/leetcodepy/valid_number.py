"""
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
"""


class Solution1:
    @staticmethod
    def _is_numeric(s: str) -> bool:
        if s.startswith('+') or s.startswith('-'):
            s = s[1:]
        nums = s.split('.')
        count = len(nums)
        if count < 1 or count > 2:
            return False
        if count == 1:
            return nums[0].isnumeric()
        if count == 2:
            if not nums[0]:
                return nums[1].isnumeric()
            if not nums[1]:
                return nums[0].isnumeric()
            return nums[0].isnumeric() and nums[1].isnumeric()

    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        words = s.split()
        if len(words) != 1:
            return False
        s = words[0]
        nums = s.split('e')
        if len(nums) > 2:
            return False
        if len(nums) == 1:
            return self._is_numeric(nums[0])
        if nums[1].startswith('+') or nums[1].startswith('-'):
            nums[1] = nums[1][1:]
        return self._is_numeric(nums[0]) and nums[1].isnumeric()


class Solution2:
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        try:
            float(s)
        except ValueError:
            return False
        return True
