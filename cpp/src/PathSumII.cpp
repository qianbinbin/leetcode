#include "PathSumII.h"

using namespace lcpp;

template <typename T> using TwoDimVec = std::vector<std::vector<T>>;

static void pathSum(TreeNode *Root, int Target, TwoDimVec<int> &Result,
                    std::vector<int> &Path) {
  if (Root == nullptr)
    return;
  Path.push_back(Root->val);
  if (Root->left == nullptr && Root->right == nullptr && Root->val == Target)
    Result.push_back(Path);
  pathSum(Root->left, Target - Root->val, Result, Path);
  pathSum(Root->right, Target - Root->val, Result, Path);
  Path.pop_back();
}

std::vector<std::vector<int>> Solution113_1::pathSum(TreeNode *root,
                                                     int targetSum) {
  TwoDimVec<int> Result;
  std::vector<int> Path;
  ::pathSum(root, targetSum, Result, Path);
  return Result;
}
