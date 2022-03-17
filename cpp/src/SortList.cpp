#include "SortList.h"

using namespace lcpp;

static ListNode *mergeTwoSortedLists(ListNode *Head1, ListNode *Head2) {
  ListNode Dummy(0), *Tail = &Dummy;
  while (Head1 != nullptr && Head2 != nullptr) {
    if (Head1->val <= Head2->val) {
      Tail = Tail->next = Head1;
      Head1 = Head1->next;
    } else {
      Tail = Tail->next = Head2;
      Head2 = Head2->next;
    }
  }
  Tail->next = Head1 != nullptr ? Head1 : Head2;
  return Dummy.next;
}

ListNode *Solution148_1::sortList(ListNode *head) {
  if (head == nullptr || head->next == nullptr)
    return head;
  ListNode Dummy(0, head), *H1 = &Dummy, *H2 = H1;
  while (H2 != nullptr && H2->next != nullptr) {
    H1 = H1->next;
    H2 = H2->next->next;
  }
  H2 = H1->next;
  H1->next = nullptr;
  H1 = sortList(head), H2 = sortList(H2);
  return mergeTwoSortedLists(H1, H2);
}
