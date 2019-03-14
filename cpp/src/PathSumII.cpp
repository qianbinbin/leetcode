#include "PathSumII.h"

using namespace lcpp;

template<typename T> using TwoDimVec = std::vector<std::vector<T>>;

static void pathSum(TreeNode *Root, int Sum,
                    TwoDimVec<int> &Result, std::vector<int> &Path) {
  Path.push_back(Root->val);
  Sum -= Root->val;
  if (Root->left == nullptr && Root->right == nullptr) {
    if (Sum == 0)
      Result.push_back(Path);
    Path.pop_back();
    return;
  }
  if (Root->left != nullptr)
    pathSum(Root->left, Sum, Result, Path);
  if (Root->right != nullptr)
    pathSum(Root->right, Sum, Result, Path);
  Path.pop_back();
}

std::vector<std::vector<int>> Solution113_1::pathSum(TreeNode *root, int sum) {
  TwoDimVec<int> Result;
  if (root == nullptr)
    return Result;
  std::vector<int> Path;
  ::pathSum(root, sum, Result, Path);
  return Result;
}
