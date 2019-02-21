#include "ReverseNodesInKGroup.h"
#include <cassert>

using namespace lcpp;

ListNode *Solution25_1::reverseKGroup(ListNode *head, int k) {
  assert(k > 0 && "k must be positive!");
  ListNode Dummy(0), *Tail = &Dummy, *SegmentHead = head, *P, *E;
  Dummy.next = head;
  int Count;
  while (SegmentHead != nullptr) {
    for (Count = 1, E = SegmentHead->next; Count != k && E != nullptr;
         ++Count, E = E->next);
    if (Count != k)
      break;
    for (P = SegmentHead->next; P != E; P = SegmentHead->next) {
      SegmentHead->next = P->next;
      P->next = Tail->next;
      Tail->next = P;
    }
    Tail = SegmentHead;
    SegmentHead = E;
  }
  return Dummy.next;
}
