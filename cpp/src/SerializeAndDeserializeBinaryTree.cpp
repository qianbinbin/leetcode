#include "SerializeAndDeserializeBinaryTree.h"
#include <cstdint>
#include <limits>
#include <sstream>

using namespace lcpp;

static const int64_t NullValue = std::numeric_limits<int64_t>::min();

static void serialize(std::ostringstream &OSS, TreeNode *Root) {
  if (Root == nullptr) {
    OSS << NullValue << ' ';
    return;
  }
  OSS << Root->val << ' ';
  serialize(OSS, Root->left);
  serialize(OSS, Root->right);
}

std::string Codec::serialize(TreeNode *root) {
  std::ostringstream OSS;
  ::serialize(OSS, root);
  return OSS.str();
}

static TreeNode *deserialize(std::istringstream &ISS, int64_t &Value) {
  ISS >> Value;
  if (Value == NullValue)
    return nullptr;
  auto Root = new TreeNode(Value);
  Root->left = deserialize(ISS, Value);
  Root->right = deserialize(ISS, Value);
  return Root;
}

TreeNode *Codec::deserialize(std::string data) {
  std::istringstream ISS(data);
  int64_t Value;
  return ::deserialize(ISS, Value);
}
