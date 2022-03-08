from queue import Queue
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def from_values(*args: Optional[int]) -> Optional[TreeNode]:
    if not args or args[0] is None:
        return None
    q = Queue()
    root = TreeNode(args[0])
    q.put(root)
    i = 1
    size = len(args)
    while i < size and not q.empty():
        node = q.get()
        if args[i] is not None:
            node.left = TreeNode(args[i])
            q.put(node.left)
        if i + 1 < size and args[i + 1] is not None:
            node.right = TreeNode(args[i + 1])
            q.put(node.right)
        i += 2
    return root


def equals(root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
    if root1 is root2:
        return True
    if root1 is None or root2 is None:
        return False
    if root1.val != root2.val:
        return False
    return equals(root1.left, root2.left) and equals(root1.right, root2.right)
