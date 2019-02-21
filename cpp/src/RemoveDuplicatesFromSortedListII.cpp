#include "RemoveDuplicatesFromSortedListII.h"

using namespace lcpp;

ListNode *Solution82_1::deleteDuplicates(ListNode *head) {
  ListNode Dummy(0), *Tail = &Dummy, *P = head;
  Dummy.next = head;
  int Remove;
  while (P != nullptr && P->next != nullptr) {
    if (P->val == P->next->val) {
      Remove = P->val;
      while (P != nullptr && P->val == Remove) {
        Tail->next = P->next;
        delete P;
        P = Tail->next;
      }
    } else {
      Tail->next = P;
      Tail = P;
      P = P->next;
    }
  }
  return Dummy.next;
}
