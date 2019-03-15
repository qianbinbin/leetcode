#include "SumRootToLeafNumbers.h"

using namespace lcpp;

static void sumNumbers(TreeNode *Root, int Path, int &Sum) {
  Path = Path * 10 + Root->val;
  if (Root->left == nullptr && Root->right == nullptr) {
    Sum += Path;
    return;
  }
  if (Root->left != nullptr)
    sumNumbers(Root->left, Path, Sum);
  if (Root->right != nullptr)
    sumNumbers(Root->right, Path, Sum);
}

int Solution129_1::sumNumbers(TreeNode *root) {
  // assert(root != nullptr);
  // Handle the dirty case,
  // as you can't tell whether it actually sums to 0 or is just null.
  if (root == nullptr)
    return 0;
  int Sum = 0;
  ::sumNumbers(root, 0, Sum);
  return Sum;
}
