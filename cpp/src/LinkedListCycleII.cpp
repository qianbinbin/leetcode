#include "LinkedListCycleII.h"

using namespace lcpp;

ListNode *Solution142_1::detectCycle(ListNode *head) {
  ListNode *Slow = head, *Fast = head;
  while (Fast != nullptr && Fast->next != nullptr) {
    Slow = Slow->next;
    Fast = Fast->next->next;
    if (Slow == Fast) {
      ListNode *P = head;
      while (P != Slow) {
        P = P->next;
        Slow = Slow->next;
      }
      return P;
    }
  }
  return nullptr;
}
