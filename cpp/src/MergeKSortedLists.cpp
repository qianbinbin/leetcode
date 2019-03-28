#include "MergeKSortedLists.h"

using namespace lcpp;

static ListNode *mergeTwoSortedLists(ListNode *Head1, ListNode *Head2) {
  ListNode Dummy(0), *Tail = &Dummy;
  while (Head1 != nullptr && Head2 != nullptr) {
    if (Head1->val <= Head2->val) {
      Tail->next = Head1;
      Head1 = Head1->next;
    } else {
      Tail->next = Head2;
      Head2 = Head2->next;
    }
    Tail = Tail->next;
  }
  Tail->next = Head1 != nullptr ? Head1 : Head2;
  return Dummy.next;
}

ListNode *Solution23_1::mergeKLists(std::vector<ListNode *> &lists) {
  const auto &Size = lists.size();
  if (Size == 0)
    return nullptr;
  std::vector<ListNode *>::size_type Interval, Step, I;
  for (Interval = 1; Interval < Size; Interval = Step) {
    Step = Interval * 2;
    for (I = 0; I + Interval < Size; I += Step)
      lists[I] = mergeTwoSortedLists(lists[I], lists[I + Interval]);
  }
  return lists[0];
}
