#include "LinkedListCycle.h"

using namespace lcpp;

bool Solution141_1::hasCycle(ListNode *head) {
  ListNode *Slow = head, *Fast = head;
  while (Fast != nullptr && Fast->next != nullptr) {
    Slow = Slow->next;
    Fast = Fast->next->next;
    if (Slow == Fast)
      return true;
  }
  return false;
}
