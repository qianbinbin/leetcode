#include "MergeKSortedLists.h"
#include <queue>

using namespace lcpp;

static ListNode *mergeTwoSortedLists(ListNode *Head1, ListNode *Head2) {
  ListNode Dummy, *Tail = &Dummy;
  while (Head1 != nullptr && Head2 != nullptr) {
    if (Head1->val <= Head2->val) {
      Tail->next = Head1;
      Tail = Head1;
      Head1 = Head1->next;
    } else {
      Tail->next = Head2;
      Tail = Head2;
      Head2 = Head2->next;
    }
  }
  Tail->next = Head1 != nullptr ? Head1 : Head2;
  return Dummy.next;
}

ListNode *Solution23_1::mergeKLists(std::vector<ListNode *> &lists) {
  auto const &Size = lists.size();
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

struct Greater {
  bool operator()(ListNode *Head1, ListNode *Head2) const {
    return Head1->val > Head2->val;
  }
};

ListNode *Solution23_2::mergeKLists(std::vector<ListNode *> &lists) {
  std::priority_queue<ListNode *, std::vector<ListNode *>, Greater> Heap;
  for (auto &H : lists) {
    if (H != nullptr)
      Heap.push(H);
  }
  ListNode Dummy, *Tail = &Dummy;
  while (!Heap.empty()) {
    Tail->next = Heap.top();
    Heap.pop();
    Tail = Tail->next;
    if (Tail->next != nullptr)
      Heap.push(Tail->next);
  }
  return Dummy.next;
}
