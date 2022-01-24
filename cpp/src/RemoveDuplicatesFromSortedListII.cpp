#include "RemoveDuplicatesFromSortedListII.h"

using namespace lcpp;

ListNode *Solution82_1::deleteDuplicates(ListNode *head) {
  ListNode Dummy(0, head), *Tail = &Dummy, *P = head;
  int Remove;
  while (P != nullptr) {
    if (P->next != nullptr && P->val == P->next->val) {
      Remove = P->val;
      while (P != nullptr && P->val == Remove) {
        Tail->next = P->next;
        delete P;
        P = Tail->next;
      }
    } else {
      Tail = P;
      P = P->next;
    }
  }
  return Dummy.next;
}
