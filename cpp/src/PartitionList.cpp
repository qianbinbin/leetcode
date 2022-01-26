#include "PartitionList.h"

using namespace lcpp;

ListNode *Solution86_1::partition(ListNode *head, int x) {
  ListNode Dummy1, *Tail1 = &Dummy1, Dummy2, *Tail2 = &Dummy2;
  for (ListNode *p = head; p != nullptr; p = p->next) {
    if (p->val < x)
      Tail1 = (Tail1->next = p);
    else
      Tail2 = (Tail2->next = p);
  }
  Tail1->next = Dummy2.next;
  Tail2->next = nullptr;
  return Dummy1.next;
}
