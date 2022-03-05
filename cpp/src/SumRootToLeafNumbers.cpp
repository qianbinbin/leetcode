#include "SumRootToLeafNumbers.h"

using namespace lcpp;

static int sumNumbers(TreeNode *Root, int Path) {
  if (Root == nullptr)
    return 0;
  Path = Path * 10 + Root->val;
  if (Root->left == nullptr && Root->right == nullptr) {
    return Path;
  }
  return sumNumbers(Root->left, Path) + sumNumbers(Root->right, Path);
}

int Solution129_1::sumNumbers(TreeNode *root) { return ::sumNumbers(root, 0); }
