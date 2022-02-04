#include "SymmetricTree.h"
#include <queue>

using namespace lcpp;

static bool isSymmetric(TreeNode *Root1, TreeNode *Root2) {
  if (Root1 == nullptr && Root2 == nullptr)
    return true;
  if (Root1 == nullptr || Root2 == nullptr)
    return false;
  if (Root1->val != Root2->val)
    return false;
  return isSymmetric(Root1->left, Root2->right) &&
         isSymmetric(Root1->right, Root2->left);
}

bool Solution101_1::isSymmetric(TreeNode *root) {
  return ::isSymmetric(root->left, root->right);
}

bool Solution101_2::isSymmetric(TreeNode *root) {
  std::queue<TreeNode *> Queue;
  Queue.push(root->left);
  Queue.push(root->right);
  TreeNode *Node1, *Node2;
  while (!Queue.empty()) {
    Node1 = Queue.front();
    Queue.pop();
    Node2 = Queue.front();
    Queue.pop();
    if (Node1 == nullptr && Node2 == nullptr) {
      continue;
    } else if (Node1 == nullptr || Node2 == nullptr ||
               Node1->val != Node2->val) {
      return false;
    } else {
      Queue.push(Node1->left);
      Queue.push(Node2->right);
      Queue.push(Node1->right);
      Queue.push(Node2->left);
    }
  }
  return true;
}
