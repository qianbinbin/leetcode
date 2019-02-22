#include "CopyListWithRandomPointer.h"

using namespace lcpp;

RandomListNode *Solution138_1::copyRandomList(RandomListNode *head) {
  if (head == nullptr)
    return nullptr;
  RandomListNode *P, *Copy;
  for (P = head; P != nullptr; P = Copy->next) {
    Copy = new RandomListNode(P->label);
    Copy->next = P->next;
    P->next = Copy;
  }
  for (P = head; P != nullptr; P = Copy->next) {
    Copy = P->next;
    if (P->random != nullptr)
      Copy->random = P->random->next;
  }
  auto CopyHead = head->next;
  for (P = head; P != nullptr;) {
    Copy = P->next;
    P->next = Copy->next;
    P = P->next;
    if (P != nullptr)
      Copy->next = P->next;
  }
  return CopyHead;
}
