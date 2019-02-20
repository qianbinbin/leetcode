#include "RemoveNthNodeFromEndOfList.h"
#include <cassert>

using namespace lcpp;

ListNode *Solution19_1::removeNthFromEnd(ListNode *head, int n) {
  assert(n > 0 && "n must be positive!");
  ListNode Dummy(0), *Slow = &Dummy, *Fast = &Dummy;
  Dummy.next = head;
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
