#include "PartitionList.h"

using namespace lcpp;

ListNode *Solution86_1::partition(ListNode *head, int x) {
  ListNode Dummy(0), *LessTail = &Dummy, *Pre = LessTail, *P = head;
  Dummy.next = head;
  while (P != nullptr && P->val < x) {
    Pre = P;
    P = P->next;
  }
  LessTail = Pre;
  while (P != nullptr) {
    if (P->val < x) {
      Pre->next = P->next;
      P->next = LessTail->next;
      LessTail->next = P;
      LessTail = P;
    } else {
      Pre = P;
    }
    P = Pre->next;
  }
  return Dummy.next;
}
