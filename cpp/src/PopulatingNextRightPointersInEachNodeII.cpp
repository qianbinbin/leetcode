#include "PopulatingNextRightPointersInEachNodeII.h"

using namespace lcpp;

typedef TreeLinkNode Node;

Node *Solution117_1::connect(Node *root) {
  if (root == nullptr)
    return nullptr;
  Node Dummy{}, *Tail = &Dummy, *TLNode = root;
  while (TLNode != nullptr) {
    if (TLNode->left != nullptr) {
      Tail->next = TLNode->left;
      Tail = Tail->next;
    }
    if (TLNode->right != nullptr) {
      Tail->next = TLNode->right;
      Tail = Tail->next;
    }
    if (TLNode->next != nullptr) {
      TLNode = TLNode->next;
    } else {
      TLNode = Dummy.next;
      Dummy.next = nullptr;
      Tail = &Dummy;
    }
  }
  return root;
}
