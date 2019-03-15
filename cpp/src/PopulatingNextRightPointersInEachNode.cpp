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

Node *Solution116_2::connect(Node *root) {
  if (root == nullptr || root->left == nullptr)
    return root;
  root->left->next = root->right;
  if (root->next != nullptr)
    root->right->next = root->next->left;
  connect(root->left);
  connect(root->right);
  return root;
}
