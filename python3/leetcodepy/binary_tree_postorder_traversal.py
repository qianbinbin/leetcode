"""
Given the root of a binary tree, return the postorder traversal of its nodes' values.



Example 1:
https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg

Input: root = [1,null,2,3]
Output: [3,2,1]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]


Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100


Follow up: Recursive solution is trivial, could you do it iteratively?
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        self.post_order(root, result)
        return result

    def post_order(self, root: Optional[TreeNode], result: List[int]):
        if root is None:
            return
        self.post_order(root.left, result)
        self.post_order(root.right, result)
        result.append(root.val)


class Solution2:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        stack = []
        node, pre = root, None
        while stack or node is not None:
            if node is not None:
                stack.append(node)
                node = node.left
            else:
                peek = stack[-1]
                if peek.right is not None and peek.right is not pre:
                    node = peek.right
                else:
                    result.append(peek.val)
                    pre = stack.pop()
        return result


class Solution3:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        if root is None:
            return result
        stack = [root]
        while stack:
            node = stack.pop()
            result.append(node.val)
            if node.left is not None:
                stack.append(node.left)
            if node.right is not None:
                stack.append(node.right)
        result.reverse()
        return result
