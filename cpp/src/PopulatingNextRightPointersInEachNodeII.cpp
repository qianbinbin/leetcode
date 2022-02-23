#include "PopulatingNextRightPointersInEachNodeII.h"

using namespace lcpp;

Node *Solution117_1::connect(Node *root) {
  Node Dummy, *Tail, *Node = root;
  while (Node != nullptr) {
    Dummy.next = nullptr;
    Tail = &Dummy;
    while (Node != nullptr) {
      if (Node->left != nullptr)
        Tail = Tail->next = Node->left;
      if (Node->right != nullptr)
        Tail = Tail->next = Node->right;
      Node = Node->next;
    }
    Node = Dummy.next;
  }
  return root;
}
