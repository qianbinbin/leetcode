#include "TreeNode.h"
#include <queue>

using namespace lcpp;

struct TreeNode *lcpp::newTree(std::initializer_list<int> List) {
  if (List.size() == 0)
    return nullptr;
  auto I = List.begin(), E = List.end();
  auto Root = new TreeNode(*I++);
  std::queue<TreeNode *> Queue;
  Queue.push(Root);
  while (I != E && !Queue.empty()) {
    auto &Node = Queue.front();
    Queue.pop();
    if (*I != NTNode)
      Queue.push(Node->left = new TreeNode(*I));
    if (++I == E)
      break;
    if (*I != NTNode)
      Queue.push(Node->right = new TreeNode(*I));
    ++I;
  }
  return Root;
}

void lcpp::deleteTree(struct TreeNode *Root) {
  if (Root == nullptr)
    return;
  deleteTree(Root->left);
  deleteTree(Root->right);
  delete Root;
}
