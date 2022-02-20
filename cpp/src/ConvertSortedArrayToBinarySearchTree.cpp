#include "ConvertSortedArrayToBinarySearchTree.h"

using namespace lcpp;

typedef std::vector<int>::iterator It;

static TreeNode *sortedArrayToBST(It Begin, It End) {
  if (Begin == End)
    return nullptr;
  auto Mid = Begin + (End - Begin) / 2;
  return new TreeNode(*Mid, sortedArrayToBST(Begin, Mid),
                      sortedArrayToBST(Mid + 1, End));
}

TreeNode *Solution108_1::sortedArrayToBST(std::vector<int> &nums) {
  return ::sortedArrayToBST(nums.begin(), nums.end());
}
