#include "MergeTwoSortedLists.h"

using namespace lcpp;

ListNode *Solution21_1::mergeTwoLists(ListNode *l1, ListNode *l2) {
  ListNode Dummy, *Tail = &Dummy;
  while (l1 != nullptr && l2 != nullptr) {
    if (l1->val <= l2->val) {
      Tail->next = l1;
      Tail = l1;
      l1 = l1->next;
    } else {
      Tail->next = l2;
      Tail = l2;
      l2 = l2->next;
    }
  }
  Tail->next = l1 != nullptr ? l1 : l2;
  return Dummy.next;
}
