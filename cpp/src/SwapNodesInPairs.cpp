#include "SwapNodesInPairs.h"

using namespace lcpp;

ListNode *Solution24_1::swapPairs(ListNode *head) {
  ListNode Dummy(0, head), *Tail = &Dummy, *P1, *P2;
  while ((P1 = Tail->next) != nullptr && (P2 = P1->next) != nullptr) {
    P1->next = P2->next;
    P2->next = P1;
    Tail->next = P2;
    Tail = P1;
  }
  return Dummy.next;
}
