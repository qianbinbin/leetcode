#include "PopulatingNextRightPointersInEachNode.h"

using namespace lcpp;

typedef TreeLinkNode Node;

Node *Solution116_1::connect(Node *root) {
  if (root == nullptr)
    return nullptr;
  auto Head = root;
  while (Head->left != nullptr) {
    auto TLNode = Head;
    while (TLNode != nullptr) {
      TLNode->left->next = TLNode->right;
      if (TLNode->next != nullptr)
        TLNode->right->next = TLNode->next->left;
      TLNode = TLNode->next;
    }
    Head = Head->left;
  }
  return root;
}
