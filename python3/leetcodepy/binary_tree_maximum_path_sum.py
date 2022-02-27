"""
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.



Example 1:
https://assets.leetcode.com/uploads/2020/10/13/exx1.jpg

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:
https://assets.leetcode.com/uploads/2020/10/13/exx2.jpg

Input: root = [-10,9,20,null,null,15,7]
Output: 42

Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.


Constraints:

The number of nodes in the tree is in the range [1, 3 * 10^4].
-1000 <= Node.val <= 1000
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        result = [root.val]
        self.single_max_path_sum(root, result)
        return result[0]

    def single_max_path_sum(self, root: Optional[TreeNode], max_path_sum: List[int]) -> int:
        if root is None:
            return 0
        left = max(0, self.single_max_path_sum(root.left, max_path_sum))
        right = max(0, self.single_max_path_sum(root.right, max_path_sum))
        max_path_sum[0] = max(max_path_sum[0], root.val + left + right)
        return root.val + max(left, right)
