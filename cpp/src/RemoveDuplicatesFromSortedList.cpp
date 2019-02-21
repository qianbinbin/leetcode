#include "RemoveDuplicatesFromSortedList.h"

using namespace lcpp;

ListNode *Solution83_1::deleteDuplicates(ListNode *head) {
  if (head == nullptr)
    return nullptr;
  ListNode *Tail = head, *P = head->next;
  while (P != nullptr) {
    if (P->val != Tail->val) {
      Tail->next = P;
      Tail = P;
    } else {
      Tail->next = P->next;
      delete P;
    }
    P = Tail->next;
  }
  return head;
}
