#include "RemoveNthNodeFromEndOfList.h"

using namespace lcpp;

ListNode *Solution19_1::removeNthFromEnd(ListNode *head, int n) {
  ListNode Dummy(0, head), *Slow = &Dummy, *Fast = &Dummy;
  for (; n >= 0; --n)
    Fast = Fast->next;
  while (Fast != nullptr) {
    Slow = Slow->next;
    Fast = Fast->next;
  }
  auto Remove = Slow->next;
  Slow->next = Remove->next;
  delete Remove;
  return Dummy.next;
}
