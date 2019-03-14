#include "FlattenBinaryTreeToLinkedList.h"

using namespace lcpp;

static void flattenPreOrder(TreeNode *Root, TreeNode *&Pre) {
  if (Root == nullptr)
    return;
  if (Pre != nullptr) {
    Pre->left = nullptr;
    Pre->right = Root;
  }
  Pre = Root;
  auto Right = Root->right;
  flattenPreOrder(Root->left, Pre);
  flattenPreOrder(Right, Pre);
}

void Solution114_1::flatten(TreeNode *root) {
  TreeNode *Pre = nullptr;
  ::flattenPreOrder(root, Pre);
}
