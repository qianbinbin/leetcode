#include "ConvertSortedListToBinarySearchTree.h"

using namespace lcpp;

static TreeNode *sortedListToBST(ListNode *&Head, std::size_t Begin,
                                 std::size_t End) {
  if (Begin == End)
    return nullptr;
  auto Mid = Begin + (End - Begin) / 2;
  auto Left = sortedListToBST(Head, Begin, Mid);
  auto Root = new TreeNode(Head->val);
  Root->left = Left;
  Head = Head->next;
  Root->right = sortedListToBST(Head, Mid + 1, End);
  return Root;
}

TreeNode *Solution109_1::sortedListToBST(ListNode *head) {
  std::size_t Size = 0;
  for (auto Node = head; Node != nullptr; Node = Node->next)
    ++Size;
  return ::sortedListToBST(head, 0, Size);
}
