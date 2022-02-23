#include "PopulatingNextRightPointersInEachNode.h"

using namespace lcpp;

Node *Solution116_1::connect(Node *root) {
  if (root == nullptr)
    return nullptr;
  Node Dummy, *Tail, *Node = root;
  while (Node->left != nullptr) {
    Tail = &Dummy;
    while (Node != nullptr) {
      Tail = Tail->next = Node->left;
      Tail = Tail->next = Node->right;
      Node = Node->next;
    }
    Node = Dummy.next;
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
