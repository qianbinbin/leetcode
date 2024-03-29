#include "ReverseNodesInKGroup.h"

using namespace lcpp;

ListNode *Solution25_1::reverseKGroup(ListNode *head, int k) {
  ListNode Dummy(0, head), *Tail = &Dummy, *First, *P, *E;
  int Count;
  while ((First = Tail->next) != nullptr) {
    E = First;
    for (Count = 0; Count != k && E != nullptr; ++Count)
      E = E->next;
    if (Count != k)
      break;
    while ((P = First->next) != E) {
      First->next = P->next;
      P->next = Tail->next;
      Tail->next = P;
    }
    Tail = First;
  }
  return Dummy.next;
}
